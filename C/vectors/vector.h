#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL_CAP 5
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
} // for qsort!


typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} vector;

// vector v;
// vector_init(&v);
// vector_destroy(&v);

int v_initialized = 0;
void vector_init(vector*v) {
    if(v_initialized == 1) {
        fprintf(stderr, "vector_init: Vector is already initialized\n");
        return;
    }
    else {
        v->data = (int*)malloc(sizeof(int)*INITIAL_CAP); // 4byte;
        if(v->data == NULL) {
            perror("vector_init: Memory allocation error\n");
            return;
        }
        v->size = 0;
        v->capacity = INITIAL_CAP;
        v_initialized = 1;
        return;
    }  
}

int vector_push_back(vector*v, int element) { //vector_push_back(&v,element);
    if (v->data == NULL) {
        fprintf(stderr, "vector_push_back: Vector is NULL\n");
        return -1;
    }
    if(v->size < v->capacity) {
        v->data[v->size++] = element;
    }else {
        v->capacity *=2;
        int* temp = (int*)malloc(sizeof(int) * v->capacity);
        if(temp == NULL) {
            perror("vector_push_back: Memory reallocation error");
            return -1;
        }
        for(int i=0;i<v->size;i++) {
            temp[i] = v->data[i];
        }
        free(v->data);
        v->data = temp;
        v->data[v->size++] = element;
    }
    return 0;
}
int vector_push_front(vector* v,int element) {
    if (v->data == NULL) {
        fprintf(stderr, "vector_push_front: Vector is NULL\n");
        return -1;
    }
    if(v->size < v->capacity) {
        for(int i=v->size;i>0;i--)
            v->data[i] = v->data[i-1];
        v->data[0] = element;
        v->size++;
    }
    else {
        v->capacity *=2;
        int* temp = (int*)malloc(sizeof(int) * v->capacity);
        if(temp == NULL) {
            perror("vector_push_back: Memory reallocation error");
            return -1;
        }
        for(int i=0;i<v->size;i++)
            temp[i+1] = v->data[i];
        free(v->data);
        v->data = temp;
        v->data[0] = element;
    }
    
}
int vector_delete(vector* v,int element) { //vector_delete(&v,element);
    if (v->data == NULL || v->size == 0) {
        fprintf(stderr, "vector_delete: Vector is empty or NULL\n");
        return -1;
    }
    int index = -1;
    for(int i=0;i<v->size;i++)
        if(v->data[i] == element)
            index = i;
    if(index != -1) {
        int* tempData = (int*)malloc(sizeof(int)*v->capacity);
        if(tempData == NULL) perror("vector_delete: Memory reallocation error");
        for(int i=0;i<index;i++) {
            tempData[i] = v->data[i];
        }
        for(int i=index;i<v->size;i++) {
            tempData[i] = v->data[i+1];
        }
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
    if (v->data == NULL || v->size == 0) {
        fprintf(stderr, "vector_sort: Vector is empty or NULL\n");
        return -1;
    }
    qsort(v->data,v->size,sizeof(int),compare);
    return 0;
    
}
int vector_pop(vector* v) {
    if (v->data == NULL || v->size == 0) {
        fprintf(stderr, "vector_pop: Vector is empty or NULL\n");
        return -1;
    }
    if(v->size > 0) {
        v->size--;
        return v->data[v->size+1];
    }
}

int vector_multiply(vector* v) {
     if (v->data == NULL || v->size == 0) {
        fprintf(stderr, "vector_multiply: Vector is empty or NULL\n");
        return -1;
    }
    int result = 1;
    for(int i=0;i<v->size;i++)
        result *= v->data[i];
    return result;
}
int vector_sum(vector* v) {
     if (v->data == NULL || v->size == 0) {
        fprintf(stderr, "vector_sum: Vector is empty or NULL\n");
        return -1;
    }
    int sum = 0;
    for(int i=0;i<v->size;i++)
        sum += v->data[i];
    return sum;
}

float vector_avg(vector* v) {
    if (v->data == NULL || v->size == 0) {
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
    if (v->data == NULL || v->size == 0) {
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
    if (v->data == NULL || v->size == 0) {
        fprintf(stderr, "Error: Vector is empty or NULL\n");
        return -1;
    }

    int max = v->data[0];
    for(int i=1;i<v->size;i++)
        if(v->data[i] > max) 
            max = v->data[i];
    return max;
}
int vector_min(vector* v) {
    if (v->data == NULL || v->size == 0) {
        fprintf(stderr, "Error: Vector is empty or NULL\n");
        return -1;
    }
    int min = v->data[0];
    for(int i=1;i<v->size;i++)
        if(v->data[i] < min)
            min = v->data[i];
    return min;
}
int vector_size(vector *v) {
	return v->size;
}
int vector_print(vector*v) {
	if (v->data == NULL || v->size == 0) {
        fprintf(stderr, "Error: Vector is empty or NULL\n");
        return -1;
    }
    printf("[");
    for(int i=0;i<v->size-1;i++) printf("%d,",v->data[i]);
    printf("%d]",v->data[v->size-1]);
    puts("");
    return 0;
}


void vector_shuffle(vector* vec) {
    srand(time(0));
    for(int i=0;i<vec->size;i++) {
        int randNum = rand() % vec->size;
        int temp = vec->data[i];
        vec->data[i] = vec->data[randNum];
        vec->data[randNum] = temp;
    }
}

int vector_destroy(vector*v){
    if (v->data == NULL) {
        fprintf(stderr, "vector_destroy: Vector is NULL maybe already destroyed\n");
        return -1;
    }
    free(v->data);
    v->data = NULL;
    v->size = 0;
    return 0;
}
