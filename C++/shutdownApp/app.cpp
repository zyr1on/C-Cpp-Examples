#include <iostream>
#if __linux__
        #include "shut_linux.hpp"
    #elif _WIN32
        #include "shut_windows.hpp"
    #endif
int main() {
    run();
    return 0;
}
