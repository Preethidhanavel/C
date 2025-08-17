/* Q08. Integer Square Root via Bit Manipulation--------------------------------------------
Problem Statement:
 Compute n for a non-negative integer without floating point operations*/

 #include <stdio.h>

// Function to compute integer square root of n
unsigned int isqrt(unsigned int n) 
{
    unsigned int res = 0;            // result (square root)
    unsigned int bit = 1 << 30;      // highest power of 4 <= 2^30

    // Reduce bit until it is <= n
    while (bit > n) 
        bit >>= 2;

    // Loop until all bits tested
    while (bit != 0) 
    {
        if (n >= res + bit) 
        {
            n -= res + bit;          // subtract trial divisor
            res = (res >> 1) + bit;  // update result
        } 
        else 
        {
            res >>= 1;               // shift result right
        }
        bit >>= 2;                   // move to next smaller power of 4
    }
    return res;
}

int main() 
{
    // Test values from 0 to 20
    for (int i = 0; i <= 20; i++) 
    {
        printf("isqrt(%d) = %u\n", i, isqrt(i));
    }
    return 0;
}
