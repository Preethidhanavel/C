/* Q48. Integer Square Root (Alternate)-----------------------------------
Problem Statement:
 Compute n using the restoring method (same idea as Q8; reinforce)*/

#include <stdio.h>

// Compute integer square root of n (floor of sqrt(n))
unsigned isqrt(unsigned n) 
{
    unsigned res = 0;            // Result (square root)
    unsigned bit = 1u << 30;     // Start with the highest power of four <= 2^31

    // Adjust 'bit' to the highest power of four <= n
    while (bit > n)
        bit >>= 2;

    // Main loop: try to build result bit by bit
    while (bit)
    {
        if (n >= res + bit) 
        {
            n -= res + bit;                  // Subtract this portion from n
            res = (res >> 1) + bit;         // Update result accordingly
        } 
        else 
        {
            res >>= 1;                      // Shift result right if subtraction not possible
        }
        bit >>= 2;                         // Move to next lower power of four
    }
    return res;                           // Return integer square root
}

int main() 
{
    // Test isqrt for values 0 to 20
    for (unsigned i = 0; i <= 20; i++)
        printf("%u -> %u\n", i, isqrt(i));

    return 0;
}
