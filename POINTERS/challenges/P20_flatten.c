//20.Log Session a program that flattens a 2D array into a 1D array using pointers.
#include <stdio.h>

void flatten(int rows, int cols, int arr[rows][cols], int *flatArr) {
    int *ptr = &arr[0][0];
    for (int i = 0; i < rows * cols; i++) {
        flatArr[i] = *(ptr + i);
    }
}

int main() {
    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int flatArr[6];

    flatten(2, 3, arr, flatArr);

    printf("Flattened array: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", flatArr[i]);
    }
    printf("\n");

    return 0;
}
