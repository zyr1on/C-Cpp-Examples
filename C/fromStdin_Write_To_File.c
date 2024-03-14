#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_S 1024
int main(int argc, char *argv[]) {
    char *fileName = argv[1];
    if(fileName == NULL) {
        fprintf(stderr,"%s\n","Enter file name as argument");
        exit(EXIT_FAILURE);
    }
    FILE *file;
    file = fopen(fileName,"w");
    if(file == NULL) {
        fprintf(stderr,"%s\n","Error while opening file...");
        exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_S];
	puts("type :q or :quit to exit.");
	while(1) {
        printf("> ");
        fgets(buffer,BUFFER_S,stdin);
        if(strcmp(buffer,":quit\n") == 0 || strcmp(buffer,":q\n") == 0)
	        break;
	    fputs(buffer,file);
	    fflush(file); //clears buffer;
    }
    fclose(file);
    puts("File Closed");
}
