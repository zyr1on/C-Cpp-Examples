#include <stdio.h>

// prints the integer array side by side
const void printArr(int arr[],int size) { 
    for(int i=0;i<size;i++) {
         printf("%d",arr[i]);       
    }
}

// prints the integer array with a new line
const void printArr_(int arr[],int size) { 
    for(int i=0;i<size;i++) {
         printf("%d\n",arr[i]);       
    }
}

// number of digits of the given number
int total_digits(long int number) { 
    int count = 0;
    while(number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

// adds each digit of the given number to the array
void digits_to_array(long int number, int arr[], int size) {
    long int temp = number;
    int count = 0;
    while(temp != 0) {
        arr[count] = temp % 10;
        temp /= 10;
        count++;
    }
    for(int i=0;i<size/2;i++) { // reversing array
        int temp_ = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp_;
    }
}

int main() {
    long int number;                     // defines long integer number that will attach variable with scanf function
    printf(">");
    scanf("%ld",&number);                // waits for input from the user to give the number whose digits we put into the array
    int size = total_digits(number);     // calculates the size of the array we will create
    int arr[size];                       // Creates an array containing each digit of the number
    digits_to_array(number,arr,size);
    printArr_(arr,size);                 // prints digits with new line
    
}
