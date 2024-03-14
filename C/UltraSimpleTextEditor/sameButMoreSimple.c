#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char* fileName = argv[1];
    if(fileName == NULL) {
        fprintf(stderr,"%s\n","Enter file name as argument | ./app <filename>");
        exit(EXIT_FAILURE);
    }
    FILE *file;
    file = fopen(fileName,"a+");
    if(file == NULL) {
        fprintf(stderr,"%s\n","Error while opening file...");
        exit(EXIT_FAILURE);
    }
    char line[BUFFER_SIZE];
    int counter = 1;
    puts("Type ':q' to exit the program");
    while(fgets(line,BUFFER_SIZE,file))
        printf("%d %s",counter++,line);
    clearerr(file);
    while(1) {
        printf("%d ",counter);
        fgets(line,BUFFER_SIZE,stdin);
        if(strcmp(line,":q\n") == 0 || strcmp(line,":quit\n") == 0 )
            break;
        fputs(line,file);
        fflush(file);
        counter++;
    }
    fclose(file);
    return 0;
}
