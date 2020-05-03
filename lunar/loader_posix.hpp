#pragma once

#if defined(__unix__)

#include <cstdio>
#include <dlfcn.h>
#include <unordered_map>

#define DLLEXPORT extern "C" __attribute((visibility("default")))

namespace Lunar::Loader {

#ifdef LUNAR_CLIENT_MODULE
constexpr auto LUA_MODULE_PATH = "./garrysmod/bin/lua_shared.so";
#else
constexpr auto LUA_MODULE_PATH = "./garrysmod/bin/lua_shared_srv.so";
#endif

static void* handle = nullptr;

static std::unordered_map<const char*, void*> symbol_map;

static bool Initialize() {
    puts("");
    puts("[Lunar] - Initializing");
    handle = dlopen(LUA_MODULE_PATH, RTLD_LAZY | RTLD_NOLOAD);

    if (handle == nullptr) {
        puts("[Lunar] - ERROR: Could not find lua_shared");
        return true;
    }

    puts("[Lunar] - lua_shared library loaded");

    return false;
}

static void Deinitialize() {
    if (handle != nullptr) {
        dlclose(handle);
    }
}

} // namespace Lunar::Loader

#endif