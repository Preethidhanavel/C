/* Q32. Count Leading Zeros (CLZ) Without Intrinsic-----------------------------------------------
Problem Statement:
 Return the number of zero bits from the MSB down to the first 1*/

#include <stdio.h>

// Count Leading Zeros (clz) for a 32-bit unsigned integer
int clz(unsigned x) 
{
    if (x == 0) 
    return 32; // Special case: all bits are 0 → 32 leading zeros

    int c = 0; // Counter for leading zeros

    // Check bits from most significant bit (bit 31) to least (bit 0)
    for (int i = 31; i >= 0; i--) 
    {
        if (x & (1u << i)) 
            break; // If bit i is 1, stop
        c++;                      // Otherwise, increment count
    }

    return c; // Return the number of leading zeros
}

int main(void) {
    // Test the clz function with two values
    printf("clz(1)=%d, clz(0x10)=%d\n", clz(1), clz(0x10));
    return 0;
}
