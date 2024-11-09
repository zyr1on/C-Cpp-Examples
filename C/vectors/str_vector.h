#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5
typedef struct {
    int initialized;
    char**data;
    size_t size;
    size_t capacity;
} str_vector;

int str_vector_init(str_vector* v) {
    if (v == NULL) {
        fprintf(stderr, "str_vector_init: Vector pointer is NULL\n");
        return -1;
    }
    if (v->initialized == 1) {
        fprintf(stderr, "str_vector_init: Vector is already initialized\n");
        return -1;
    }
    v->capacity  = INITIAL_CAPACITY;
    v->data = (char**)malloc(sizeof(char*) * v->capacity);
    if(v->data == NULL) 
    {
        perror("str_vector_init: (malloc) Memory allocation error");
        return -1;
    }
    v->size = 0;
    v->initialized = 1;
    return 0;
}
int str_vector_push_back(str_vector* v, char* string) {
    if (v == NULL || v->initialized != 1 || v->data == NULL) {
        fprintf(stderr, "str_vector_push_back: Vector is NULL or not initialized\n");
        return -1;
    }
    if (v->size >= v->capacity) {
        char** temp = (char**)malloc(sizeof(char*) * v->capacity * 2);
        if (temp == NULL) {
            perror("str_vector_push_back: (malloc) Memory allocation error");
            return -1;
        }
        for(int i=0;i<v->size;i++) 
        {
            temp[i] = (char*)malloc(sizeof(char) * (strlen(v->data[i])+1));
            strncpy(temp[i],v->data[i],strlen(v->data[i]));
            temp[i][strlen(v->data[i])] = '\0';
        }
        for(int i=0;i<v->capacity / 2 ;i++) 
            free(v->data[i]);
        free(v->data);
        v->data = temp;
        v->capacity *= 2;
    }
    v->data[v->size] = (char*)malloc(sizeof(char) * (strlen(string) + 1));
    if (v->data[v->size] == NULL) {
        perror("vector_push_back_s: (malloc) Memory allocation error");
        return -1;
    }
    strncpy(v->data[v->size], string, strlen(string));
    v->data[v->size][strlen(string)] = '\0';
    v->size++;
    return 0;
}
void str_vector_print(str_vector* v) {
	if (v == NULL || v->initialized != 1||v->data == NULL || v->size == 0) {
        fprintf(stderr, "str_vector_print: Vector is empty or NULL | maybe not initialized\n");
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
int str_vector_destroy(str_vector* v)
{
    if (v == NULL || v->initialized != 1 ||v->data == NULL)
    {
        fprintf(stderr, "str_vector_destroy: Vector is not initialized\n");
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
int str_vector_IndexAt(str_vector* v, char* element) 
{
    for(int i=0;i<v->size;i++) 
        if(strcmp(v->data[i],element) == 0) 
            return i;
    return -1;
}
void str_vector_fill(str_vector* v,char* fill_val) 
{
    size_t fill_len = strlen(fill_val);
    for (int i = 0; i < v->size; i++) 
    {
        free(v->data[i]);
        v->data[i] = (char*)malloc(sizeof(char) * (fill_len + 1));
        if (v->data[i] != NULL) {
            strncpy(v->data[i], fill_val, fill_len);
            v->data[i][fill_len] = '\0';
        } else {
            fprintf(stderr, "Memory allocation failed for element %d\n", i);
        }
    }
}
