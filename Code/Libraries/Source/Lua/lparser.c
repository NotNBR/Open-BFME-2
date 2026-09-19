// Open-BFME recovery lane: Lua parser sweep (phase 1: caller-clean bodies)
// cl: /MD /Ireference/open-bfme-1/Code/Libraries/Source/Lua
/* Lua 4.0.1 (TeCGraf, PUC-Rio), lua.org lua-4.0.1.tar.gz, flattened from
   src/, src/lib/, src/luac/ and include/.  Statically linked into
   lotrbfme.exe behind GameLogic/ScriptEngine/LuaScriptEngine.cpp.
   ALTERED SOURCE VERSION: upstream plus a reconstruction of EA's own changes
   to the language (a boolean type tag, OP_PUSHBOOL, an extra luaH_new
   argument).  PROVENANCE.txt lists every file that differs from upstream and
   how; a file absent from that list is upstream byte-for-byte apart from this
   header.  Saying so is a condition of the licence at lua.h:215, not a
   courtesy.
   Retail linked the DLL CRT, so libc calls are __imp__ indirect calls --
   /MD is what makes those call sites byte-exact. */
/*
** $Id: lparser.c,v 1.117 2000/11/29 11:57:42 roberto Exp $
** LL(1) Parser and code generator for Lua
** See Copyright Notice in lua.h
*/


#include <stdio.h>
#include <string.h>

#include "lua.h"

#include "lcode.h"
#include "lfunc.h"
#include "llex.h"
#include "lmem.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lparser.h"
#include "lstate.h"
#include "lstring.h"


/*
** Constructors descriptor:
** `n' indicates number of elements, and `k' signals whether
** it is a list constructor (k = 0) or a record constructor (k = 1)
** or empty (k = ';' or '}')
*/
typedef struct Constdesc {
  int n;
  int k;
} Constdesc;


typedef struct Breaklabel {
  struct Breaklabel *previous;  /* chain */
  int breaklist;
  int stacklevel;
} Breaklabel;




/* Callee declarations: cross-TU refs resolve via landed rows, sweep pins in
   reverse/symbols.csv, or remain unresolved in the object (the build never
   links; it byte-compares per-symbol with relocations masked). Same-TU
   statics that retail's bodies call are DEFINED below instead: MSVC uses
   TU-private conventions for statics, so an extern declaration would emit a
   standard call site where retail has a private one. */
BinOpr subexpr (LexState *ls, expdesc *v, int limit);
void open_func (LexState *ls, FuncState *fs);
void adjustlocalvars (LexState *ls, int nvars);
void parlist (LexState *ls);
void chunk (LexState *ls);
void close_func (LexState *ls);
void pushclosure (LexState *ls, FuncState *func);


/* Forward declaration: `checkname' (below) calls back into it. */
static TString *str_checkname (LexState *ls);
/* Forward declarations: `recfield'/'recfields'/'listfields' call into these. */
static void exp1 (LexState *ls);
static void expr (LexState *ls, expdesc *v);


/* `next' is ICF-ambiguous in BFME1 (name is this sweep's guess), so it is
   emitted here without claiming the name; the marker keeps the
   find_declared_unmatched gate honest. */
// _next present-unmatched
static void next (LexState *ls) {
  ls->lastline = ls->linenumber;
  if (ls->lookahead.token != TK_EOS) {  /* is there a look-ahead token? */
    ls->t = ls->lookahead;  /* use this one */
    ls->lookahead.token = TK_EOS;  /* and discharge it */
  }
  else
    ls->t.token = luaX_lex(ls, &ls->t.seminfo);  /* read next token */
}


static void lookahead (LexState *ls) {
  LUA_ASSERT(ls->lookahead.token == TK_EOS, "two look-aheads");
  ls->lookahead.token = luaX_lex(ls, &ls->lookahead.seminfo);
}


static void error_expected (LexState *ls, int token) {
  char buff[100], t[TOKEN_LEN];
  luaX_token2str(token, t);
  sprintf(buff, "`%.20s' expected", t);
  luaK_error(ls, buff);
}


static void check (LexState *ls, int c) {
  if (ls->t.token != c)
    error_expected(ls, c);
  next(ls);
}


static void check_condition (LexState *ls, int c, const char *msg) {
  if (!c) luaK_error(ls, msg);
}


static void check_match (LexState *ls, int what, int who, int where) {
  if (ls->t.token != what) {
    if (where == ls->linenumber)
      error_expected(ls, what);
    else {
      char buff[100];
      char t_what[TOKEN_LEN], t_who[TOKEN_LEN];
      luaX_token2str(what, t_what);
      luaX_token2str(who, t_who);
      sprintf(buff, "`%.20s' expected (to close `%.20s' at line %d)",
              t_what, t_who, where);
      luaK_error(ls, buff);
    }
  }
  next(ls);
}


// _string_constant present-unmatched
static int string_constant (FuncState *fs, TString *s) {
  Proto *f = fs->f;
  int c = s->u.s.constindex;
  if (c >= f->nkstr || f->kstr[c] != s) {
    luaM_growvector(fs->L, f->kstr, f->nkstr, 1, TString *,
                    "constant table overflow", MAXARG_U);
    c = f->nkstr++;
    f->kstr[c] = s;
    s->u.s.constindex = c;  /* hint for next time */
  }
  return c;
}


// _checkname present-unmatched
static int checkname (LexState *ls) {
  return string_constant(ls->fs, str_checkname(ls));
}


static TString *str_checkname (LexState *ls) {  TString *ts;
  check_condition(ls, (ls->t.token == TK_NAME), "<name> expected");
  ts = ls->t.seminfo.ts;
  next(ls);
  return ts;
}


// _luaI_registerlocalvar present-unmatched
static int luaI_registerlocalvar (LexState *ls, TString *varname) {
  Proto *f = ls->fs->f;
  luaM_growvector(ls->L, f->locvars, f->nlocvars, 1, LocVar, "", MAX_INT);
  f->locvars[f->nlocvars].varname = varname;
  return f->nlocvars++;
}


/* `error_expected' and `new_localvar' are defined for retail's inline
   context but unrowed here; the markers keep the unmatched-def gate honest. */
// _error_expected present-unmatched
static void new_localvar (LexState *ls, TString *name, int n) {
  FuncState *fs = ls->fs;
  luaX_checklimit(ls, fs->nactloc+n+1, MAXLOCALS, "local variables");
  fs->actloc[fs->nactloc+n] = luaI_registerlocalvar(ls, name);
}


static void new_localvarstr (LexState *ls, const char *name, int n) {
  new_localvar(ls, luaS_newfixed(ls->L, name), n);
}


static void leavebreak (FuncState *fs, Breaklabel *bl) {
  fs->bl = bl->previous;
  LUA_ASSERT(bl->stacklevel == fs->stacklevel, "wrong levels");
  luaK_patchlist(fs, bl->breaklist, luaK_getlabel(fs));
}


// _recfield present-unmatched
static void recfield (LexState *ls) {
  /* recfield -> (NAME | '['exp1']') = exp1 */
  switch (ls->t.token) {
    case TK_NAME: {
      luaK_kstr(ls, checkname(ls));
      break;
    }
    case '[': {
      next(ls);
      exp1(ls);
      check(ls, ']');
      break;
    }
    default: luaK_error(ls, "<name> or `[' expected");
  }
  check(ls, '=');
  exp1(ls);
}


// _recfields present-unmatched
static int recfields (LexState *ls) {
  /* recfields -> recfield { ',' recfield } [','] */
  FuncState *fs = ls->fs;
  int n = 1;  /* at least one element */
  recfield(ls);
  while (ls->t.token == ',') {
    next(ls);
    if (ls->t.token == ';' || ls->t.token == '}')
      break;
    recfield(ls);
    n++;
    if (n%RFIELDS_PER_FLUSH == 0)
      luaK_code1(fs, OP_SETMAP, RFIELDS_PER_FLUSH);
  }
  luaK_code1(fs, OP_SETMAP, n%RFIELDS_PER_FLUSH);
  return n;
}


// _listfields present-unmatched
static int listfields (LexState *ls) {
  /* listfields -> exp1 { ',' exp1 } [','] */
  FuncState *fs = ls->fs;
  int n = 1;  /* at least one element */
  exp1(ls);
  while (ls->t.token == ',') {
    next(ls);
    if (ls->t.token == ';' || ls->t.token == '}')
      break;
    exp1(ls);
    n++;
    luaX_checklimit(ls, n/LFIELDS_PER_FLUSH, MAXARG_A,
               "`item groups' in a list initializer");
    if (n%LFIELDS_PER_FLUSH == 0)
      luaK_code2(fs, OP_SETLIST, n/LFIELDS_PER_FLUSH - 1, LFIELDS_PER_FLUSH);
  }
  luaK_code2(fs, OP_SETLIST, n/LFIELDS_PER_FLUSH, n%LFIELDS_PER_FLUSH);
  return n;
}


static void constructor_part (LexState *ls, Constdesc *cd) {
  switch (ls->t.token) {
    case ';': case '}': {  /* constructor_part -> empty */
      cd->n = 0;
      cd->k = ls->t.token;
      break;
    }
    case TK_NAME: {  /* may be listfields or recfields */
      lookahead(ls);
      if (ls->lookahead.token != '=')  /* expression? */
        goto case_default;
      /* else go through to recfields */
    }
    case '[': {  /* constructor_part -> recfields */
      cd->n = recfields(ls);
      cd->k = 1;  /* record */
      break;
    }
    default: {  /* constructor_part -> listfields */
    case_default:
      cd->n = listfields(ls);
      cd->k = 0;  /* list */
      break;
    }
  }
}


// _search_local present-unmatched
static int search_local (LexState *ls, TString *n, expdesc *var) {
  FuncState *fs;
  int level = 0;
  for (fs=ls->fs; fs; fs=fs->prev) {
    int i;
    for (i=fs->nactloc-1; i >= 0; i--) {
      if (n == fs->f->locvars[fs->actloc[i]].varname) {
        var->k = VLOCAL;
        var->u.index = i;
        return level;
      }
    }
    level++;  /* `var' not found; check outer level */
  }
  var->k = VGLOBAL;  /* not found in any level; must be global */
  return -1;
}


// _singlevar present-unmatched
static void singlevar (LexState *ls, TString *n, expdesc *var) {
  int level = search_local(ls, n, var);
  if (level >= 1)  /* neither local (0) nor global (-1)? */
    luaX_syntaxerror(ls, "cannot access a variable in outer scope", n->str);
  else if (level == -1)  /* global? */
    var->u.index = string_constant(ls->fs, n);
}


// _funcname present-unmatched
static int funcname (LexState *ls, expdesc *v) {
  /* funcname -> NAME [':' NAME | '.' NAME] */
  int needself = 0;
  singlevar(ls, str_checkname(ls), v);
  if (ls->t.token == ':' || ls->t.token == '.') {
    needself = (ls->t.token == ':');
    next(ls);
    luaK_tostack(ls, v, 1);
    luaK_kstr(ls, checkname(ls));
    v->k = VINDEXED;
  }
  return needself;
}


// _body present-unmatched
static void body (LexState *ls, int needself, int line) {
  /* body ->  '(' parlist ')' chunk END */
  FuncState new_fs;
  open_func(ls, &new_fs);
  new_fs.f->lineDefined = line;
  check(ls, '(');
  if (needself) {
    new_localvarstr(ls, "self", 0);
    adjustlocalvars(ls, 1);
  }
  parlist(ls);
  check(ls, ')');
  chunk(ls);
  check_match(ls, TK_END, TK_FUNCTION, line);
  close_func(ls);
  pushclosure(ls, &new_fs);
}


// _explist1 present-unmatched
static int explist1 (LexState *ls) {
  /* explist1 -> expr { ',' expr } */
  int n = 1;  /* at least one expression */
  expdesc v;
  expr(ls, &v);
  while (ls->t.token == ',') {
    luaK_tostack(ls, &v, 1);  /* gets only 1 value from previous expression */
    next(ls);  /* skip comma */
    expr(ls, &v);
    n++;
  }
  luaK_tostack(ls, &v, 0);  /* keep open number of values of last expression */
  return n;
}


// _expr present-unmatched
static void expr (LexState *ls, expdesc *v) {
  subexpr(ls, v, -1);
}


// _exp1 present-unmatched
static void exp1 (LexState *ls) {
  expdesc v;
  expr(ls, &v);
  luaK_tostack(ls, &v, 1);
}


static int block_follow (int token) {
  switch (token) {
    case TK_ELSE: case TK_ELSEIF: case TK_END:
    case TK_UNTIL: case TK_EOS:
      return 1;
    default: return 0;
  }
}


static void funcstat (LexState *ls, int line) {
  /* funcstat -> FUNCTION funcname body */
  int needself;
  expdesc v;
  next(ls);  /* skip FUNCTION */
  needself = funcname(ls, &v);
  body(ls, needself, line);
  luaK_storevar(ls, &v);
}


static void retstat (LexState *ls) {
  /* stat -> RETURN explist */
  FuncState *fs = ls->fs;
  next(ls);  /* skip RETURN */
  if (!block_follow(ls->t.token) && ls->t.token != ';')
    explist1(ls);  /* optional return values */
  luaK_code1(fs, OP_RETURN, ls->fs->nactloc);
  fs->stacklevel = fs->nactloc;  /* removes all temp values */
}


/* Anchor, absent from retail: keeps the static workers out-of-line so the
   verifier can see them. Only the 11 rowed bodies are claimed. */
void LuaParserAnchor (LexState *ls, FuncState *fs, Breaklabel *bl, Constdesc *cd) {
  lookahead(ls);
  check(ls, 0);
  check_condition(ls, 0, 0);
  check_match(ls, 0, 0, 0);
  str_checkname(ls);
  new_localvarstr(ls, 0, 0);
  leavebreak(fs, bl);
  constructor_part(ls, cd);
  block_follow(0);
  funcstat(ls, 0);
  retstat(ls);
  next(ls);
}
