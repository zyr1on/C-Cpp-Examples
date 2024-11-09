/*
	AUTHOR: Semih "zyr1on" Özdemir
 	unordered dynamic array implementation of C
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

#define INITIAL_CAP 5
typedef struct {
    int* data;
    size_t size;
    size_t capacity;
    int initialized;
} vector;

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int vector_init(vector*v) {
    if(v->initialized == 1) {
        fprintf(stderr, "vector_init: Vector is already initialized\n");
        return -1;
    }
    v->data = (int*)malloc(sizeof(int)*INITIAL_CAP);
    if(v->data == NULL) {
        perror("vector_init: Memory allocation error\n");
        return -1;
    }
    v->size = 0;
    v->capacity = INITIAL_CAP;
    v->initialized = 1;
    return 0;  
}

int vector_push_back(vector*v, int element) {
    if (v->data == NULL || v->initialized != 1) {
        fprintf(stderr, "vector_push_back: Vector is NULL or not initialized\n");
        return -1;
    }
    if(v->size >= v->capacity) {
        v->capacity *=2;
        int* temp = (int*)malloc(sizeof(int) * v->capacity);
        if(temp == NULL) {
            perror("vector_push_back: Temporary Memory allocation error");
            return -1;
        }
        memcpy(temp,v->data,sizeof(int)*v->size);
        free(v->data);
        v->data = temp;
        v->data[v->size++] = element;
    }
    v->data[v->size++] = element;
    return 0;
}

int vector_push_front(vector* v,int element) {
    if (v->data == NULL || v->initialized != 1) {
        fprintf(stderr, "vector_push_front: Vector is NULL or not initialized\n");
        return -1;
    }
    if(v->size >= v->capacity) {
        v->capacity *=2;
        int* temp = (int*)malloc(sizeof(int) * v->capacity);
        if(temp == NULL) {
            perror("vector_push_back: Temporary Memory allocation error");
            return -1;
        }
        // for(int i=0;i<v->size;i++)
        //     temp[i+1] = v->data[i];
        memmove(temp+1,v->data,sizeof(int)*v->size);
        free(v->data);
        v->data = temp;
        v->data[0] = element;
    }
    else 
    {
        // for (int i = v->size; i > 0; i--)
        //     v->data[i] = v->data[i - 1];
        memmove(v->data + 1,v->data,sizeof(int) * (v->size));
        v->data[0] = element;
    }
    v->size++;
    return 0;
}

int vector_delete(vector* v,int element) { //vector_delete(&v,element);
    if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "vector_delete: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int index = -1;
    for(int i=0;i<v->size;i++)
        if(v->data[i] == element)
            index = i;
    if(index != -1) {
        int* tempData = (int*)malloc(sizeof(int)*v->capacity);
        if(tempData == NULL) fprintf(stderr,"vector_delete: Memory allocation error");
        for(int i=0;i<index;i++)
            tempData[i] = v->data[i];
        for(int i=index;i<v->size;i++)
            tempData[i] = v->data[i+1];
        free(v->data);
        v->data = tempData;
        v->size--;
        return 0;
    }
    else {
        fprintf(stderr,"vector_delete: Element not found\n");
        return -1;
    }
}

int vector_sort(vector* v) { //selection sort;
    if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "vector_sort: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    qsort(v->data,v->size,sizeof(int),compare);
    return 0;
    
}

int vector_pop(vector* v) {
    if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "vector_pop: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    if(v->size > 0) {
        v->size--;
        return v->data[v->size+1];
    }
}

int vector_multiply(vector* v) {
     if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "vector_multiply: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int result = 1;
    for(int i=0;i<v->size;i++)
        result *= v->data[i];
    return result;
}

int vector_sum(vector* v) {
     if (v->data == NULL || v->size == 0 || v->initialized != 1 ) {
        fprintf(stderr, "vector_sum: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int sum = 0;
    for(int i=0;i<v->size;i++)
        sum += v->data[i];
    return sum;
}

float vector_avg(vector* v) {
    if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "vector_avg: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int sum = 0;
    for(int i=0;i<v->size;i++) {
        sum += v->data[i];
    }
    return (float) ((float)sum/(float)v->size);
}

int vector_get_last_element(vector* v) {
    if (v->data == NULL || v->size == 0 || v->initialized != 1 ) {
        fprintf(stderr, "vector_get_last_element: Vector is empty or NULL | maybe not initialized\n");
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
    if (v->data == NULL || v->size == 0 || v->initialized != 1 ) {
        fprintf(stderr, "vector_max: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }

    int max = v->data[0];
    for(int i=1;i<v->size;i++)
        if(v->data[i] > max) 
            max = v->data[i];
    return max;
}

int vector_min(vector* v) {
    if (v->data == NULL || v->size == 0 || v->initialized != 1 ) {
        fprintf(stderr, "vector_min: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int min = v->data[0];
    for(int i=1;i<v->size;i++)
        if(v->data[i] < min)
            min = v->data[i];
    return min;
}

int vector_size(vector *v) {
	if (v->data == NULL || v->initialized != 1 ) {
        fprintf(stderr, "vector_size: Vector is NULL | maybe not initialized\n");
        return -1;
    }
    return v->size;
}

void vector_print(vector*v) {
	if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "vector_print: Vector is empty or NULL | maybe not initialized\n");
        return;
    }
    printf("[");
    for(int i=0;i<v->size-1;i++) printf("%d,",v->data[i]);
    printf("%d]\n",v->data[v->size-1]);
    return;
}

void vector_shuffle(vector* v) {
    if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "vector_shuffle: Vector is empty or NULL | maybe not initialized\n");
        return;
    }
    srand(time(0));
    for(int i=0;i<v->size;i++) {
        int randNum = rand() % v->size;
        int temp = v->data[i];
        v->data[i] = v->data[randNum];
        v->data[randNum] = temp;
    }
}

int vector_destroy(vector*v){
    if (v->data == NULL || v->initialized != 1) {
        fprintf(stderr, "vector_destroy: Vector is NULL | maybe already destroyed or not initialized\n");
        return -1;
    }
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->initialized = 0;
    return 0;
}

void vector_fill(vector* v, int fill_val) 
{
    if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "vector_fill: Vector is empty or NULL | maybe not initialized\n");
        return;
    }
    
    for(int i=0;i<v->size;i++) 
    {
        v->data[i] = fill_val;
    }
}
int vector_IndexAt(vector* v, int element) 
{
    for(int i=0;i<v->size;i++) 
    {
        if(v->data[i] == element)
            return i;
    }
    return -1;
}
