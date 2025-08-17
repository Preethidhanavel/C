/* Q28. Memcpy Optimized with 4-Byte Blocks---------------------------------------
Problem Statement:
 Copy n bytes favoring 32-bit word moves then tail bytes*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Custom memcpy implementation
void* my_memcpy(void* d, const void* s, size_t n) 
{
    // Work with 4-byte chunks first (for speed)
    uint32_t* D = d; 
    const uint32_t* S = s;

    // Copy while at least 4 bytes remain
    while (n >= 4) { 
        *D++ = *S++;   // copy 4 bytes at once
        n -= 4;        // reduce remaining count
    }

    // Handle leftover bytes (less than 4)
    unsigned char* d2 = (unsigned char*)D;
    const unsigned char* s2 = (const unsigned char*)S;
    while (n--) 
        *d2++ = *s2++;   // copy remaining bytes one by one

    return d;  // return destination pointer
}

int main() 
{
    char a[16] = "ABCDEFGH";   // source string
    char b[16] = {0};          // destination buffer

    // Copy 9 bytes ("ABCDEFGH" + '\0')
    my_memcpy(b, a, 9);

    // Print copied result
    printf("%s\n", b);

    return 0;
}
