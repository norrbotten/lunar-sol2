
#if defined(__unix__)
#include "loader_posix.hpp"
#elif defined(__WIN32__)
#include "loader_win.hpp"
#endif

namespace Lunar::Loader {

template <typename Ret, typename... Args>
auto CallSymbol = [](const char* name, Args... args) -> Ret {
    Ret (*symbol)(Args...);

    if (symbol_map.find(name) != symbol_map.end()) {
        *(void**)(&symbol) = symbol_map[name];
    }
    else {
        auto* raw_symbol = dlsym(handle, name);
        symbol_map[name] = raw_symbol;

        *(void**)(&symbol) = raw_symbol;
    }

    return symbol(args...);
};

}