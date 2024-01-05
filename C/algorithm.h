#include <stdio.h>

const void reverseArr(int arr[],int size) {
    for(int i=0;i<size/2;i++){
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}
const void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

const void selection_sort(int arr[],int size) {
    for(int i=0;i<size-1;i++) {
        int minIndex = i;
        for(int k=i;k<size;k++)
        	if(arr[k] < arr[minIndex])
                minIndex = k;
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Shift the array elements to the left and add the first element to the end (Shifts to the left by the count value.)
const void shift_left(int swipe_count,int arr[],int size) { 
    for(int t=0;t<swipe_count;t++) {
        int temp = arr[0];
        for(int i=1;i<size;i++)
            arr[i-1]=arr[i];
        arr[size-1] = temp;
    }
}
