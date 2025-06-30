//Write a C function that allocates and frees an array of integers. First, make a version that causes a memory leak. Then, fix the leak.
#include <stdio.h>
#include <stdlib.h>

void create_and_free_array() {
    int *arr = malloc(5 * sizeof(int));
    if (arr == NULL) {
        return;
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }

    free(arr);//To avoid Memory Leak
}

int main() {
    create_and_free_array();
    printf("Function ran with memory properly freed\n");
    return 0;
}

