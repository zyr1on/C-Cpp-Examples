/*
	AUTHOR: Semih "zyr1on" Özdemir
 	ordered dynamic array implementation of C
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define INITIAL_CAP 5
typedef struct {
    int* data;
    size_t size;
    size_t capacity;
    int initialized;
} ordered_vector;

int ordered_vector_init(ordered_vector*v) {
    if(v->initialized == 1) {
        fprintf(stderr, "vector_init: Vector is already initialized\n");
        return -1;
    }
    v->data = (int*)malloc(sizeof(int)*INITIAL_CAP); // 4byte;
    if(v->data == NULL) {
        perror("ordered_vector_init: Memory allocation error\n");
        return -1;
    }
    v->size = 0;
    v->capacity = INITIAL_CAP;
    v->initialized = 1;
    return 0;
}

int ordered_vector_insert(ordered_vector*v,int element) 
{
	if (v->data == NULL || v->initialized != 1) 
	{
        fprintf(stderr, "ordered_vector_insert: Vector is NULL or not initialized\n");
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
        	perror("ordered_vector_insert: Temporary Memory allocation error");
			return -1;
        }
		int checked_index = 0;
		for(int i=0;i<v->size;i++) 
		{
			if(element >= v->data[i]) 
				checked_index++;
			else 
			{
				// for(int k=0;k<checked_index;k++) 
				//      temp[k] = v->data[k];
                memcpy(temp,v->data,sizeof(int) * checked_index);
				temp[checked_index] = element;
				// for(int k=checked_index;k<v->size;k++) 
				// 	temp[k+1] = v->data[k];
                memcpy(temp + checked_index + 1,v->data + checked_index,sizeof(int)* (v->size - checked_index));                
                break;
            }
		}
		v->size++;
		free(v->data);
		v->data = temp;
        return 0;
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
				memmove(v->data + checked_index + 1, v->data + checked_index, sizeof(int) * (v->size - checked_index));
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

int ordered_vector_delete(ordered_vector*v,int element) 
{
    if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "ordered_vector_delete: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int index = -1;
    for(int i=0;i<v->size;i++)
        if(v->data[i] == element)
            index = i;
    if(index != -1) {
        int* tempData = (int*)malloc(sizeof(int)*v->capacity);
        if(tempData == NULL) perror("ordered_vector_delete: Memory allocation error");
        for(int i=0;i<index;i++)
            tempData[i] = v->data[i];
        for(int i=index;i<v->size;i++)
            tempData[i] = v->data[i+1];
        free(v->data);
        v->data = tempData;
        v->size--;
        return 0;
    }
    else return -1;
}

int ordered_vector_pop(ordered_vector* v) {
    if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "vector_pop: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    if(v->size > 0) {
        v->size--;
        return v->data[v->size+1];
    }
}

int ordered_vector_multiply(ordered_vector* v) {
     if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "ordered_vector_multiply: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int result = 1;
    for(int i=0;i<v->size;i++)
        result *= v->data[i];
    return result;
}

int ordered_vector_sum(ordered_vector* v) {
     if (v->data == NULL || v->size == 0 || v->initialized != 1 ) {
        fprintf(stderr, "ordered_vector_sum: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int sum = 0;
    for(int i=0;i<v->size;i++)
        sum += v->data[i];
    return sum;
}

float ordered_vector_avg(ordered_vector* v) {
    if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "ordered_vector_avg: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int sum = 0;
    for(int i=0;i<v->size;i++) {
        sum += v->data[i];
    }
    return (float) ((float)sum/(float)v->size);
}

int ordered_vector_last(ordered_vector* v) {
    if (v->data == NULL || v->size == 0 || v->initialized != 1 ) {
        fprintf(stderr, "ordered_vector_last: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    if(v->size == 0) {
        return v->data[0];
    }
    else {
        return v->data[v->size-1];
    }   
}

int ordered_vector_size(ordered_vector *v) {
	if (v->data == NULL || v->initialized != 1 ) {
        fprintf(stderr, "ordered_vector_size: Vector is NULL | maybe not initialized\n");
        return -1;
    }
    return v->size;
}

void ordered_vector_print(ordered_vector*v) {
	if (v->data == NULL || v->size == 0 || v->initialized != 1) {
        fprintf(stderr, "ordered_vector_print: Vector is empty or NULL | maybe not initialized\n");
        return;
    }
    printf("[");
    for(int i=0;i<v->size-1;i++) printf("%d,",v->data[i]);
    printf("%d]\n",v->data[v->size-1]);
    return;
}

int ordered_vector_destroy(ordered_vector*v){
    if (v->data == NULL || v->initialized != 1) {
        fprintf(stderr, "ordered_vector_destroy: Vector is NULL | maybe already destroyed or not initialized\n");
        return -1;
    }
    free(v->data);
    v->data = NULL;
    v->size = 0;
    return 0;
}

void ordered_vector_fill(ordered_vector* v, int fill_val) 
{
    if (v->data == NULL || v->size == 0 || v->initialized != 1) 
	{
        fprintf(stderr, "ordered_vector_fill: Vector is empty or NULL | maybe not initialized\n");
        return;
    }
    memset(v->data,fill_val,sizeof(int)*v->size);
}
int ordered_vector_IndexAt(ordered_vector* v, int element) 
{
    if (v->data == NULL || v->size == 0 || v->initialized != 1) 
	{
        fprintf(stderr, "ordered_vector_s_IndexAt: Vector is empty or NULL | maybe not initialized\n");
        return -1;
    }
    int eb = v->size + 1;
    int ek = -1;
    while(ek < eb) 
    {
        int lookIndex = (eb + ek) / 2;
        if(v->data[lookIndex] == element) return lookIndex;
        else if(v->data[lookIndex] > element) eb = lookIndex -1;
        else ek = lookIndex + 1;
    }
    return -1;
}
