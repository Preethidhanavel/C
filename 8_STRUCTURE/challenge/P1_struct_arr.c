/*1.What is the difference in memory organization between a structure and an array, especially considering padding and alignment? */
#include <stdio.h>

struct MixedStruct {
    char a;    
    int b;     
    char c;    
};

int main() 
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    struct MixedStruct s;

    printf("=== Array Layout ===\n");
    printf("Size of entire array: %lu bytes\n", sizeof(arr));
    for (int i = 0; i < 6; i++) {
        printf("Address of arr[%d]: %p\n", i,&arr[i]);
    }

    printf("\n=== Structure Layout ===\n");
    printf("Size of struct: %lu bytes\n", sizeof(struct MixedStruct));
    printf("Address of s.a: %p\n", (void *)&s.a);
    printf("Address of s.b: %p\n", (void *)&s.b);
    printf("Address of s.c: %p\n", (void *)&s.c);

    return 0;
}
