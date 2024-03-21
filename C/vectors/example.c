#include "vector.h"

int main() {
	vector vec;
	vector_init(&vec); // vector initialized
	
	vector_push_back(&vec,5);
	vector_push_back(&vec,12);
	vector_push_back(&vec,13);
	vector_push_back(&vec,7);
	vector_push_back(&vec,24);
	vector_push_back(&vec,25);
	// vector= [5,12,13,7,24,25];
	
	vector_pop(&vec); // last element remoed | vector= [5,12,13,7,24];
	vector_delete(&vec,13); // 13 removed    | vector= [5,12,7,24];
	vector_sort(&vec); // selection sorted   | vector= [5,7,12,24];
	print_vector(&vec);

	printf("total number of elements in the vector-> %d\n",vector_size(&vec));
	printf("largest value in vector-> %d\nsmallest value in vector-> %d\n",vector_max(&vec),vector_min(&vec));
	printf("multiplication of elements in vector-> %d\nsum of elements in vector-> %d\n",vector_multiply(&vec),vector_sum(&vec));
	printf("average of elements in vector-> %f\n",vector_avg(&vec));
	destroy_vector(&vec); // [IMPORTANT] vector destroyed;
}
