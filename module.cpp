#include <sol/sol.hpp>

#define DLLEXPORT extern "C" __attribute((visibility("default")))

DLLEXPORT int gmod13_open(lua_State* L) {
    Lunar::Loader::Initialize();

    sol::state_view lua(L);
    lua.script("print('bigbong')");

    return 0;
}

DLLEXPORT int gmod13_close(lua_State* L) {
    (void)L;
    Lunar::Loader::Deinitialize();
    return 0;
}