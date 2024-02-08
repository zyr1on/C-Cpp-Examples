#include <stdio.h>

// prints the integer array
const void printArr(int arr[],int size,int mode) { 
    switch (mode) {
    case 1:                            //  Mode:1 Side by side with spaces
        for(int i=0;i<size;i++)
            printf("%d ",arr[i]);
        break;
    case 2:                            // Mode:2 With new line
        for(int i=0;i<size;i++)
            printf("%d\n",arr[i]);
        break;
    default:                          //  Default: Side by side without spaces
        for(int i=0;i<size;i++)
            printf("%d",arr[i]);
        break;
    }
}

// returns number of digits of the given number
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
        arr[(size -1) - count] = temp % 10;
        temp /= 10;
        count++;
    }
    // for(int i=0;i<size/2;i++) { // reversing array
    //     int temp_ = arr[i];
    //     arr[i] = arr[size-1-i];
    //     arr[size-1-i] = temp_;
    // }
}

void printArrLikePython(int arr[],int size) {
    for(int i=0;i<size;i++) {
        if(i == 0)
            printf("[%d,",arr[i]);
        else if(i == size-1)
            printf("%d",arr[i]);
        else 
            printf("%d,",arr[i]);
    }
    printf("]\n");
}

int main() {
    long int number;                     // defines long integer number that will attach variable with scanf function
    printf(">");
    scanf("%ld",&number);                // waits for input from the user to give the number whose digits we put into the array
    int size = total_digits(number);     // calculates the size of the array we will create
    int arr[size];                       // Creates an array containing each digit of the number
    digits_to_array(number,arr,size);
    //printArr(arr,size,2);                // prints digits with mode 2(with new line)
    printArrLikePython(arr,size);           // prints digits in array like python.
    
}
