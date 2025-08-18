/*16.Question: Find duplicate elements
Question description: Write a C program to find all duplicate elements in an array.
Sample data:
Input: 1 2 3 2 4 1
Expected output:
Duplicate elements: 1 2*/

#include <stdio.h>

void dup(int *arr, int ele)
{
    int i, j, isdup;

    printf("Duplicate elements: ");
    for (i = 0; i < ele; i++) {
        isdup = 0;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isdup = 1;
                break;
            }
        }
        if (isdup)
            continue;

        int count = 0;
        for (j = i + 1; j < ele; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > 0) {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int arr[6], i;
    int ele = sizeof(arr) / sizeof(arr[0]);

    printf("Input: ");
    for (i = 0; i < ele; i++) {
        scanf("%d", &arr[i]);
    }

    dup(arr, ele);
    return 0;
}
