/*2.Sorting Algorithms Selector
Implement three sorting functions (bubbleSort, selectionSort, insertionSort) that sort an integer array.
Store pointers to these sorting functions in an array of function pointers.
Prompt the user to choose a sorting method, and use the selected function pointer to sort a user-provided integer array.
*/
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n -1; i++) {
        for (int j = i +1; j < n; j++) {
            if (arr[j] < arr[i]) {
        int temp = arr[j]; 
        arr[j] = arr[i]; 
        arr[i] = temp;
        }
    }
}
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i -1;
        while (j >=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i=0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    void (*sortFuncs[])(int[], int) = {bubbleSort, selectionSort, insertionSort};

    int choice;
    printf("Choose sorting method:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice!\n");
        return 1;
    }

    sortFuncs[choice -1](arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
