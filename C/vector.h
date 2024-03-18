#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int* data;
    size_t size;
} vector;
//init vector for ints,floats and chars
int vector_init(vector*v) {
    v->data = malloc(sizeof(int)); // 4byte;
    if(!v->data) return -1;
    v->size = 0;
    return 0;
}
int vector_push_back(vector*v, int element) {
    if(v->size == 0) {
        v->data[v->size] = element;
        v->size++; // 1->stack
    }
    else {
        v->data = realloc(v->data,(v->size + 1) * sizeof(int)); //resize
        v->data[v->size] = element;
        v->size++; // 1+->stack
    }
    return 0;
}
int vector_size(vector *v) {
	return v->size;
}
int show_vector(vector*v) {
	if(v == NULL) return -1;
	if(v->size == 0) {
		puts("empty");
		return -1;
	}
    for(int i=0;i<v->size;i++) printf("%d ",v->data[i]);
    puts("");
    return 0;
}
int free_vector(vector*v){
    free(v->data);
}

/*
	#include "vector.h"
 	vector_init(vector*)
	vector_push_back(&vector,element);
	show_vector(&vector);
	free_vector(vector*) 
 */
