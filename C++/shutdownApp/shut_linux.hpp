#include <iostream>

using std::cout;
using std::string;
using std::to_string;
using std::cin;

void shut_sec(int secs) {
    cout << secs << " Seconds to shutdown\n";
    secs = secs / 60;
    string cmd = "shutdown -P +" + to_string(secs);
    system(cmd.c_str());
}
void shut_min(int mins) {
    cout << mins << " Minutes to shutdown\n"; 
    string cmd = "shutdown -P +" + to_string(mins);
    system(cmd.c_str());
}
void shut_hour(int hours) {
    cout << hours << " Hours to shutdown\n";
    hours = hours * 60;
    string cmd = "shutdown -P +" + to_string(hours);
    system(cmd.c_str());
}
void abort_shut() {
    cout << "Aborted\n";
    system("shutdown -c");
}
void run() {
    int time,pref;
    cout << "1-Hours\n2-Mins\n3-Secs\n4-Abort scheduled shutdown\n";
    cout << "> ";cin >> pref;
    switch (pref){
    case 1:
        cout << "Time: ";cin>>time;
        shut_hour(time);
        break;
    case 2:
        cout << "Time: ";cin >> time;
        shut_min(time);
        break;
    case 3:
        cout << "Time: ";cin >> time;
        shut_sec(time);
        break;
    case 4:
        abort_shut();
        break;
    default:
        cout << "Enter number between 1-3\n";
        break;
    }
}
