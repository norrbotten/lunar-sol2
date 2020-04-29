
#if defined(__unix__)
#include "loader_posix.hpp"
#elif defined(__WIN32__)
#include "loader_win.hpp"
#endif