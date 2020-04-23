#include <sol/sol.hpp>

struct bong {
    int a, b, c;
};

DLLEXPORT int gmod13_open(lua_State* L) {
    Lunar::Loader::Initialize();

    sol::state_view lua(L);
    lua.script("print('Hello, SOL2!')");

    lua["my_function"] = [](int a, int b, int c) { return a + b + c; };

    return 0;
}

DLLEXPORT int gmod13_close(lua_State* L) {
    (void)L;
    Lunar::Loader::Deinitialize();
    return 0;
}