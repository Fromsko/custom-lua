/*
** $Id: lsknetlib.c $
** Standard Operating System library
** See Copyright Notice in lua.h
*/

#define lsknetlib_c
#define LUA_LIB

#include <stdlib.h>
#include "lprefix.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "cJSON.h"

static int get(lua_State *L)
{
    return 1; // 返回一个结果
}

static int post(lua_State *L)
{
    return 1; // 返回 Lua 表
}

static int delete(lua_State *L)
{
    return 1; // 返回一个结果
}

static int put(lua_State *L)
{
    return 1; // 返回 Lua 表
}

static const luaL_Reg sknetlib[] = {
    {"get", get},
    {"post", post},
    {"delete", delete},
    {"put", put},
    {NULL, NULL},
};

/* }====================================================== */

LUAMOD_API int luaopen_cjson(lua_State *L)
{
    luaL_newlib(L, sknetlib);
    return 1;
}