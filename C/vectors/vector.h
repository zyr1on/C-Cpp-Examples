#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    size_t size;
} vector;

// vector v;
// vector_init(&v);

int vector_init(vector*v) { 
    v->data = (int*)malloc(sizeof(int)); // 4byte;
    if(v->data == NULL) {
        perror("Memory allocation error");
        return -1;
    }
    v->size = 0;
    return 0;
}
int vector_push_back(vector*v, int element) { //vector_push_back(&v,element);
    if(v->size == 0) {
        v->data[v->size] = element;
        v->size++; // 1->stack
    }
    else {
        v->data = (int*) realloc(v->data,(v->size + 1) * sizeof(int)); //resize
        if(v->data == NULL) {
            perror("Memory reallocation error:");
            return -1;
        }
        v->data[v->size] = element;
        v->size++; // 1+->stack
    }
    return 0;
}

int vector_delete(vector* v,int element) { //vector_delete(&v,element);
    int index = -1;
    for(int i=0;i<v->size;i++)
        if(v->data[i] == element)
            index = i;
    if(index != -1) {
        vector* tempVec = (vector*) malloc(sizeof(vector));
        if(tempVec == NULL) perror("Memory reallocation error");
        tempVec->data = (int*) malloc(sizeof(int)*(v->size -1));
        tempVec->size = v->size -1;
        for(int i=0;i<index;i++) {
            tempVec->data[i] = v->data[i];
        }
        for(int i=index;i<tempVec->size;i++) {
            tempVec->data[i] = v->data[i+1];
        }
        v->data = (int*) realloc(v->data,sizeof(int)*(tempVec->size));
        if(v->data == NULL) perror("Memory reallocation error");
        v->size--;
        memcpy(v->data,tempVec->data,sizeof(int) * (tempVec->size));
        free(tempVec->data);
    }
    else {
        fprintf(stderr,"Element not found\n");
        return -1;
    }
}

int vector_pop(vector* v) {
    if (v == NULL || v->size == 0) {
        return -1;
    }
    v->size--; 
    v = (int*)realloc(v->data, sizeof(int) * v->size); // Bellek boyutunu güncelle
    if (v == NULL && v->size > 0) {
        perror("Memory reallocation error");
        return -1;
    }
    return 0; // Başarılı dönüş
}
int vector_multiply(vector* v) {
    int result = 1;
    for(int i=0;i<v->size;i++) {
        result *= v->data[i];
    }
    return result;
}
int vector_sum(vector* v) {
    int sum = 0;
    for(int i=0;i<v->size;i++) {
        sum += v->data[i];
    }
    return sum;
}
float vector_avg(vector* v) {
    int sum = 0;
    for(int i=0;i<v->size;i++) {
        sum += v->data[i];
    }
    return (float) ((float)sum/(float)v->size);
}
int vector_size(vector *v) {
	return v->size;
}
int print_vector(vector*v) {
	if(v == NULL) return -1;
	if(v->size == 0) {
		puts("empty");
		return -1;
	}
    for(int i=0;i<v->size;i++) printf("%d ",v->data[i]);
    puts("");
    return 0;
}
int destroy_vector(vector*v){
    free(v->data);
    v->data = NULL;
    v->size = 0;
}

/*
	#include "vector.h"
 	vector v;
  	vector_init(&v)
	vector_push_back(&v,element);
	print_vector(&v);
 	destroy_vector(&v);

 */
