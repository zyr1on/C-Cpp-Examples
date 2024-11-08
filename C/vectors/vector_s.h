#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5
typedef struct {
    int initialized;
    char**data;
    size_t size;
    size_t capacity;
} vector_s;

int vector_init_s(vector_s* v) {
    if (v == NULL ||v->data == NULL) {
        fprintf(stderr, "vector_init_s: Vector pointer is NULL\n");
        return -1;
    }
    if (v->initialized == 1) {
        fprintf(stderr, "vector_init_s: Vector is already initialized\n");
        return -1;
    }
    v->capacity  = INITIAL_CAPACITY;
    v->data = (char**)malloc(sizeof(char*) * v->capacity);
    if(v->data == NULL) 
    {
        perror("vector_init_s: (malloc) Memory allocation error");
        return -1;
    }
    v->size = 0;
    v->initialized = 1;
    return 0;
}
int vector_push_back_s(vector_s* v, char* string) {
    if (v == NULL || v->initialized != 1 || v->data == NULL) {
        fprintf(stderr, "vector_push_back_s: Vector is NULL or not initialized\n");
        return -1;
    }
    if (v->size >= v->capacity) {
        char** temp = (char**)malloc(sizeof(char*) * v->capacity * 2);
        if (temp == NULL) {
            perror("vector_push_back_s: (malloc) Memory allocation error");
            return -1;
        }
        for(int i=0;i<v->size;i++) 
        {
            temp[i] = (char*)malloc(sizeof(char) * strlen(v->data[i]));
            strncpy(temp[i],v->data[i],strlen(v->data[i]));
            temp[i][strlen(v->data[i])] = '\0';
        }
        for(int i=0;i<v->capacity / 2 ;i++) 
            free(v->data[i]);
        free(v->data);
        v->data = temp;
        v->capacity *= 2;
    }
    v->data[v->size] = (char*)malloc(sizeof(char) * (strlen(string)));
    if (v->data[v->size] == NULL) {
        perror("vector_push_back_s: (malloc) Memory allocation error");
        return -1;
    }
    strncpy(v->data[v->size], string, strlen(string));
    v->data[v->size][strlen(string)] = '\0';
    v->size++;
    return 0;
}
void vector_print_s(vector_s* v) {
	if (v == NULL || v->initialized != 1||v->data == NULL || v->size == 0) {
        fprintf(stderr, "vector_print_s: Vector is empty or NULL | maybe not initialized\n");
        return;
    }
    printf("[");
    for(int i=0;i<v->size;i++)
        if(i != v->size-1) 
            printf("\"%s\",",v->data[i]);
        else 
            printf("\"%s\"]",v->data[i]);
    printf("\n");
}
int vector_destroy_s(vector_s* v)
{
    if (v == NULL || v->initialized != 1 ||v->data == NULL)
    {
        fprintf(stderr, "vector_destroy_s: Vector is not initialized\n");
        return -1;
    }
    for(int i=0;i<v->capacity;i++)
        free(v->data[i]);
    free(v->data);
    v->data=NULL;
    v->size = 0;
    v->capacity = 0;
    v->initialized = 0;
    return 0;
}

