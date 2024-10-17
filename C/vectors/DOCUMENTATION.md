<h1>Click Arrow For More Information</h1>

<details>
<summary style="font-size: 18px;">VECTOR.H</summary>
<h1> How to use vector.h</h1>
<h2>Vector container like C++ for C.</h2>

1. First we need to include our header file.

```c
#include "vector.h"         // for unordered_vector;
```
2. Create and initialize vector struct.
```c
#include "vector.h"
int main() {
    vector v;
    vector_init(&v);
}
```
3. Introduction to Vector and Vector functions.
```c

#define INITIAL_CAP 5                         -> default initial capacity of vector.
int compare(const void* a, const void* b)     -> the comparison function that qsort uses.
v_initialized                                 -> global variable that checks whether the vector is initialized or not.

void vector_init(vector*v)                    -> *initializes vector.
int vector_push_back(vector*v, int element)   -> pushs an element to end of the vector. (0 succes -1 fail)
int vector_push_front(vector* v,int element)  -> pushs an element to begining of the vector.(0 succes -1 fail)
int vector_delete(vector* v,int element)      -> deletes an element from vector that passed to function.(0 succes -1 fail)
int vector_sort(vector* v)                    -> sorts vector.(0 succes -1 fail)
int vector_pop(vector* v)                     -> pops vector element (assume last element deleted)
int vector_multiply(vector* v)                -> returns the result of multiplying all vector elements
int vector_sum(vector* v)                     -> returns the result of summing all vector elements
float vector_avg(vector* v)                   -> returns total average of vector elements
int vector_get_last_element(vector* v)        -> returns vector's last element.
int vector_max(vector* v)                     -> returns the maximum value in the vector
int vector_min(vector* v)                     -> returns the minimum value in the vector
int vector_size(vector *v)                    -> returns size of vector.
void vector_print(vector*v)                   -> prints vector like python lists.
void vector_shuffle(vector* v)                -> shuffle vector's elements.
void vector_fill(vector* v,int fill_val)      -> fills all vectors elements to fill_val parameter.
int vector_destroy(vector*v)                  -> *terminates vector and frees memory block. (0 succes -1 fail)
```
4. Basic instructions to start and use vector.
```c
#include "vector.h"
int main() {
    vector v;             //create vector object
    vector_init(&v);      // initialize vector object
    ...
    ...
    ...
    vector_destroy(&v);   // terminate vector object
}
```
5.Example usage:
```c
#include "vector.h"

int main() {
    vector v;
    vector_init(&v);
    
    vector_push_back(&v,5);
    vector_push_back(&v,12);
    vector_push_back(&v,13);
    vector_print(&v);
    
    vector_push_front(&v,-9);
    vector_push_front(&v,12586);
    vector_print(&v);
    
    vector_shuffle(&v);
    vector_print(&v);
    
    vector_sort(&v);
    vector_print(&v);

    vector_delete(&v,12586);
    vector_print(&v);

    printf(" Maximum value in vector is:    %d\n" , vector_max(&v));
    printf(" Average of vector elements is: %f\n" , vector_avg(&v));

    vector_destroy(&v);
}
```
</details>
<details>
<summary style="font-size: 18px;">ORDERED_VECTOR.H</summary>
<h1> How to use ordered_vector.h</h1>
<h2> Ordered Vector container like C++ for C. "Elements are sorted in an orderly manner." </h2>

1. First we need to include our header file.

```c
#include "ordered_vector.h"         // for ordered_vector;
```
2. Create and initialize vector struct.
```c
#include "ordered_vector.h"
int main() {
    u_vector v;
    vector_init(&v);
}
```
3. Introduction to Vector and Vector functions.
```c

#define INITIAL_CAP 5                         -> default initial capacity of vector.
v_initialized                                 -> global variable that checks whether the vector is initialized or not.

void vector_init(vector*v)                    -> *initializes vector.
int u_vector_push_back(vector*v, int element)   -> pushs an element to end of the vector. (0 succes -1 fail)
int vector_delete(vector* v,int element)      -> deletes an element from vector that passed to function.(0 succes -1 fail)
int vector_pop(vector* v)                     -> pops vector element (assume last element deleted)
int vector_get_last_element(vector* v)        -> returns vector's last element.
int vector_size(vector *v)                    -> returns size of vector.
void vector_print(vector*v)                   -> prints vector like python lists.
void vector_fill(vector* v,int fill_val)      -> fills all vectors elements to fill_val parameter.
int vector_destroy(vector*v)                  -> *terminates vector and frees memory block. (0 succes -1 fail)
```
4. Basic instructions to start and use vector.
```c
#include "ordered_vector.h"
int main() {
    u_vector v;            //create vector object
    vector_init(&v);      // initialize vector object
    ...
    ...
    ...
    vector_destroy(&v);   // terminate vector object
}
```

5.Example usage:
```c
#include "ordered_vector.h"

int main() {
    u_vector v;
    vector_init(&v);

    u_vector_push_back(&v,5); // 5 _ _ _ _
    u_vector_push_back(&v,1); // 1 5 _ _ _
    u_vector_push_back(&v,7); // 1 5 7 _ _
    u_vector_push_back(&v,0); // 0 1 5 7 _ 

    vector_print(&v);

    vector_destroy(&v);
}
```
</details>
