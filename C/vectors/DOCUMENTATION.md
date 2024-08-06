<h1> How to use vector.h</h1>

1. First we need to include our header file.

```c
#include "vector.h"
```

2. Create and initialize vector struct.
```c
#include "vector.h"
int main() {
    vector v;
    vector_init(&v);
}
```
3. Introduction to Vector functions.
```c
int vector_push_back(vector*v, int element)   -> pushs an element to end of the vector. (0 succes -1 fail)
int vector_push_front(vector* v,int element)  -> pushs an element to begining of the vector.(0 succes -1 fail)
int vector_delete(vector* v,int element)      -> deletes an element from vector that passed to function.(0 succes -1 fail)
int vector_sort(vector* v)                    -> sorts vector.(0 succes -1 fail)
int vector_pop(vector* v)                     -> pops vector element (assume last element deleted)
int vector_multiply(vector* v)                -> returns the result of multiplying all vector elements
int vector_sum(vector* v)                     -> returns the result of summing all vector elements
float vector_avg(vector* v)                   -> returns total avarege of vector elements
int vector_get_last_element(vector* v)        -> returns vector's last element.
int vector_max(vector* v)                     -> returns the maximum value in the vector
int vector_min(vector* v)                     -> returns the minimum value in the vector
int vector_size(vector *v)                    -> returns size of vector.
int vector_print(vector*v)                    -> prints vector like python lists.
void vector_shuffle(vector* v)                -> shuffle vector's elements.
int vector_destroy(vector*v)                  -> terminates vector and frees memory block.
```
