/*  g++ shut.cpp -o shut.exe -static-libstdc++ -static -static-libgcc
    'if output file is shutdown.exe it won't work, idk why :)'
*/
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
