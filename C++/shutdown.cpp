/* 
g++.exe shutdown.cpp -o shutdown.exe -static-libstdc++ -static -static-libgcc
*/

#include <iostream>
#include <conio.h>

using std::string;
using std::cout;
using std::cin;
using std::stoi;

int main(){
    string time; cout << "Sec: ";cin >> time;
    cout << stoi(time) / 60 << " seconds to shutdown";
    time = "shutdown -s -f -t " + time;
    system(time.c_str());
    getch();
    return 0;
}
