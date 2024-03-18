#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char**data;
    size_t size;
} vector_s;

int vector_init_s(vector_s* v) {
    v->data = (char **) malloc(sizeof(char*) * 2);
    if(v->data == NULL) return -1;
    v->size = 0;
    return 0;
}
int vector_push_back_s(vector_s* v,char* string) {
    v->data[v->size] = (char*) malloc(sizeof(char) * strlen(string));
    strcpy(v->data[v->size],string);
    v->size++;
}
int vector_size_s(vector_s* v) {
	return v->size;
}
int show_vector_s(vector_s* v) {
	if(v == NULL) return -1;
	if(v->size == 0) {
		puts("empty");
		return -1;
	}
    for(int i=0;i<v->size;i++) {
         if(i != v->size -1)
            printf("%s\n",v->data[i]);
        else 
            printf("%s ",v->data[i]);
    }
    puts("");
    return 0;
}
int free_vector_s(vector_s* v){
    free(v->data);
}
