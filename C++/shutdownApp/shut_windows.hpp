#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::to_string;
void shut_min(int min) {
    cout << min << " Minustes to shutdown\n";
    min = min * 60;
    string cmd = "shutdown -s -f -t " + to_string(min);
    system(cmd.c_str());
}
void shut_sec(int sec) {
    cout << sec << " Seconds to shutdown\n";
    string cmd = "shutdown -s -f -t " + to_string(sec);
    system(cmd.c_str());
}
void shut_hour(int hour) {
    cout << hour << " Hours to shutdown\n";
    hour = hour * 3600;
    string cmd = "shutdown -s -f -t " + to_string(hour);
    system(cmd.c_str());
}
void abort_shut() {
    cout << "Aborted\n";
    system("shutdown -a");
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
