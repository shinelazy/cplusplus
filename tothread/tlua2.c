/**
=========================================================================
 Author: findstr
 Email: findstr@sina.com
 File Name: hellolua.c
 Description: (C)  2015-01  findstr
   
 Edit History: 
   2015-01-22    File created.
=========================================================================
**/
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

//a + b
static int l_sin(lua_State *L)
{
/*
        lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
        lua_State *nL = lua_tothread(L, -1);
        lua_pop(L, 1);

        printf("main lua_State, ptr = %p\n", nL);
*/
 
        printf("coroutine %p\n", L);
        
        double a = lua_tonumber(L, 1);
        double b = lua_tonumber(L, 2);
        lua_pushnumber(L, a + b);
        return 1;
}

int main()
{
        char buff[256];
        int err;

        lua_State *L = luaL_newstate();
 
        luaL_openlibs(L);

        printf("origin lua state:%p\n", L);

        lua_pushcfunction(L, l_sin);
        lua_setglobal(L, "mysin");

        if (luaL_loadfile(L, "./a2.lua") || lua_pcall(L, 0, 0, 0)) {
                printf("call fail\n");
                return -1;
        }

        lua_close(L);

        return 0;
} 
