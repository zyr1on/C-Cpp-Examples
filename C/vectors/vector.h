#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I WILL OPTIMIZE IT asap!!!

typedef struct {
    int* data;
    size_t size;
} vector;

// vector v;
// vector_init(&v);

int vector_init(vector*v) { 
    v->data = (int*)malloc(sizeof(int)); // 4byte;
    if(v->data == NULL) {
        perror("vector_init: Memory allocation error");
        return -1;
    }
    v->size = 0;
    return 0;
}
int vector_push_back(vector*v, int element) { //vector_push_back(&v,element);
    if (v == NULL) {
        fprintf(stderr, "vector_push_back: Vector is NULL\n");
        return -1;
    }
    if(v->size == 0) {
        v->data[v->size] = element;
        v->size++; // 1->stack
    }
    else {
        v->data = (int*) realloc(v->data,(v->size + 1) * sizeof(int)); //resize
        if(v->data == NULL) {
            perror("vector_push_back: Memory reallocation error:");
            return -1;
        }
        v->data[v->size] = element;
        v->size++; // 1+->stack
    }
    return 0;
}

int vector_delete(vector* v,int element) { //vector_delete(&v,element);
    if (v == NULL || v->size == 0) {
        fprintf(stderr, "vector_delete: Vector is empty or NULL\n");
        return -1;
    }
    int index = -1;
    for(int i=0;i<v->size;i++)
        if(v->data[i] == element)
            index = i;
    if(index != -1) {
        vector* tempVec = (vector*) malloc(sizeof(vector));
        if(tempVec == NULL) perror("vector_delete: Memory reallocation error");
        tempVec->data = (int*) malloc(sizeof(int)*(v->size -1));
        tempVec->size = v->size -1;
        for(int i=0;i<index;i++) {
            tempVec->data[i] = v->data[i];
        }
        for(int i=index;i<tempVec->size;i++) {
            tempVec->data[i] = v->data[i+1];
        }
        v->data = (int*) realloc(v->data,sizeof(int)*(tempVec->size));
        if(v->data == NULL) perror("vector_delete: Memory reallocation error");
        v->size--;
        memcpy(v->data,tempVec->data,sizeof(int) * (tempVec->size));
        free(tempVec->data);
        return 0;
    }
    else {
        fprintf(stderr,"vector_delete: Element not found\n");
        return -1;
    }
}
int vector_sort(vector* v) { //selection sort;
    if (v == NULL || v->size == 0) {
        fprintf(stderr, "vector_sort: Vector is empty or NULL\n");
        return -1;
    }
    int min_index;
    for(int i=0;i<v->size -1;i++) {
        min_index = i;
        for(int j=i+1;j<v->size;j++)
            if(v->data[j] < v->data[min_index]) min_index = j;
        if(min_index != i) {
            int temp = v->data[min_index];
            v->data[min_index] = v->data[i];
            v->data[i] = temp;
        }
    }
}
int vector_pop(vector* v) {
    if (v == NULL || v->size == 0) {
        fprintf(stderr, "vector_pop: Vector is empty or NULL\n");
        return -1;
    }
    if(v->size > 0) {
        v->size--;
        v->data = (int*) realloc(v->data,sizeof(int)* v->size);
        if(v->data == NULL) {
            perror("vector_pop: Memory reallocation error");
            return -1;
        }
        return 0;
    }
}

int vector_multiply(vector* v) {
     if (v == NULL || v->size == 0) {
        fprintf(stderr, "vector_multiply: Vector is empty or NULL\n");
        return -1;
    }
    int result = 1;
    for(int i=0;i<v->size;i++) {
        result *= v->data[i];
    }
    return result;
}
int vector_sum(vector* v) {
     if (v == NULL || v->size == 0) {
        fprintf(stderr, "vector_sum: Vector is empty or NULL\n");
        return -1;
    }
    int sum = 0;
    for(int i=0;i<v->size;i++) {
        sum += v->data[i];
    }
    return sum;
}

float vector_avg(vector* v) {
    if (v == NULL || v->size == 0) {
        fprintf(stderr, "vector_avg: Vector is empty or NULL\n");
        return -1;
    }
    int sum = 0;
    for(int i=0;i<v->size;i++) {
        sum += v->data[i];
    }
    return (float) ((float)sum/(float)v->size);
}

int vector_get_last_element(vector* v) {
    if (v == NULL || v->size == 0) {
        fprintf(stderr, "vector_get_last_element: Vector is empty or NULL\n");
        return -1;
    }
    if(v->size == 0) {
        return v->data[0];
    }
    else {
        return v->data[v->size-1];
    }   
}

int vector_max(vector* v) {
    if (v == NULL || v->size == 0) {
        fprintf(stderr, "Error: Vector is empty or NULL\n");
        return -1;
    }

    int max = v->data[0];
    for(int i=1;i<v->size;i++) {
        if(v->data[i] > max) {
            max = v->data[i];
        }
    }
    return max;
}
int vector_min(vector* v) {
    if (v == NULL || v->size == 0) {
        fprintf(stderr, "Error: Vector is empty or NULL\n");
        return -1;
    }
    int min = v->data[0];
    for(int i=1;i<v->size;i++) {
        if(v->data[i] < min) {
            min = v->data[i];
        }
    }
    return min;
}
int vector_size(vector *v) {
	return v->size;
}
int print_vector(vector*v) {
	if (v == NULL || v->size == 0) {
        fprintf(stderr, "Error: Vector is empty or NULL\n");
        return -1;
    }
    for(int i=0;i<v->size;i++) printf("%d ",v->data[i]);
    puts("");
    return 0;
}

int destroy_vector(vector*v){
    if (v == NULL) {
        fprintf(stderr, "destroy_vector: Vector is empty or NULL\n");
        return -1;
    }
    free(v->data);
    v->data = NULL;
    v->size = 0;
    return 0;
}
