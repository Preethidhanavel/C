//5.Log Session a function that segregates even and odd values of an integer array using pointers.
#include <stdio.h>

void segregateEvenOdd(int *arr, int size) 
{
    printf("Even numbers: ");
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            printf("%d ", *(arr + i));
        }
    }

    printf("\nOdd numbers: ");
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 != 0) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

int main() 
{
    int numbers[] = {10, 3, 4, 7, 8, 1, 12};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    segregateEvenOdd(numbers, size);

    return 0;
}
