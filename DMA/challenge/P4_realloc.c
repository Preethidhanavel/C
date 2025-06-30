/*You want to make a memory block bigger using realloc. How can you do this safely, so you don’t lose your data if realloc fails?*/
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        printf("Initial malloc failed.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    int *temp = (int *)realloc(arr, 10 * sizeof(int));
    if (temp == NULL) {
        printf("Realloc failed. Original memory is still valid.\n");
    } 
    else {
        arr = temp;

        for (int i = 5; i < 10; i++) {
            arr[i] = (i + 1) * 10;
        }

        for (int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}
