#pragma once

#define LUA_VERSION "Lua 5.1"
#define LUA_RELEASE "Lua 5.1.5"
#define LUA_VERSION_NUM 501
#define LUA_COPYRIGHT "Copyright (C) 1994-2012 Lua.org, PUC-Rio"
#define LUA_AUTHORS "R. Ierusalimschy, L. H. de Figueiredo & W. Celes"

#define LUA_SIGNATURE "\033Lua"

#define LUA_MULTRET (-1)

#define LUA_REGISTRYINDEX (-10000)
#define LUA_ENVIRONINDEX (-10001)
#define LUA_GLOBALSINDEX (-10002)
#define lua_upvalueindex(i) (LUA_GLOBALSINDEX - (i))

#define LUA_TNONE (-1)

#define LUA_TNIL 0
#define LUA_TBOOLEAN 1
#define LUA_TLIGHTUSERDATA 2
#define LUA_TNUMBER 3
#define LUA_TSTRING 4
#define LUA_TTABLE 5
#define LUA_TFUNCTION 6
#define LUA_TUSERDATA 7
#define LUA_TTHREAD 8

#define LUA_NUMTAGS 9

#define LUA_MINSTACK 20

#define LUA_YIELD 1
#define LUA_ERRRUN 2
#define LUA_ERRSYNTAX 3
#define LUA_ERRMEM 4
#define LUA_ERRERR 5

#define LUA_GCSTOP 0
#define LUA_GCRESTART 1
#define LUA_GCCOLLECT 2
#define LUA_GCCOUNT 3
#define LUA_GCCOUNTB 4
#define LUA_GCSTEP 5
#define LUA_GCSETPAUSE 6
#define LUA_GCSETSTEPMUL 7

#define LUA_HOOKCALL 0
#define LUA_HOOKRET 1
#define LUA_HOOKLINE 2
#define LUA_HOOKCOUNT 3
#define LUA_HOOKTAILRET 4

#define LUA_MASKCALL (1 << LUA_HOOKCALL)
#define LUA_MASKRET (1 << LUA_HOOKRET)
#define LUA_MASKLINE (1 << LUA_HOOKLINE)
#define LUA_MASKCOUNT (1 << LUA_HOOKCOUNT)

#define LUA_RIDX_MAINTHREAD 1
#define LUA_RIDX_GLOBALS 2
#define LUA_RIDX_LAST LUA_RIDX_GLOBALS

#define LUA_OPADD 0
#define LUA_OPSUB 1
#define LUA_OPMUL 2
#define LUA_OPMOD 3
#define LUA_OPPOW 4
#define LUA_OPDIV 5
#define LUA_OPIDIV 6
#define LUA_OPBAND 7
#define LUA_OPBOR 8
#define LUA_OPBXOR 9
#define LUA_OPSHL 10
#define LUA_OPSHR 11
#define LUA_OPUNM 12
#define LUA_OPBNOT 13

#define LUA_OPEQ 0
#define LUA_OPLT 1
#define LUA_OPLE 2

#define LUA_GCSTOP 0
#define LUA_GCRESTART 1
#define LUA_GCCOLLECT 2
#define LUA_GCCOUNT 3
#define LUA_GCCOUNTB 4
#define LUA_GCSTEP 5
#define LUA_GCSETPAUSE 6
#define LUA_GCSETSTEPMUL 7
#define LUA_GCISRUNNING 9

#define LUA_HOOKCALL 0
#define LUA_HOOKRET 1
#define LUA_HOOKLINE 2
#define LUA_HOOKCOUNT 3
#define LUA_HOOKTAILCALL 4

#define LUA_ERRFILE (LUA_ERRERR + 1)

#define LUA_LOADED_TABLE "_LOADED"

#define LUA_PRELOAD_TABLE "_PRELOAD"

#define LUA_NOREF (-2)
#define LUA_REFNIL (-1)

#define LUA_FILEHANDLE "FILE*"

struct lua_State;
typedef double lua_Number;
typedef long   lua_Integer;

typedef const char* (*lua_Reader)(lua_State* L, void* ud, size_t* sz);
typedef int (*lua_Writer)(lua_State* L, const void* p, size_t sz, void* ud);

typedef int (*lua_CFunction)(lua_State* L);
typedef void* (*lua_Alloc)(void* ud, void* ptr, size_t osize, size_t nsize);

#define LUA_IDSIZE 60

struct lua_Debug {
    int         event;
    const char* name;
    const char* namewhat;
    const char* what;
    const char* source;
    int         currentline;
    int         nups;
    int         linedefined;
    int         lastlinedefined;
    char        short_src[LUA_IDSIZE];
    int         i_ci;
};

typedef void (*lua_Hook)(lua_State* L, lua_Debug* ar);

typedef struct luaL_Reg {
    const char*   name;
    lua_CFunction func;
} luaL_Reg;

#define LUAL_BUFFERSIZE ((int)(0x80 * sizeof(void*) * sizeof(lua_Integer)))

typedef struct luaL_Buffer {
    char*      b;
    size_t     size;
    size_t     n;
    lua_State* L;
    char       initb[LUAL_BUFFERSIZE];
} luaL_Buffer;