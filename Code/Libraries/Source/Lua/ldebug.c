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
** $Id: ldebug.c,v 1.50 2000/10/30 12:38:50 roberto Exp $
** Debug Interface
** See Copyright Notice in lua.h
**
** Trimmed to the bodies that reproduce game.dat bytes: pushpc plus
** luaG_symbexec (BFME1 0x00996790, 437B) ahead of the BFME 2 body at
** 0x0074CEF0. The only BFME 1 -> BFME 2 drift is the switch jump-table
** base (0xd968e8 vs 0xb4d048), a relocation slot the patcher fills from
** retail, so the donor compiles unchanged. luaK_opproperties is redeclared
** here TU-locally (same layout as lcode.h) to avoid pulling the llex.h /
** lparser.h chain into this translation unit.
*/

#include "ldebug.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lfunc.h"

#define VD 100

extern const struct OpProperties {
  char mode;
  unsigned char push;
  unsigned char pop;
} luaK_opproperties[];

static int pushpc (int *stack, int pc, int top, int n) {
  while (n--)
    stack[top++] = pc-1;
  return top;
}


static Instruction luaG_symbexec (const Proto *pt, int lastpc, int stackpos) {
  int stack[MAXSTACK];  /* stores last instruction that changed a stack entry */
  const Instruction *code = pt->code;
  int top = pt->numparams;
  int pc = 0;
  if (pt->is_vararg)  /* varargs? */
    top++;  /* `arg' */
  while (pc < lastpc) {
    const Instruction i = code[pc++];
    LUA_ASSERT(0 <= top && top <= pt->maxstacksize, "wrong stack");
    switch (GET_OPCODE(i)) {
      case OP_RETURN: {
        LUA_ASSERT(top >= GETARG_U(i), "wrong stack");
        top = GETARG_U(i);
        break;
      }
      case OP_TAILCALL: {
        LUA_ASSERT(top >= GETARG_A(i), "wrong stack");
        top = GETARG_B(i);
        break;
      }
      case OP_CALL: {
        int nresults = GETARG_B(i);
        if (nresults == MULT_RET) nresults = 1;
        LUA_ASSERT(top >= GETARG_A(i), "wrong stack");
        top = pushpc(stack, pc, GETARG_A(i), nresults);
        break;
      }
      case OP_PUSHNIL: {
        top = pushpc(stack, pc, top, GETARG_U(i));
        break;
      }
      case OP_POP: {
        top -= GETARG_U(i);
        break;
      }
      case OP_SETTABLE:
      case OP_SETLIST: {
        top -= GETARG_B(i);
        break;
      }
      case OP_SETMAP: {
        top -= 2*GETARG_U(i);
        break;
      }
      case OP_CONCAT: {
        top -= GETARG_U(i);
        stack[top++] = pc-1;
        break;
      }
      case OP_CLOSURE: {
        top -= GETARG_B(i);
        stack[top++] = pc-1;
        break;
      }
      case OP_JMPONT:
      case OP_JMPONF: {
        int newpc = pc + GETARG_S(i);
        /* jump is forward and do not skip `lastpc'? */
        if (pc < newpc && newpc <= lastpc) {
          stack[top-1] = pc-1;  /* value comes from `and'/`or' */
          pc = newpc;  /* do the jump */
        }
        else
          top--;  /* do not jump; pop value */
        break;
      }
      default: {
        OpCode op = GET_OPCODE(i);
        LUA_ASSERT(luaK_opproperties[op].push != VD,
                   "invalid opcode for default");
        top -= luaK_opproperties[op].pop;
        LUA_ASSERT(top >= 0, "wrong stack");
        top = pushpc(stack, pc, top, luaK_opproperties[op].push);
      }
    }
  }
  return code[stack[stackpos]];
}

/* Anchor, absent from retail: keeps the static worker out-of-line and gives
   the declare gate a TU entry to see. Only the 437B worker is claimed. */
Instruction LuaGSymbexecAnchor(const Proto *pt, int lastpc, int stackpos)
{
  return luaG_symbexec(pt, lastpc, stackpos);
}


void luaG_binerror (lua_State *L, StkId p1, int t, const char *op) {
  if (ttype(p1) == t) p1++;
  LUA_ASSERT(ttype(p1) != t, "must be an error");
  luaG_typeerror(L, p1, op);
}


void luaG_ordererror (lua_State *L, StkId top) {
  const char *t1 = luaO_typename(top-2);
  const char *t2 = luaO_typename(top-1);
  if (t1[2] == t2[2])
    luaO_verror(L, "attempt to compare two %.10s values", t1);
  else
    luaO_verror(L, "attempt to compare %.10s with %.10s", t1, t2);
}


static int isLmark (StkId o) {
  return (o && ttype(o) == LUA_TMARK && !infovalue(o)->func->isC);
}


static StkId aux_stackedfunction (lua_State *L, int level, StkId top) {
  int i;
  for (i = (top-1) - L->stack; i>=0; i--) {
    if (is_T_MARK(L->stack[i].ttype)) {
      if (level == 0)
        return L->stack+i;
      level--;
    }
  }
  return NULL;
}


static int currentpc (StkId f) {
  CallInfo *ci = infovalue(f);
  LUA_ASSERT(isLmark(f), "function has no pc");
  if (ci->pc)
    return (*ci->pc - ci->func->f.l->code) - 1;
  else
    return -1;  /* function is not active */
}


static const char *getobjname (lua_State *L, StkId obj, const char **name) {
  StkId func = aux_stackedfunction(L, 0, obj);
  if (!isLmark(func))
    return NULL;  /* not an active Lua function */
  else {
    Proto *p = infovalue(func)->func->f.l;
    int pc = currentpc(func);
    int stackpos = obj - (func+1);  /* func+1 == function base */
    Instruction i = luaG_symbexec(p, pc, stackpos);
    LUA_ASSERT(pc != -1, "function must be active");
    switch (GET_OPCODE(i)) {
      case OP_GETGLOBAL: {
        *name = p->kstr[GETARG_U(i)]->str;
        return "global";
      }
      case OP_GETLOCAL: {
        *name = luaF_getlocalname(p, GETARG_U(i)+1, pc);
        LUA_ASSERT(*name, "local must exist");
        return "local";
      }
      case OP_PUSHSELF:
      case OP_GETDOTTED: {
        *name = p->kstr[GETARG_U(i)]->str;
        return "field";
      }
      default:
        return NULL;  /* no useful name found */
    }
  }
}


int lua_getstack (lua_State *L, int level, lua_Debug *ar) {
  StkId f = aux_stackedfunction(L, level, L->top);
  if (f == NULL) return 0;  /* there is no such level */
  else {
    ar->_func = f;
    return 1;
  }
}


void luaG_typeerror (lua_State *L, StkId o, const char *op) {  const char *name;
  const char *kind = getobjname(L, o, &name);
  const char *t = luaO_typename(o);
  if (kind)
    luaO_verror(L, "attempt to %.30s %.20s `%.40s' (a %.10s value)",
                op, kind, name, t);
  else
    luaO_verror(L, "attempt to %.30s a %.10s value", op, t);
}


int luaG_getline (int *lineinfo, int pc, int refline, int *prefi) {  int refi;
  if (lineinfo == NULL || pc == -1)
    return -1;  /* no line info or function is not active */
  refi = prefi ? *prefi : 0;
  if (lineinfo[refi] < 0)
    refline += -lineinfo[refi++];
  LUA_ASSERT(lineinfo[refi] >= 0, "invalid line info");
  while (lineinfo[refi] > pc) {
    refline--;
    refi--;
    if (lineinfo[refi] < 0)
      refline -= -lineinfo[refi--];
    LUA_ASSERT(lineinfo[refi] >= 0, "invalid line info");
  }
  for (;;) {
    int nextline = refline + 1;
    int nextref = refi + 1;
    if (lineinfo[nextref] < 0)
      nextline += -lineinfo[nextref++];
    LUA_ASSERT(lineinfo[nextref] >= 0, "invalid line info");
    if (lineinfo[nextref] > pc)
      break;
    refline = nextline;
    refi = nextref;
  }
  if (prefi) *prefi = refi;
  return refline;
}
