/*Log Session your own version of calloc by using malloc and memset.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t num, size_t size) {
    size_t total_size = num * size;
    void *ptr = malloc(total_size);
    if (ptr) {
        memset(ptr, 0, total_size);
        printf("Allocated %zu bytes, initialized to zero at %p\n", total_size, ptr);
    } else {
        printf("Allocation failed for %zu bytes\n", total_size);
    }
    return ptr;
}

int main() 
{
    int *arr = (int *)my_calloc(5, sizeof(int));
    if (!arr) {
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}
