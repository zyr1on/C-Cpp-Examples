#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    char *fileName = argv[1];
    if(fileName == NULL) {
        puts("Enter file name as argument | ./app <filename>\n");
        exit(EXIT_FAILURE);
    }
    FILE *file;
    file = fopen(fileName,"a+");
    char string[BUFFER_SIZE];
    int counter = 1;
    puts("Type ':q' to exit the program");
    while(fgets(string,BUFFER_SIZE,file)) {
        printf("%d %s",counter,string);
        counter++;
    }
    while(1) {
        printf("%d ",counter);
        fgets(string,BUFFER_SIZE,stdin);
        if(strcmp(string,":q\n") == 0)
            break;
            exit(EXIT_SUCCESS);
        fputs(string,file);
        counter++;
    }
    fclose(file);
    return 0;
}
