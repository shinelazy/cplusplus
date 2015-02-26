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
#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int a = 1;

double f(lua_State *L, double x, double y)
{
        double z;

        lua_getglobal(L, "f");
        lua_pushnumber(L, x);
        lua_pushnumber(L, y);

        if (lua_pcall(L, 2, 1, 0) != 0)
                fprintf(stderr, "call ocurs error~\n");

        if (!lua_isnumber(L, -1))
                fprintf(stderr, "must return a number~\n");

        z = lua_tonumber(L, -1);

        lua_pop(L, 1);

        printf("lua_rawgeti:%d\n", lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD)); 
        lua_State *nL = lua_tothread(L, -1);
        lua_pop(L, 1);

        printf("1-->new lua_State, ptr = %p\n", nL);

        return z;
}

int main()
{
        char buff[256];
        int err;

        lua_State *L = luaL_newstate();
 
        printf("origin lua_State, ptr = %p\n", L);

        luaL_openlibs(L);

        if (luaL_loadfile(L, "./t.lua") || lua_pcall(L, 0, 0, 0)) {
                printf("call fail\n");
                return -1;
        }
        
        f(L, 3, 5);
        f(L, 3, 5);
        f(L, 3, 5);
        f(L, 3, 5);
        f(L, 3, 5);

        printf("lua_rawgeti:%d\n", lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD)); 
        lua_State *nL = lua_tothread(L, -1);
        lua_pop(L, 1);

        printf("2-->new lua_State, ptr = %p\n", nL);


        lua_close(L);

        return 0;
} 
