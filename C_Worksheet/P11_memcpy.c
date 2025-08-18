/* Q11. memcpy with Overlap Handling (memmove semantics)----------------------------------------------------
Problem Statement:
 Copy n bytes from src to dest safely even if regions overlap*/

 #include <stdio.h>
#include <string.h>

// Copies 'n' bytes from src to dest, safe even if regions overlap
void* my_memcpy(void* dest, const void* src, size_t n) {
    unsigned char* d = dest;        // destination pointer (byte-wise)
    const unsigned char* s = src;   // source pointer (byte-wise)

    if (d < s) 
    { // Case 1: dest is before src -> safe to copy forward
        for (size_t i = 0; i < n; i++)
            d[i] = s[i];            // copy byte by byte forward
    } 
    else 
    {     // Case 2: dest is after src -> must copy backward
        for (size_t i = n; i > 0; i--)
            d[i-1] = s[i-1];        // copy from end to start
    }
    return dest; // return destination pointer
}

int main() 
{
    char str[20] = "ABCDEFGH";   // test string
    printf("Before: %s\n", str);
    my_memcpy(str+2, str, 4);

    printf("After copying: %s\n", str);
    return 0;
}
