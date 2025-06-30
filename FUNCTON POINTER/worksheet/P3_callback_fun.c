/*3.Callback Function Array Processing
Define a function processArray that accepts an integer array, its size, and a callback function as arguments.
Implement callback functions (increment, doubleValue) that modify array elements in different ways.
Demonstrate invoking processArray with different callback functions.*/
#include <stdio.h>

typedef void (*Callback)(int *);

void increment(int *element) 
{
    (*element) += 1;
}

void doubleValue(int *element) 
{
    (*element) *= 2;
}

void processArray(int *arr, int size, Callback cb) 
{
    for (int i = 0; i < size; i++) {
        cb(&arr[i]);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    printArray(data, size);

    processArray(data, size, increment);
    printf("After increment: ");
    printArray(data, size);

    processArray(data, size, doubleValue);
    printf("After doubling: ");
    printArray(data, size);

    return 0;
}
