#include <iostream>
#include <cmath>
using std::cout;

const void swap_(auto &a,auto &b){
	auto temp = &a;
	&a = &b;
	&b = temp;
}

const void printArr(int array[],int size) {
	for(int i=0;i<size;i++)
		cout << array[i] << " ";
	cout << "\n";
}

namespace sorting 
{
	void bubble(int array[],int size) { //bubble sort
		int temp;
		for(int i=1;i<size;i++) {
			for(int j=0;j<size-i;j++) {
				if(array[j] > array[j+1]) {
					temp = array[j+1];
					array[j+1] = array[j];
					array[j] = temp;
				}
			}
		}
//		printArr(array,size);
	}
	void bubble2(int array[],int size) { //bubble sort with other algorithm
		int temp;
		for(int i=0;i<size-1;i++) {
			for(int j=i+1;j<size;j++) {
				if(array[i] > array[j]) {
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}
//		printArr(array,size);
	}
	void selection(int array[],int size) { //selection sort
		int temp,minIndex;
		for(int i=0;i<size-1;i++) {
			minIndex = i;
			for(int j=i;j<size;j++) {
				if(array[j] < array[minIndex]) minIndex = j;
			}
			temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
//		printArr(array,size);
	}
}

int mod(int arr[],int size) {
	int index,k=0,eb=0;
	for(int i=0;i<size;i++) {
		eb=0;
		for(int j=0;j<size;j++) {
			if(arr[j] == arr[i])
				eb++;
		}
		if(eb > k) {
			k = eb;
			index = i;
		}
	}
//	cout << "The most repeated value "<<arr[index]<<"\n";
  return arr[index];
}

void reverseArr(int arr[],int size) {
	for(int i =0;i<size/2;i++) {
		int temp = arr[size-i-1];
		arr[size-i-1] = arr[i];
		arr[i] = temp;
	}
	for(int i=0;i<size;i++)
		cout << arr[i] << " ";
	cout << "\n";
}
int closeValToAvarageValue(int arr[],int size) {
	int sum=0,avVal;
	for(int i=0;i<size;i++)
		sum+=arr[i];
	avVal = sum / size;
	int index;
	int offset = avVal;
	for(int i=0;i<size;i++) {
		int newOffset = avVal - arr[i];
		if(newOffset < 0) {
			newOffset = newOffset * -1;
			if(newOffset < offset) {
				offset = newOffset;
				index = i;
			}
		}
		else {
			if(newOffset == 0) {
				offset = 0;
				index = i;
			}
			else if(newOffset < offset) {
				offset = newOffset;
				index = i;
			}
		}
	}
//	cout << "\n";
//	cout << "Avarage: " << avVal << "\n";
//	cout << "The closet difference to the avarage: "<< offset << "\n";
//	cout << "The closet value to the avarage: " << arr[index] << "\n";
	return arr[index];
}


