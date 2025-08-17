/* Q46. Count Set Bits (Brian Kernighan)------------------------------------
Problem Statement:
Count 1s by repeatedly clearing the lowest set bit using n &= (n-1)*/

#include <stdio.h>

// Count number of set bits (1s) in unsigned integer x
int popcount(unsigned x) 
{
    int c = 0;              // Initialize count to zero
    while (x) 
    {
        x &= x - 1;         // Clear the least significant set bit
        c++;                // Increment count for each cleared bit
    }
    return c;               // Return total number of set bits
}

int main() 
{
    printf("%d\n", popcount(0xF0F0F0F0u)); // Output: 16
    return 0;
}
