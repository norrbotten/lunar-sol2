#pragma once

#ifdef __WIN32__

#include <cstdio>
#include <unordered_map>
#include <windows.h>

#define DLLEXPORT extern "C" __declspec(dllexport)

namespace Lunar::Loader {

#ifdef LUNAR_WINDOWS_x64
constexpr auto LUA_MODULE_PATH = "./bin/win64/lua_shared.dll";
#else
constexpr auto LUA_MODULE_PATH = "./bin/lua_shared.dll";
#endif

typedef int(__cdecl* MYPROC)(LPWSTR);

static HINSTANCE handle;

static std::unordered_map<const char*, MYPROC> symbol_map;

static bool Initialize() {
    puts("");
    puts("[Lunar] - Initializing");
    handle = LoadLibrary(TEXT(LUA_MODULE_PATH));

    if (handle == NULL) {
        puts("[Lunar] - ERROR: Could not find lua_shared");
        return true;
    }

    puts("[Lunar] - lua_shared library loaded");

    return false;
}

static void Deinitialize() {
    if (handle != NULL) {
        FreeLibrary(handle);
    }
}

template <typename Ret, typename... Args>
auto CallSymbol = [](const char* name, Args... args) -> Ret {
    MYPROC symbol = (MYPROC)GetProcAddress(handle, name);
    symbol(args...);
};

} // namespace Lunar::Loader

#endif
