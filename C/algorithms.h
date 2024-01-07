#include <stdio.h>
#include <stdbool.h>
// !!!!! all functions working with int arrays
// Author: Semih Özdemir

const void printArr(int arr[],int size) {
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
}

// reverse array
const void reverseArr(int arr[],int size) {
    for(int i=0;i<size/2;i++){
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}
// swaps 2 given elements | swap(&a,&b);
const void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// sorts array
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

// Shift the array elements to the left from begin point and add the first element to the end (Shifts to the left by the count value.)
const void shift_left_t(int begin,int swipe_count,int arr[],int size) { 
    for(int t=0;t<swipe_count;t++) {
        int temp = arr[begin];
        for(int i=begin+1;i<size;i++)
            arr[i-1]=arr[i];
        arr[size-1] = temp;
    }
}

// Shift the array elements to the left and add the zero value to the end (Shifts to the left by the count value.)
const void shift_left_withZero(int try,int arr[],int size) {
    for(int t=0;t<try;t++) {
        int temp = arr[0];
        for(int i=1;i<size;i++)
            arr[i-1]=arr[i];
        arr[size-1] = 0;
    }
}

const int mod(int arr[],int size) {
	int index,k=0,count=0;
	for(int i=0;i<size;i++) {
		count = 0;
		for(int k=0;k<size;k++)
			if(arr[k] == arr[i]) count++;
		if(count > k) {
			k = count;
			index = i;
        	}
	}
	return arr[index];
}

bool isPrime(int num) { // isPrime(number) returns 1 or 0;
	if(num % 2 == 0)
		return num == 2;
	if(num % 3 == 0)
		return num == 3;
	if(num % 5 == 0)
		return num == 5;
	if(num % 7 == 0)
		return num == 7;
	if(num % 11 == 0)
		return num == 11;
	for(int i=13;i<num/2;i+=2)
		if( num % i == 0 ) return false;
	return true;
}

int partition(int arr[],int low,int high)
{
  int pivot=arr[high];
  int i=(low-1);
  for(int j=low;j<=high;j++) {
    if(arr[j]<pivot) {
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i+1);
}

// quickSort(arr,0,size-1);
void quickSort(int arr[],int low,int high)
{
	if(low<high) {     
		int pi=partition(arr,low,high);
		quickSort(arr,low,pi-1);
    	quickSort(arr,pi+1,high);
	}
}




