#pragma once

#include <cstring>

#include "loader.hpp"
#include "luadef.hpp"

using Lunar::Loader::CallSymbol;

lua_State* lua_newstate(lua_Alloc f, void* ud) {
    return CallSymbol<lua_State*, lua_Alloc, void*>("lua_newstate", f, ud);
}

void lua_close(lua_State* L) { return CallSymbol<void, lua_State*>("lua_close", L); }

lua_State* lua_newthread(lua_State* L) {
    return CallSymbol<lua_State*, lua_State*>("lua_newthread", L);
}

lua_CFunction lua_atpanic(lua_State* L, lua_CFunction panicf) {
    return CallSymbol<lua_CFunction, lua_State*, lua_CFunction>("lua_atpanic", L, panicf);
}

int lua_gettop(lua_State* L) { return CallSymbol<int, lua_State*>("lua_gettop", L); }

void lua_settop(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_settop", L, idx);
}

void lua_pushvalue(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_pushvalue", L, idx);
}

void lua_remove(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_remove", L, idx);
}

void lua_insert(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_insert", L, idx);
}

void lua_replace(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_replace", L, idx);
}

int lua_checkstack(lua_State* L, int sz) {
    return CallSymbol<int, lua_State*, int>("lua_checkstack", L, sz);
}

void lua_xmove(lua_State* from, lua_State* to, int n) {
    return CallSymbol<void, lua_State*, lua_State*, int>("lua_xmove", from, to, n);
}

int lua_isnumber(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_isnumber", L, idx);
}

int lua_isstring(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_isstring", L, idx);
}

int lua_iscfunction(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_iscfunction", L, idx);
}

int lua_isuserdata(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_isuserdata", L, idx);
}

int lua_type(lua_State* L, int idx) { return CallSymbol<int, lua_State*, int>("lua_type", L, idx); }

const char* lua_typename(lua_State* L, int tp) {
    return CallSymbol<const char*, lua_State*, int>("lua_typename", L, tp);
}

int lua_equal(lua_State* L, int idx1, int idx2) {
    return CallSymbol<int, lua_State*, int, int>("lua_equal", L, idx1, idx2);
}

int lua_rawequal(lua_State* L, int idx1, int idx2) {
    return CallSymbol<int, lua_State*, int, int>("lua_rawequal", L, idx1, idx2);
}

int lua_lessthan(lua_State* L, int idx1, int idx2) {
    return CallSymbol<int, lua_State*, int, int>("lua_lessthan", L, idx1, idx2);
}

lua_Number lua_tonumber(lua_State* L, int idx) {
    return CallSymbol<lua_Number, lua_State*, int>("lua_tonumber", L, idx);
}

lua_Integer lua_tointeger(lua_State* L, int idx) {
    return CallSymbol<lua_Integer, lua_State*, int>("lua_tointeger", L, idx);
}

int lua_toboolean(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_toboolean", L, idx);
}

const char* lua_tolstring(lua_State* L, int idx, size_t* len) {
    return CallSymbol<const char*, lua_State*, int, size_t*>("lua_tolstring", L, idx, len);
}

size_t lua_objlen(lua_State* L, int idx) {
    return CallSymbol<size_t, lua_State*, int>("lua_objlen", L, idx);
}

lua_CFunction lua_tocfunction(lua_State* L, int idx) {
    return CallSymbol<lua_CFunction, lua_State*, int>("lua_tocfunction", L, idx);
}

void* lua_touserdata(lua_State* L, int idx) {
    return CallSymbol<void*, lua_State*, int>("lua_touserdata", L, idx);
}

lua_State* lua_tothread(lua_State* L, int idx) {
    return CallSymbol<lua_State*, lua_State*, int>("lua_tothread", L, idx);
}

const void* lua_topointer(lua_State* L, int idx) {
    return CallSymbol<const void*, lua_State*, int>("lua_topointer", L, idx);
}

void lua_pushnil(lua_State* L) { return CallSymbol<void, lua_State*>("lua_pushnil", L); }

void lua_pushnumber(lua_State* L, lua_Number n) {
    return CallSymbol<void, lua_State*, lua_Number>("lua_pushnumber", L, n);
}

void lua_pushinteger(lua_State* L, lua_Integer n) {
    return CallSymbol<void, lua_State*, lua_Integer>("lua_pushinteger", L, n);
}

void lua_pushlstring(lua_State* L, const char* s, size_t l) {
    return CallSymbol<void, lua_State*, const char*, size_t>("lua_pushlstring", L, s, l);
}

void lua_pushstring(lua_State* L, const char* s) {
    return CallSymbol<void, lua_State*, const char*>("lua_pushstring", L, s);
}

void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n) {
    return CallSymbol<void, lua_State*, lua_CFunction, int>("lua_pushcclosure", L, fn, n);
}

void lua_pushboolean(lua_State* L, int b) {
    return CallSymbol<void, lua_State*, int>("lua_pushboolean", L, b);
}

void lua_pushlightuserdata(lua_State* L, void* p) {
    return CallSymbol<void, lua_State*, void*>("lua_pushlightuserdata", L, p);
}

int lua_pushthread(lua_State* L) { return CallSymbol<int, lua_State*>("lua_pushthread", L); }

void lua_gettable(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_gettable", L, idx);
}

int lua_getfield(lua_State* L, int idx, const char* k) {
    return CallSymbol<int, lua_State*, int, const char*>("lua_getfield", L, idx, k);
}

void lua_rawget(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_rawget", L, idx);
}

void lua_rawgeti(lua_State* L, int idx, int n) {
    return CallSymbol<void, lua_State*, int, int>("lua_rawgeti", L, idx, n);
}

void lua_createtable(lua_State* L, int narr, int nrec) {
    return CallSymbol<void, lua_State*, int, int>("lua_createtable", L, narr, nrec);
}

void* lua_newuserdata(lua_State* L, size_t sz) {
    return CallSymbol<void*, lua_State*, size_t>("lua_newuserdata", L, sz);
}

int lua_getmetatable(lua_State* L, int objindex) {
    return CallSymbol<int, lua_State*, int>("lua_getmetatable", L, objindex);
}

void lua_getfenv(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_getfenv", L, idx);
}

void lua_settable(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_settable", L, idx);
}

void lua_setfield(lua_State* L, int idx, const char* k) {
    return CallSymbol<void, lua_State*, int, const char*>("lua_setfield", L, idx, k);
}

void lua_rawset(lua_State* L, int idx) {
    return CallSymbol<void, lua_State*, int>("lua_rawset", L, idx);
}

void lua_rawseti(lua_State* L, int idx, int n) {
    return CallSymbol<void, lua_State*, int, int>("lua_rawseti", L, idx, n);
}

int lua_setmetatable(lua_State* L, int objindex) {
    return CallSymbol<int, lua_State*, int>("lua_setmetatable", L, objindex);
}

int lua_setfenv(lua_State* L, int idx) {
    return CallSymbol<int, lua_State*, int>("lua_setfenv", L, idx);
}

void lua_call(lua_State* L, int nargs, int nresults) {
    return CallSymbol<void, lua_State*, int, int>("lua_call", L, nargs, nresults);
}

int lua_pcall(lua_State* L, int nargs, int nresults, int errfunc) {
    return CallSymbol<int, lua_State*, int, int, int>("lua_pcall", L, nargs, nresults, errfunc);
}

int lua_cpcall(lua_State* L, lua_CFunction func, void* ud) {
    return CallSymbol<int, lua_State*, lua_CFunction, void*>("lua_cpcall", L, func, ud);
}

int lua_load(lua_State* L, lua_Reader reader, void* dt, const char* chunkname) {
    return CallSymbol<int, lua_State*, lua_Reader, void*, const char*>("lua_load", L, reader, dt,
                                                                       chunkname);
}

int lua_load(lua_State* L, lua_Reader reader, void* dt, const char* source, const char* mode) {
    (void)mode;
    return lua_load(L, reader, dt, source); // good enough
}

int lua_dump(lua_State* L, lua_Writer writer, void* data) {
    return CallSymbol<int, lua_State*, lua_Writer, void*>("lua_dump", L, writer, data);
}

int lua_yield(lua_State* L, int nresults) {
    return CallSymbol<int, lua_State*, int>("lua_yield", L, nresults);
}

int lua_resume(lua_State* L, int narg) {
    return CallSymbol<int, lua_State*, int>("lua_resume", L, narg);
}

int lua_status(lua_State* L) { return CallSymbol<int, lua_State*>("lua_status", L); }

int lua_gc(lua_State* L, int what, int data) {
    return CallSymbol<int, lua_State*, int, int>("lua_gc", L, what, data);
}

int lua_error(lua_State* L) { return CallSymbol<int, lua_State*>("lua_error", L); }

int lua_next(lua_State* L, int idx) { return CallSymbol<int, lua_State*, int>("lua_next", L, idx); }

void lua_concat(lua_State* L, int n) {
    return CallSymbol<void, lua_State*, int>("lua_concat", L, n);
}

lua_Alloc lua_getallocf(lua_State* L, void** ud) {
    return CallSymbol<lua_Alloc, lua_State*, void*>("lua_getallocf", L, *ud);
}

void lua_setallocf(lua_State* L, lua_Alloc f, void* ud) {
    return CallSymbol<void, lua_State*, lua_Alloc, void*>("lua_setallocf", L, f, ud);
}

void lua_setlevel(lua_State* from, lua_State* to) {
    return CallSymbol<void, lua_State*, lua_State*>("lua_setlevel", from, to);
}

int lua_getstack(lua_State* L, int level, lua_Debug* ar) {
    return CallSymbol<int, lua_State*, int, lua_Debug*>("lua_getstack", L, level, ar);
}

int lua_getinfo(lua_State* L, const char* what, lua_Debug* ar) {
    return CallSymbol<int, lua_State*, const char*, lua_Debug*>("lua_getinfo", L, what, ar);
}

const char* lua_getlocal(lua_State* L, const lua_Debug* ar, int n) {
    return CallSymbol<const char*, lua_State*, const lua_Debug*, int>("lua_getlocal", L, ar, n);
}

const char* lua_setlocal(lua_State* L, const lua_Debug* ar, int n) {
    return CallSymbol<const char*, lua_State*, const lua_Debug*, int>("lua_setlocal", L, ar, n);
}

const char* lua_getupvalue(lua_State* L, int funcindex, int n) {
    return CallSymbol<const char*, lua_State*, int, int>("lua_getupvalue", L, funcindex, n);
}

const char* lua_setupvalue(lua_State* L, int funcindex, int n) {
    return CallSymbol<const char*, lua_State*, int, int>("lua_setupvalue", L, funcindex, n);
}

int lua_sethook(lua_State* L, lua_Hook func, int mask, int count) {
    return CallSymbol<int, lua_State*, lua_Hook, int, int>("lua_sethook", L, func, mask, count);
}

lua_Hook lua_gethook(lua_State* L) { return CallSymbol<lua_Hook, lua_State*>("lua_gethook", L); }

int lua_gethookmask(lua_State* L) { return CallSymbol<int, lua_State*>("lua_gethookmask", L); }

int lua_gethookcount(lua_State* L) { return CallSymbol<int, lua_State*>("lua_gethookcount", L); }

auto lua_pop(lua_State* L, int n) { return lua_settop(L, (-n) - 1); }

auto lua_newtable(lua_State* L) { return lua_createtable(L, 0, 0); }

auto lua_setglobal(lua_State* L, const char* s) { return lua_setfield(L, LUA_GLOBALSINDEX, s); }

auto lua_getglobal(lua_State* L, const char* s) { return lua_getfield(L, LUA_GLOBALSINDEX, s); }

auto lua_pushcfunction(lua_State* L, lua_CFunction f) { return lua_pushcclosure(L, f, 0); }

auto lua_register(lua_State* L, const char* n, lua_CFunction f) {
    return lua_pushcfunction(L, f), lua_setglobal(L, n);
}

auto lua_strlen(lua_State* L, int i) { return lua_objlen(L, i); }

auto lua_isfunction(lua_State* L, int i) { return lua_type(L, i) == LUA_TFUNCTION; }

auto lua_istable(lua_State* L, int i) { return lua_type(L, i) == LUA_TTABLE; }

auto lua_islightuserdata(lua_State* L, int i) { return lua_type(L, i) == LUA_TLIGHTUSERDATA; }

auto lua_isnil(lua_State* L, int i) { return lua_type(L, i) == LUA_TNIL; }

auto lua_isboolean(lua_State* L, int i) { return lua_type(L, i) == LUA_TBOOLEAN; }

auto lua_isthread(lua_State* L, int i) { return lua_type(L, i) == LUA_TTHREAD; }

auto lua_isnone(lua_State* L, int i) { return lua_type(L, i) == LUA_TNONE; }

auto lua_isnoneornil(lua_State* L, int i) { return lua_type(L, i) <= 0; }

auto lua_pushliteral(lua_State* L, const char* s) {
    return lua_pushlstring(L, s, sizeof(s) / sizeof(char) - 1);
}

auto lua_tostring(lua_State* L, int i) { return lua_tolstring(L, i, NULL); }

auto lua_getregistry(lua_State* L) { return lua_pushvalue(L, LUA_REGISTRYINDEX); }

auto lua_getgccount(lua_State* L) { return lua_gc(L, LUA_GCCOUNT, 0); }

template <typename... Args>
const char* lua_pushfstring(lua_State* L, const char* fmt, Args... args) {
    return CallSymbol<const char*, lua_State*, const char*, Args...>("lua_pushfstring", L, fmt,
                                                                     args...);
}

int luaopen_base(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_base", L); }
int luaopen_package(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_package", L); }
int luaopen_math(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_math", L); }
int luaopen_table(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_table", L); }
int luaopen_os(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_os", L); }
int luaopen_io(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_io", L); }
int luaopen_bit(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_bit", L); }
int luaopen_jit(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_jit", L); }
int luaopen_debug(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_debug", L); }
int luaopen_string(lua_State* L) { return CallSymbol<int, lua_State*>("luaopen_string", L); }

void luaI_openlib(lua_State* L, const char* libname, const luaL_Reg* l, int nup) {
    return CallSymbol<void, lua_State*, const char*, const luaL_Reg*, int>("luaI_openlib", L,
                                                                           libname, l, nup);
}

template <typename... Args> int luaL_error(lua_State* L, const char* fmt, Args... args) {
    return CallSymbol<int, lua_State*, const char*, Args...>("luaL_error", L, fmt, args...);
}

void luaL_openlibs(lua_State* L) { return CallSymbol<void, lua_State*>("luaL_openlibs", L); }

void luaL_openlib(lua_State* L) { return CallSymbol<void, lua_State*>("luaL_openlib", L); }

void luaL_register(lua_State* L, const char* libname, const luaL_Reg* l) {
    return CallSymbol<void, lua_State*, const char*, const luaL_Reg*>("luaL_register", L, libname,
                                                                      l);
}

int luaL_getmetafield(lua_State* L, int obj, const char* e) {
    return CallSymbol<int, lua_State*, int, const char*>("luaL_getmetafield", L, obj, e);
}

int luaL_callmeta(lua_State* L, int obj, const char* e) {
    return CallSymbol<int, lua_State*, int, const char*>("luaL_callmeta", L, obj, e);
}

int luaL_typerror(lua_State* L, int narg, const char* tname) {
    return CallSymbol<int, lua_State*, int, const char*>("luaL_typerror", L, narg, tname);
}

int luaL_argerror(lua_State* L, int numarg, const char* extramsg) {
    return CallSymbol<int, lua_State*, int, const char*>("luaL_argerror", L, numarg, extramsg);
}

const char* luaL_checklstring(lua_State* L, int numArg, size_t* l) {
    return CallSymbol<const char*, lua_State*, int, size_t*>("luaL_checklstring", L, numArg, l);
}

const char* luaL_optlstring(lua_State* L, int numArg, const char* def, size_t* l) {
    return CallSymbol<const char*, lua_State*, int, const char*, size_t*>("luaL_optlstring", L,
                                                                          numArg, def, l);
}

lua_Number luaL_checknumber(lua_State* L, int numArg) {
    return CallSymbol<lua_Number, lua_State*, int>("luaL_checknumber", L, numArg);
}

lua_Number luaL_optnumber(lua_State* L, int nArg, lua_Number def) {
    return CallSymbol<lua_Number, lua_State*, int, lua_Number>("luaL_optnumber", L, nArg, def);
}

lua_Integer luaL_checkinteger(lua_State* L, int numArg) {
    return CallSymbol<lua_Integer, lua_State*, int>("luaL_checkinteger", L, numArg);
}

lua_Integer luaL_optinteger(lua_State* L, int nArg, lua_Integer def) {
    return CallSymbol<lua_Integer, lua_State*, int, lua_Integer>("luaL_optinteger", L, nArg, def);
}

void luaL_checkstack(lua_State* L, int sz, const char* msg) {
    return CallSymbol<void, lua_State*, int, const char*>("luaL_checkstack", L, sz, msg);
}

void luaL_checktype(lua_State* L, int narg, int t) {
    return CallSymbol<void, lua_State*, int, int>("luaL_checktype", L, narg, t);
}

void luaL_checkany(lua_State* L, int narg) {
    return CallSymbol<void, lua_State*, int>("luaL_checkany", L, narg);
}

int luaL_newmetatable(lua_State* L, const char* tname) {
    return CallSymbol<int, lua_State*, const char*>("luaL_newmetatable", L, tname);
}

void* luaL_checkudata(lua_State* L, int ud, const char* tname) {
    return CallSymbol<void*, lua_State*, int, const char*>("luaL_checkudata", L, ud, tname);
}

void luaL_where(lua_State* L, int lvl) {
    return CallSymbol<void, lua_State*, int>("luaL_where", L, lvl);
}

int luaL_checkoption(lua_State* L, int narg, const char* def, const char* const lst[]) {
    return CallSymbol<int, lua_State*, int, const char*, const char* const[]>("luaL_checkoption", L,
                                                                              narg, def, lst);
}

int luaL_ref(lua_State* L, int t) { return CallSymbol<int, lua_State*, int>("luaL_ref", L, t); }

void luaL_unref(lua_State* L, int t, int ref) {
    return CallSymbol<void, lua_State*, int, int>("luaL_unref", L, t, ref);
}

int luaL_loadfile(lua_State* L, const char* filename) {
    return CallSymbol<int, lua_State*, const char*>("luaL_loadfile", L, filename);
}

int luaL_loadbuffer(lua_State* L, const char* buff, size_t sz, const char* name) {
    return CallSymbol<int, lua_State*, const char*, size_t, const char*>("luaL_loadbuffer", L, buff,
                                                                         sz, name);
}

int luaL_loadstring(lua_State* L, const char* s) {
    return CallSymbol<int, lua_State*, const char*>("luaL_loadstring", L, s);
}

lua_State* luaL_newstate() { return CallSymbol<lua_State*>("luaL_newstate"); }

const char* luaL_gsub(lua_State* L, const char* s, const char* p, const char* r) {
    return CallSymbol<const char*, lua_State*, const char*, const char*, const char*>("luaL_gsub",
                                                                                      L, s, p, r);
}

const char* luaL_findtable(lua_State* L, int idx, const char* fname, int szhint) {
    return CallSymbol<const char*, lua_State*, int, const char*, int>("luaL_findtable", L, idx,
                                                                      fname, szhint);
}

auto lua_open() { return luaL_newstate(); }

template <typename Cond>
auto luaL_argcheck(lua_State* L, Cond cond, int numarg, const char* extramsg) {
    return (void)(cond) || luaL_argerror(L, numarg, extramsg);
}

auto luaL_checkstring(lua_State* L, int n) { return luaL_checklstring(L, n, NULL); }

auto luaL_optstring(lua_State* L, int n, const char* d) { return luaL_optlstring(L, n, d, NULL); }

auto luaL_checkint(lua_State* L, int n) { return (int)luaL_checkinteger(L, n); }

auto luaL_optint(lua_State* L, int n, lua_Integer d) { return (int)luaL_optinteger(L, n, d); }

auto luaL_checklong(lua_State* L, int n) { return (long)luaL_checkinteger(L, n); }

auto luaL_optlong(lua_State* L, int n, lua_Integer d) { (long)luaL_optinteger(L, n, d); }

auto luaL_typename(lua_State* L, int i) { return lua_typename(L, lua_type(L, i)); }

auto luaL_dofile(lua_State* L, const char* fn) {
    return luaL_loadfile(L, fn) || lua_pcall(L, 0, LUA_MULTRET, 0);
}

auto luaL_dostring(lua_State* L, const char* s) {
    return luaL_loadstring(L, s) || lua_pcall(L, 0, LUA_MULTRET, 0);
}

auto luaL_getmetatable(lua_State* L, const char* n) {
    return lua_getfield(L, LUA_REGISTRYINDEX, n);
}

template <typename Ret> auto luaL_opt(lua_State* L, Ret (*f)(lua_State*, int), int arg, Ret def) {
    // if it compiles it works HEHEHEHE
    return lua_isnoneornil(L, arg) ? def : f(L, arg);
    // as ive understood, this checks if arg is none or nil,
    // if so it returns the default, else the result of f()
}

void luaL_traceback(lua_State* L, lua_State* L1, const char* msg, int level) {
    return CallSymbol<void, lua_State*, lua_State*, const char*, int>("luaL_traceback", L, L1, msg,
                                                                      level);
}

int luaL_fileresult(lua_State* L, int stat, const char* fname) {
    return CallSymbol<int, lua_State*, int, const char*>("luaL_filesresult", L, stat, fname);
}

int luaL_execfileresult(lua_State* L, int stat) {
    return CallSymbol<int, lua_State*, int>("luaL_execfileresult", L, stat);
}

void luaL_setmetatable(lua_State* L, const char* tname) {
    luaL_getmetatable(L, tname);
    lua_setmetatable(L, -2);
}

void* luaL_testudata(lua_State* L, int ud, const char* tname) {
    void* p = lua_touserdata(L, ud);
    if (p != NULL) {                      /* value is a userdata? */
        if (lua_getmetatable(L, ud)) {    /* does it have a metatable? */
            luaL_getmetatable(L, tname);  /* get correct metatable */
            if (!lua_rawequal(L, -1, -2)) /* not the same? */
                p = NULL;                 /* value is a userdata with wrong metatable */
            lua_pop(L, 2);                /* remove both metatables */
            return p;
        }
    }
    return NULL; /* value is not a userdata with a metatable */
}

typedef struct UBox {
    void*  box;
    size_t bsize;
} UBox;

static void* resizebox(lua_State* L, int idx, size_t newsize) {
    void*     ud;
    lua_Alloc allocf = lua_getallocf(L, &ud);
    UBox*     box    = (UBox*)lua_touserdata(L, idx);
    void*     temp   = allocf(ud, box->box, box->bsize, newsize);
    if (temp == NULL && newsize > 0) { /* allocation error? */
        resizebox(L, idx, 0);          /* free buffer */
        luaL_error(L, "not enough memory for buffer allocation");
    }
    box->box   = temp;
    box->bsize = newsize;
    return temp;
}

static int boxgc(lua_State* L) {
    resizebox(L, 1, 0);
    return 0;
}

static void* newbox(lua_State* L, size_t newsize) {
    UBox* box  = (UBox*)lua_newuserdata(L, sizeof(UBox));
    box->box   = NULL;
    box->bsize = 0;
    if (luaL_newmetatable(L, "LUABOX")) { /* creating metatable? */
        lua_pushcfunction(L, boxgc);
        lua_setfield(L, -2, "__gc"); /* metatable.__gc = boxgc */
    }
    lua_setmetatable(L, -2);
    return resizebox(L, -1, newsize);
}

static bool buffonstack(luaL_Buffer* B) { return B->b != B->initb; }

char* luaL_prepbuffsize(luaL_Buffer* B, size_t sz) {
    lua_State* L = B->L;
    if (B->size - B->n < sz) { /* not enough space? */
        char*  newbuff;
        size_t newsize = B->size * 2; /* double buffer size */
        if (newsize - B->n < sz)      /* not big enough? */
            newsize = B->n + sz;
        if (newsize < B->n || newsize - B->n < sz)
            luaL_error(L, "buffer too large");
        /* create larger buffer */
        if (buffonstack(B))
            newbuff = (char*)resizebox(L, -1, newsize);
        else { /* no buffer yet */
            newbuff = (char*)newbox(L, newsize);
            memcpy(newbuff, B->b, B->n * sizeof(char)); /* copy original content */
        }
        B->b    = newbuff;
        B->size = newsize;
    }
    return &B->b[B->n];
}

void luaL_addlstring(luaL_Buffer* B, const char* s, size_t l) {
    return CallSymbol<void, luaL_Buffer*, const char*, size_t>("luaL_addlstring", B, s, l);
}

void luaL_addstring(luaL_Buffer* B, const char* s) {
    return CallSymbol<void, luaL_Buffer*, const char*>("luaL_addstring", B, s);
}

void luaL_pushresult(luaL_Buffer* B) {
    return CallSymbol<void, luaL_Buffer*>("luaL_pushresult", B);
}

void luaL_addsize(luaL_Buffer* B, size_t s) { B->n += s; }

void luaL_pushresultsize(luaL_Buffer* B, size_t sz) {
    luaL_addsize(B, sz);
    luaL_pushresult(B);
}

void luaL_addvalue(luaL_Buffer* B) { return CallSymbol<void, luaL_Buffer*>("luaL_addvalue", B); }

void luaL_buffinit(lua_State* L, luaL_Buffer* B) {
    return CallSymbol<void, lua_State*, luaL_Buffer*>("luaL_buffinit", L, B);
}

char* luaL_buffinitsize(lua_State* L, luaL_Buffer* B, size_t sz) {
    luaL_buffinit(L, B);
    return luaL_prepbuffsize(B, sz);
}

int luaL_loadfilex(lua_State* L, const char* filename, const char* mode) {
    return CallSymbol<int, lua_State*, const char*, const char*>("luaL_loadfilex", L, filename,
                                                                 mode);
}

int luaL_loadbufferx(lua_State* L, const char* buff, size_t size, const char* name,
                     const char* mode) {
    return CallSymbol<int, lua_State*, const char*, size_t, const char*, const char*>(
        "luaL_loadbufferx", L, buff, size, name, mode);
}

void lua_len(lua_State* L, int i) {
    switch (lua_type(L, i)) {
    case LUA_TSTRING:
        lua_pushnumber(L, (lua_Number)lua_objlen(L, i));
        break;
    case LUA_TTABLE:
        if (!luaL_callmeta(L, i, "__len"))
            lua_pushnumber(L, (lua_Number)lua_objlen(L, i));
        break;
    case LUA_TUSERDATA:
        if (luaL_callmeta(L, i, "__len"))
            break;
        /* FALLTHROUGH */
    default:
        luaL_error(L, "attempt to get length of a %s value", lua_typename(L, lua_type(L, i)));
    }
}

lua_Number lua_tonumberx(lua_State* L, int i, int* isnum) {
    lua_Number n = lua_tonumber(L, i);
    if (isnum != NULL) {
        *isnum = (n != 0 || lua_isnumber(L, i));
    }
    return n;
}

lua_Integer lua_tointegerx(lua_State* L, int i, int* isnum) {
    int        ok = 0;
    lua_Number n  = lua_tonumberx(L, i, &ok);

    if (ok) {
        if (n == (lua_Integer)n) {
            if (isnum)
                *isnum = 1;
            return (lua_Integer)n;
        }
    }
    if (isnum)
        *isnum = 0;
    return 0;
}

lua_Integer luaL_len(lua_State* L, int idx) {
    lua_Integer l;
    int         isnum;
    lua_len(L, idx);

    l = lua_tointegerx(L, -1, &isnum);
    if (!isnum)
        luaL_error(L, "object length is not an integer");
    lua_pop(L, 1); /* remove object */
    return l;
}

int lua_isinteger(lua_State* L, int index) {
    if (lua_type(L, index) == LUA_TNUMBER) {
        lua_Number  n = lua_tonumber(L, index);
        lua_Integer i = lua_tointeger(L, index);
        if (i == n)
            return 1;
    }
    return 0;
}

const char* luaL_tolstring(lua_State* L, int idx, size_t* len) {
    if (luaL_callmeta(L, idx, "__tostring")) { /* metafield? */
        if (!lua_isstring(L, -1))
            luaL_error(L, "'__tostring' must return a string");
    }
    else {
        switch (lua_type(L, idx)) {
        case LUA_TNUMBER: {
            if (lua_isinteger(L, idx))
                lua_pushfstring(L, "%I", (lua_Integer)lua_tointeger(L, idx));
            else
                lua_pushfstring(L, "%f", (lua_Number)lua_tonumber(L, idx));
            break;
        }
        case LUA_TSTRING:
            lua_pushvalue(L, idx);
            break;
        case LUA_TBOOLEAN:
            lua_pushstring(L, (lua_toboolean(L, idx) ? "true" : "false"));
            break;
        case LUA_TNIL:
            lua_pushliteral(L, "nil");
            break;
        default: {
            int         tt   = luaL_getmetafield(L, idx, "__name"); /* try name */
            const char* kind = (tt == LUA_TSTRING) ? lua_tostring(L, -1) : luaL_typename(L, idx);
            lua_pushfstring(L, "%s: %p", kind, lua_topointer(L, idx));
            if (tt != LUA_TNIL)
                lua_remove(L, -2); /* remove '__name' */
            break;
        }
        }
    }
    return lua_tolstring(L, -1, len);
}

int lua_absindex(lua_State* L, int i) {
    if (i < 0 && i > LUA_REGISTRYINDEX)
        i += lua_gettop(L) + 1;
    return i;
}

int luaL_getsubtable(lua_State* L, int i, const char* name) {
    int abs_i = lua_absindex(L, i);
    luaL_checkstack(L, 3, "not enough stack slots");
    lua_pushstring(L, name);
    lua_gettable(L, abs_i);
    if (lua_istable(L, -1))
        return 1;
    lua_pop(L, 1);
    lua_newtable(L);
    lua_pushstring(L, name);
    lua_pushvalue(L, -2);
    lua_settable(L, abs_i);
    return 0;
}

void luaL_requiref(lua_State* L, const char* modname, lua_CFunction openf, int glb) {
    luaL_checkstack(L, 3, "not enough stack slots available");
    luaL_getsubtable(L, LUA_REGISTRYINDEX, "_LOADED");
    if (lua_getfield(L, -1, modname) == LUA_TNIL) {
        lua_pop(L, 1);
        lua_pushcfunction(L, openf);
        lua_pushstring(L, modname);
        lua_call(L, 1, 1);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, modname);
    }
    if (glb) {
        lua_pushvalue(L, -1);
        lua_setglobal(L, modname);
    }
    lua_replace(L, -2);
}

auto lua_setuservalue(lua_State* L, int i) { return (lua_getfenv(L, i), lua_type(L, -1)); }

auto lua_pushglobaltable(lua_State* L) { return lua_pushvalue(L, LUA_GLOBALSINDEX); }

int lua_rawgetp(lua_State* L, int i, const void* p) {
    int abs_i = lua_absindex(L, i);
    lua_pushlightuserdata(L, (void*)p);
    lua_rawget(L, abs_i);
    return lua_type(L, -1);
}

void lua_rawsetp(lua_State* L, int i, const void* p) {
    int abs_i = lua_absindex(L, i);
    luaL_checkstack(L, 1, "not enough stack slots");
    lua_pushlightuserdata(L, (void*)p);
    lua_insert(L, -2);
    lua_rawset(L, abs_i);
}

static void compat53_call_lua(lua_State* L, char const code[], size_t len, int nargs, int nret) {
    lua_rawgetp(L, LUA_REGISTRYINDEX, (void*)code);
    if (lua_type(L, -1) != LUA_TFUNCTION) {
        lua_pop(L, 1);
        if (luaL_loadbuffer(L, code, len, "=none"))
            lua_error(L);
        lua_pushvalue(L, -1);
        lua_rawsetp(L, LUA_REGISTRYINDEX, (void*)code);
    }
    lua_insert(L, -nargs - 1);
    lua_call(L, nargs, nret);
}

static const char compat53_compare_code[] = "local a,b=...\n"
                                            "return a<=b\n";

int lua_compare(lua_State* L, int idx1, int idx2, int op) {
    int result = 0;
    switch (op) {
    case LUA_OPEQ:
        return lua_equal(L, idx1, idx2);
    case LUA_OPLT:
        return lua_lessthan(L, idx1, idx2);
    case LUA_OPLE:
        luaL_checkstack(L, 5, "not enough stack slots");
        idx1 = lua_absindex(L, idx1);
        idx2 = lua_absindex(L, idx2);
        lua_pushvalue(L, idx1);
        lua_pushvalue(L, idx2);
        compat53_call_lua(L, compat53_compare_code, sizeof(compat53_compare_code) - 1, 2, 1);
        result = lua_toboolean(L, -1);
        lua_pop(L, 1);
        return result;
    default:
        luaL_error(L, "invalid 'op' argument for lua_compare");
    }
    return 0;
}

void luaL_setfuncs(lua_State* L, const luaL_Reg* l, int nup) {
    luaL_checkstack(L, nup + 1, "too many upvalues");
    for (; l->name != NULL; l++) { /* fill the table with given functions */
        int i;
        lua_pushstring(L, l->name);
        for (i = 0; i < nup; i++) /* copy upvalues to the top */
            lua_pushvalue(L, -(nup + 1));
        lua_pushcclosure(L, l->func, nup); /* closure with those upvalues */
        lua_settable(L,
                     -(nup + 3)); /* table must be below the upvalues, the name and the closure */
    }
    lua_pop(L, nup); /* remove upvalues */
}

static void compat53_reverse(lua_State* L, int a, int b) {
    for (; a < b; ++a, --b) {
        lua_pushvalue(L, a);
        lua_pushvalue(L, b);
        lua_replace(L, a);
        lua_replace(L, b);
    }
}

void lua_rotate(lua_State* L, int idx, int n) {
    int n_elems = 0;
    idx         = lua_absindex(L, idx);
    n_elems     = lua_gettop(L) - idx + 1;
    if (n < 0)
        n += n_elems;
    if (n > 0 && n < n_elems) {
        luaL_checkstack(L, 2, "not enough stack slots available");
        n = n_elems - n;
        compat53_reverse(L, idx, idx + n - 1);
        compat53_reverse(L, idx + n, idx + n_elems - 1);
        compat53_reverse(L, idx, idx + n_elems - 1);
    }
}
