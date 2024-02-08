#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void readFile(char *fileName) {
    int counter = 1;
    FILE *file;
    file = fopen(fileName,"r");
    char string[BUFFER_SIZE];
    while(fgets(string,BUFFER_SIZE,file)) {
        printf("%d %s",counter,string);
        counter++;
    }
    fclose(file);
}

void writeFile(char *fileName)  {
    FILE *file;
    file = fopen(fileName,"w");
    char string[BUFFER_SIZE];
    int counter = 1;
    while(1) {
        printf("%d ",counter);
        fgets(string,BUFFER_SIZE,stdin);
        if(strcmp(string,":q\n") == 0) {
            break;
            exit(EXIT_SUCCESS);
        }
        fputs(string,file);
        counter++;
    }
    fclose(file);
}
void editFile(char *fileName) {
    int counter = 1;
    FILE *file;
    file = fopen(fileName,"r+");
    char string[BUFFER_SIZE];
    while(fgets(string,BUFFER_SIZE,file)) {
        printf("%d %s",counter,string);
        counter++;
    }
    while(1) {
        printf("%d ",counter);
        fgets(string,BUFFER_SIZE,stdin);
        if(strcmp(string,":q\n") == 0) {
            break;
            exit(EXIT_SUCCESS);
        }
        fputs(string,file);
        counter++;
    }
    fclose(file);
}

int fileExists(char *fileName) {
    FILE *file;
    if ((file = fopen(fileName, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    char *fileName = argv[1];
    if(fileName == NULL) {
        puts("Enter file name as argument | ./app <filename>\n");
        exit(EXIT_FAILURE);
    }
    if(fileExists(fileName)) {
        puts("File exists. Editing file. Type ':q' to exit");
        editFile(fileName);
    }
    else {
        puts("File not exists. Creating and Writing file. Type ':q' to exit.");
        writeFile(fileName);
    }
    return 0;
}
