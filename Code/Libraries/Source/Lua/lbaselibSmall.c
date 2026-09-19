// cl: /MD /Ireference/open-bfme-1/Code/Libraries/Source/Lua
/* Lua 4.0.1 base-library bindings, second part: the six small bodies whose
   BFME1 twins fold under ICF.  Each b2 address below is claimed once; the
   game.dat luaL_reg tables prove every identity (each address is the table
   slot shown), so these are not guesses:
   base_funcs "assert"     -> 0x0074C200 (luaB_assert 63B)
   base_funcs "settag"     -> 0x0074B980 (luaB_settag 53B)
   rawset/rawsettable/
   rawsetglobal tables     -> 0x0074BAB0 (shared folded body, luaB_rawset 49B)
   rawget/rawgettable/
   rawgetglobal tables     -> 0x0074BA80 (shared folded body, luaB_rawget 41B)
   base_funcs "setglobal"  -> 0x0074B8F0 (luaB_setglobal 37B)
   base_funcs "getglobal"  -> 0x0074B920 (luaB_getglobal 32B)
   Bodies are the upstream donor verbatim (reference/open-bfme-1 lbaselib.c),
   re-declared here as globals so the row names resolve; /MD keeps the libc
   calls indirect exactly like the donor TU. */

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

int luaB_assert(lua_State *L) {
  luaL_checkany(L, 1);
  if (lua_isnil(L, 1))
    luaL_verror(L, "assertion failed!  %.90s", luaL_opt_string(L, 2, ""));
  return 0;
}

int luaB_settag(lua_State *L) {
  luaL_checktype(L, 1, LUA_TTABLE);
  lua_pushvalue(L, 1);  /* push table */
  lua_settag(L, luaL_check_int(L, 2));
  return 1;  /* return table */
}

int luaB_rawget(lua_State *L) {
  luaL_checktype(L, 1, LUA_TTABLE);
  luaL_checkany(L, 2);
  lua_rawget(L, 1);
  return 1;
}

int luaB_rawset(lua_State *L) {
  luaL_checktype(L, 1, LUA_TTABLE);
  luaL_checkany(L, 2);
  luaL_checkany(L, 3);
  lua_rawset(L, 1);
  return 1;
}

int luaB_setglobal(lua_State *L) {
  luaL_checkany(L, 2);
  lua_setglobal(L, luaL_check_string(L, 1));
  return 0;
}

int luaB_getglobal(lua_State *L) {
  lua_getglobal(L, luaL_check_string(L, 1));
  return 1;
}
