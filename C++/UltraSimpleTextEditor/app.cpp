#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::ofstream;
using std::cin;
using std::string;
using std::ifstream;
using std::fstream;

void EditFile(string fileName) { // reads and edits file contents
    fstream file;
    file.open(fileName);
    string line;
    int count = 1;
    if(file.is_open()) {
        while(getline(file,line)) {
            cout << count << " " << line << "\n";
            count++;
        }
        file.clear();
        bool cont = true;
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
}
void ReadFile(string fileName) { // reads file contents;
    ifstream file (fileName);
    string line;
    int count = 1;
    if(file.is_open()) {
        while(getline(file,line)) {
            cout << count << " " << line << "\n";
            count++;
        }
        file.close();
    }
}
void WriteFile(string fileName) {
    bool cont = true;
    ofstream myFile (fileName);
    string line;
    int count = 1;
    if(myFile.is_open()) {
        while(cont) {
            cout << count << " ";
            getline(cin,line);
            if(line == ":q") {
                myFile.close();
                cont = false;
            }
            else {
                myFile << line << "\n";
                count++;
            }
        }
        myFile.close();
    }
}

bool fileExists(string fileName) { // checks for if file exists
    ifstream file;
    file.open(fileName);
    if(file.good()) {
        file.close();
        return true;
    }
    else {
        file.close();
        return false;
    }
}
int main(int argc, char *argv[]) {
    char *fileName = argv[1];
    if(fileName == NULL) {
        cout << "Enter file name as argument | ./app <filename>\n";
        exit(EXIT_FAILURE);
    }
    if(fileExists(fileName)) {
        cout << "File exists. Editing file. Type ':q' to exit.\n";
        EditFile(fileName);
    }
    else {
        cout << "File not exists. Writing file. Type ':q' or 'Ctrl-C' to exit.\n";
        WriteFile(fileName);
    }
    return 0;
}

