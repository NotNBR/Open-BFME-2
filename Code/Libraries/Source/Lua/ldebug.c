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
