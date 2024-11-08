#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5
typedef struct {
    char**data;
    size_t size;
    size_t capacity ;
} vector_s;

int v_initialized = 0;
int vector_init_s(vector_s* v) {
    if(v_initialized == 1) 
    {
        fprintf(stderr, "vector_init_s: Vector is already initialized\n");
        return -1;
    }
    else 
    {
        v->data = (char**)malloc(sizeof(char*) * v->capacity );
        if(v->data == NULL) 
        {
            perror("vector_init_s: (malloc) Memory allocation error");
            return -1;
        }
        v->size = 0;
        v->capacity  = INITIAL_CAPACITY;
        v_initialized = 1;
        return 0;
    }
}
int vector_push_back_s(vector_s* v,char* string) {
    if(v->data == NULL || v_initialized == 0) 
    {
        fprintf(stderr, "vector_push_back_s: Vector is NULL or not initialized\n");
        return -1;
    }
    if(v->size < v->capacity ) 
    {
        v->data[v->size] = (char*)malloc(sizeof(char)* (strlen(string) + 1));
        if (v->data[v->size] == NULL) {
            perror("vector_push_back_s: (malloc) Memory allocation error");
            return -1;
        }
        strncpy(v->data[v->size],string,strlen(string));
        v->data[v->size][strlen(string)] = '\0';
        v->size++;
        return 0;
    }
    else 
    {
        v->capacity *=2;
        char** temp = (char**)malloc(sizeof(char*) * v->capacity );
        if(temp == NULL) 
        {
            perror("vector_push_back_s: (malloc) Memory allocation error");
            return -1;
        }
        for(int i=0;i<v->size;i++)
            temp[i] = v->data[i];
        free(v->data);
        v->data= temp;
        v->data[v->size] = (char*)malloc(sizeof(char)* (strlen(string)));
        if (v->data[v->size] == NULL) {
            perror("vector_push_back_s: (malloc) Memory allocation error");
            return -1;
        }
        strncpy(v->data[v->size],string,strlen(string));
        v->data[v->size][strlen(string)] = '\0';
        v->size++;
        return 0;
    }
}
void vector_print_s(vector_s* v) {
	if (v->data == NULL || v->size == 0 || v_initialized == 0) {
        fprintf(stderr, "vector_print_s: Vector is empty or NULL | maybe not initialized\n");
        return;
    }
    printf("[");
    for(int i=0;i<v->size;i++)
        if(i != v->size-1) 
            printf("%s,",v->data[i]);
        else 
            printf("%s]",v->data[i]);
    printf("\n");
}
int vector_destroy_s(vector_s* v)
{
    if(v_initialized == 0) 
    {
        fprintf(stderr, "vector_destroy_s: Vector is not initialized\n");
        return -1;
    }
    for(int i=0;i<v->size;i++)
        free(v->data[i]);
    free(v->data);
    v->data=NULL;
    v->size = 0;
    v->capacity = 0;
    return 0;
}
