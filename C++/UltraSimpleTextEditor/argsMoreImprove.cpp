#include <iostream>
#include <fstream>
#include <string.h>
void read_Flat(std::fstream& file) {
	std::string line;
	if(file.is_open()) {
		while(getline(file,line)) {
			std::cout << line << "\n";
		}
		file.close();
	}
	else
		std::cout << "Error while opening file...";
}

void read_Number(std::fstream& file) {
	std::string line;
	int counter = 1;
	if(file.is_open()) {
		while(getline(file,line)) {
			std::cout << counter << " " << line << "\n";
			counter++;
		}
		file.close();
	}
	else
		std::cout << "Error while opening file...";
}

void edit_number(std::fstream& file) {
	std::string line;
	int counter = 1;
	if(file.is_open()) {
		while(getline(file,line)) {
			std::cout << counter << " " << line << "\n";
			counter++;
		}
		file.clear();
		while(1) {
			std::cout << counter << " ";
			getline(std::cin,line);
			if(line == ":q") {
				break;
			}
			else {
				file << line << "\n";
				counter++;
			}
		}
		file.close();
	}
}
void edit_flat(std::fstream& file) {
	std::string line;
	if(file.is_open()) {
		while(getline(file,line))
			std::cout << line << '\n';
		file.clear();
		while(1) {
			getline(std::cin,line);
			if(line == ":q")
				break;
			else file << line << "\n";
		}
		file.close();
	}
}
int main(int argc, char **argv) {
	char *fileName = argv[1];
	if(fileName == NULL || (strcmp(fileName,"--help") == 0 || strcmp(fileName,"-h") == 0)) {
		puts("Enter file name as argument \n./app <filename>\n -e/--edit for edit\n -n/--number for line numbers");
		exit(EXIT_FAILURE);
	}
	std::fstream file(fileName,std::ios::in | std::ios::out | std::ios::app);
	if(argc == 3) {
		char *cmd = argv[2];
		if(strcmp(cmd,"-n") == 0 ||strcmp(cmd,"--number") == 0)
			read_Number(file);
		else if(strcmp(cmd,"-e") == 0 ||strcmp(cmd,"--edit") == 0)
			edit_flat(file);
	}
	else if(argc == 4) {
		char *cmd1 = argv[2];
		char *cmd2 = argv[3];
		if((strcmp(cmd1,"-n") == 0 && strcmp(cmd2,"-e") == 0) || (strcmp(cmd1,"-e") == 0 && strcmp(cmd2,"-n") == 0))
			edit_number(file);
		else if((strcmp(cmd1,"--edit") == 0 && strcmp(cmd2,"-n") == 0) || (strcmp(cmd1,"-n") == 0 && strcmp(cmd2,"--edit") == 0))
			edit_number(file);
		else if((strcmp(cmd1,"--number") == 0 && strcmp(cmd2,"-e") == 0) || (strcmp(cmd1,"-e") == 0 && strcmp(cmd2,"--number") == 0))
			edit_number(file);
		else if((strcmp(cmd1,"--number") == 0 && strcmp(cmd2,"--edit") == 0) || (strcmp(cmd1,"--edit") == 0 && strcmp(cmd2,"--number") == 0))
			edit_number(file);
		else read_Flat(file);
	}
	else edit_flat(file);
	return 0;
}
