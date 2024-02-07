//same app but more simple, less code, less space usage, more fast
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::fstream;
using std::string;

int main(int argc, char *argv[]) {
    char *fileName = argv[1];
    if(fileName == NULL) {
        puts("Enter file name as argument | ./app <filename>\n");
        exit(EXIT_FAILURE);
    }
    fstream file (fileName,std::ios::in | std::ios::out | std::ios::app);
    string line;
    int count = 1;
    bool cont = true;
    if(file.is_open()) {
        cout << "Type ':q' to exit the program\n";
        while(getline(file,line)) {
            cout << count << " " << line << "\n";
            count++;
        }
        file.clear();
        while(cont) {
            cout << count << " ";
            getline(cin,line);
            if(line == ":q") {
                file.close();
                cont = false;
            }
            else {
                file << line << "\n";
                count++;
            }
        }
        file.close();
    }
    return 0;
}
