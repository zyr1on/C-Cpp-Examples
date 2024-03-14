#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_S 1024

int main(int argc, char *argv[]) {
        char *fileName = argv[1];
        if(fileName == NULL) {
                puts("Enter file name as argument");
                exit(EXIT_FAILURE);
        }
        FILE *file;
        file = fopen(fileName,"w");
        if(file == NULL) {
                puts("Error while opening file...");
                exit(EXIT_FAILURE);
        }
        bool cont = true;
        char buffer[BUFFER_S];
		puts("type :q or :quit to exit.");
		while(cont) {
                printf("> ");
                fgets(buffer,BUFFER_S,stdin);
                if(strcmp(buffer,":quit\n") == 0 || strcmp(buffer,":q\n") == 0) {
						fclose(file);
						break;
						/* exit(EXIT_SUCCESS); */
				}
				fputs(buffer,file);
        }
        /* fclose(file); */
}

