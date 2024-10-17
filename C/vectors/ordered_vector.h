/*
	AUTHOR: Semih "zyr1on" Özdemir
 	ordered dynamic array implementation of C
*/
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAP 5
typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} u_vector;

int v_initialized = 0;
void vector_init(u_vector*v) {
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

int u_vector_push_back(u_vector*v,int element) 
{
	if (v->data == NULL || v_initialized == 0) 
	{
        fprintf(stderr, "vector_push_back: Vector is NULL or not initialized\n");
        return -1;
    }
	if(v->size==0) 
	{
		v->data[v->size++] = element;
		return 0;
	}
	if(v->size==1)
	{
		if(element > v->data[0]) 
		{
			v->data[v->size++] = element;
			return 0;
		}
		else 
		{
			int temp = v->data[0];
			v->data[0] = element;
			v->data[1] = temp;
			v->size++;
		}
		return 0;
	}
	if(v->size >= v->capacity) 
	{
		v->capacity *= 2;
		int* temp = (int*)malloc(sizeof(int) * v->capacity);
		if(temp == NULL) 
		{
        	perror("vector_push_back: Temporary Memory allocation error");
			return -1;
        }
		int checked_index = 0;
		for(int i=0;i<v->size;i++) 
		{
			if(element >= v->data[i]) 
				checked_index++;
			else 
			{
				for(int k=0;k<checked_index;k++) 
					temp[k] = v->data[k];
				temp[checked_index] = element;
				for(int k=checked_index;k<v->size;k++) 
					temp[k+1] = v->data[k];
			}
			v->size++;
			free(v->data);
			v->data = temp;
			break;
		}
	}
	else 
	{
		int checked_index = 0;
		for(int i=0;i<v->size;i++) 
		{
			if(element > v->data[i]) 
				checked_index++;
			else 
			{
				for(int k=v->size;k>checked_index;k--)
					v->data[k] = v->data[k-1];
				v->data[checked_index] = element;
				v->size++;
				return 0;
			
			}
		}
		v->data[checked_index] = element;
		v->size++;
		return 0;
	}
}

int vector_delete(u_vector*v,int element) { //vector_delete(&v,element);
    if (v->data == NULL || v->size == 0 || v_initialized == 0) {
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

int vector_pop(u_vector* v) {
    if (v->data == NULL || v->size == 0 || v_initialized == 0) {
        fprintf(stderr, "vector_pop: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    if(v->size > 0) {
        v->size--;
        return v->data[v->size+1];
    }
}

int vector_multiply(u_vector* v) {
     if (v->data == NULL || v->size == 0 || v_initialized == 0) {
        fprintf(stderr, "vector_multiply: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int result = 1;
    for(int i=0;i<v->size;i++)
        result *= v->data[i];
    return result;
}

int vector_sum(u_vector* v) {
     if (v->data == NULL || v->size == 0 || v_initialized == 0 ) {
        fprintf(stderr, "vector_sum: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int sum = 0;
    for(int i=0;i<v->size;i++)
        sum += v->data[i];
    return sum;
}

float vector_avg(u_vector* v) {
    if (v->data == NULL || v->size == 0 || v_initialized == 0) {
        fprintf(stderr, "vector_avg: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int sum = 0;
    for(int i=0;i<v->size;i++) {
        sum += v->data[i];
    }
    return (float) ((float)sum/(float)v->size);
}

int vector_get_last_element(u_vector* v) {
    if (v->data == NULL || v->size == 0 || v_initialized == 0 ) {
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

int vector_size(u_vector *v) {
	if (v->data == NULL || v_initialized == 0 ) {
        fprintf(stderr, "vector_size: Vector is NULL | maybe not initialized\n");
        return -1;
    }
    return v->size;
}

void vector_print(u_vector*v) {
	if (v->data == NULL || v->size == 0 || v_initialized == 0) {
        fprintf(stderr, "vector_print: Vector is empty or NULL | maybe not initialized\n");
        return;
    }
    printf("[");
    for(int i=0;i<v->size-1;i++) printf("%d,",v->data[i]);
    printf("%d]\n",v->data[v->size-1]);
    return;
}

int vector_destroy(u_vector*v){
    if (v->data == NULL || v_initialized == 0) {
        fprintf(stderr, "vector_destroy: Vector is NULL | maybe already destroyed or not initialized\n");
        return -1;
    }
    free(v->data);
    v->data = NULL;
    v->size = 0;
    return 0;
}

void vector_fill(u_vector* v, int fill_val) 
{
    if (v->data == NULL || v->size == 0 || v_initialized == 0) 
	{
        fprintf(stderr, "vector_fill: Vector is empty or NULL | maybe not initialized\n");
        return;
    }
    for(int i=0;i<v->size;i++)
        v->data[i] = fill_val;
}
