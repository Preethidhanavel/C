/*4.Void Pointers and Memory Copying
Goal: Use void pointers to create a generic memory copying utility function for embedded data types.
Activity:
Declare a function mem_copy(void *dest, const void *src, size_t n) that copies n bytes from src to dest:
void mem_copy(void *dest, const void *src, size_t n);
Within the function, use char * pointers to copy data byte-by-byte.
Test the function by copying an array of integers and an array of floats.*/

#include <stdio.h>
#include <string.h>

void mem_copy(void *dest, const void *src, size_t n) 
{
    char *d = (char *)dest;
    const char *s = (const char *)src;
    for (size_t i = 0; i < n; i++) 
    {
        d[i] = s[i];
    }
}

int main() 
{
    int s[] = {1, 2, 3, 4, 5};
    int d[5];

    mem_copy(d, s, sizeof(s));

    printf("Copied int array:\n");
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", d[i]);
    }
    printf("\n");
    float src_float[] = {1.1, 2.2, 3.3, 4.4};
    float dest_float[4];

    mem_copy(dest_float, src_float, sizeof(src_float));

    printf("Copied float array:\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("%.1f ", dest_float[i]);
    }
    printf("\n");
}
