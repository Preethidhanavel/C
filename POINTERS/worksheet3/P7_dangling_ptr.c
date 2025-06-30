/*7.Dangling Pointer Scenario
Goal: Identify potential risks and behavior of dangling pointers in embedded dynamic memory management.
Activity:
Write a function that allocates a block of memory dynamically using malloc() and returns the pointer:
int *allocate_buffer(void) {
  int *buf = (int *)malloc(10 * sizeof(int));
  return buf;
}
In the calling context, free the memory pointed to and then try to access it via the original pointer.
Use debug prints or debugger to observe system behavior.*/

#include <stdio.h>
#include <stdlib.h>

int* allocate_buffer(void) {
    int *buf = (int *)malloc(10 * sizeof(int));
    if (buf == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 0;;
    }
    for (int i = 0; i < 10; i++) 
    {
        buf[i] = i * 10;
    }

    return buf;
}

int main() 
{
    int *buffer = allocate_buffer();

    printf("Buffer contents before free:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    free(buffer);
    printf("Memory has been freed.\n");

    printf("Attempting to access buffer after free (dangling pointer):\n");
    for (int i = 0; i < 10; i++) 
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    return 0;
}
