/* Q27. Detect Integer Multiplication Overflow------------------------------------------
Problem Statement:
 Determine if a*b overflows 32-bit signed int, and if not, return the product*/

#include <stdio.h>
#include <limits.h>

// Safe multiply function
int safe_mul(int a, int b, int* out) 
{
    // Perform multiplication in a larger type (long long)
    long long p = (long long)a * b;

    // Check if result fits in 32-bit int
    if (p > INT_MAX || p < INT_MIN)
        return -1;   // overflow occurred

    *out = (int)p;   // store safe result
    return 0;        // success
}

int main() 
{
    int r;

    // Normal multiplication (fits in int range)
    printf("7*8 ok? %d, val=%d\n", safe_mul(7, 8, &r), r);

    // Overflow example (exceeds int max)
    printf("INT_MAX*2 ok? %d\n", safe_mul(INT_MAX, 2, &r));

    return 0;
}
