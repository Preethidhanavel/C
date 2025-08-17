/* Q43. memmove (Overlap-Safe Copy)-------------------------------
Problem Statement:
 Copy bytes between overlapping regions safely*/

#include <stdio.h>
#include <string.h>

//implementation of memmove
void* my_memmove(void* d, const void* s, size_t n) 
{
    unsigned char* D = d;           // Destination pointer (byte-wise)
    const unsigned char* S = s;     // Source pointer (byte-wise)

    if (D < S) 
    {
        // If destination is before source, copy forwards
        // No overlap issue moving front-to-back
        for (size_t i = 0; i < n; i++)
            D[i] = S[i];
    } 
    else 
    {
        // If destination is after source, copy backwards
        // To avoid overwriting source data before copying it
        for (size_t i = n; i > 0; i--)
            D[i - 1] = S[i - 1];
    }

    return d; // Return destination pointer
}

int main() 
{
    char s[16] = "ABCDEFGH";

    // Move 6 bytes from s to s+2, overlapping copy
    my_memmove(s + 2, s, 6);

    // Print the result: expected "ABABCDEF"
    puts(s);

    return 0;
}
