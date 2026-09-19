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




/* Callee declarations: pinned to retail addresses in reverse/symbols.csv
   (BFME1 byte-identity sweep). Declared here without `static' so the
   references resolve to the pinned addresses at link. */
void body (LexState *ls, int needself, int line);
void error_expected (LexState *ls, int token);
int explist1 (LexState *ls);
int funcname (LexState *ls, expdesc *v);
int listfields (LexState *ls);
void new_localvar (LexState *ls, TString *name, int n);
int recfields (LexState *ls);


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


static TString *str_checkname (LexState *ls) {
  TString *ts;
  check_condition(ls, (ls->t.token == TK_NAME), "<name> expected");
  ts = ls->t.seminfo.ts;
  next(ls);
  return ts;
}


static void new_localvarstr (LexState *ls, const char *name, int n) {
  new_localvar(ls, luaS_newfixed(ls->L, name), n);
}


static void leavebreak (FuncState *fs, Breaklabel *bl) {
  fs->bl = bl->previous;
  LUA_ASSERT(bl->stacklevel == fs->stacklevel, "wrong levels");
  luaK_patchlist(fs, bl->breaklist, luaK_getlabel(fs));
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
