/*Q15. Multiply Using Bitwise Operations-------------------------------------
Problem Statement:
 Compute a*b using shifts and additions only*/
 
#include <stdio.h>

// Multiply two integers using shift-and-add method
int multiply(int a, int b) 
{
    int res = 0;   // result
    int neg = 0;   // track if result should be negative

    // Handle sign of 'a'
    if (a < 0) 
    { 
        a = -a;        // make positive
        neg = !neg;    // flip sign flag
    }

    // Handle sign of 'b'
    if (b < 0) 
    { 
        b = -b;        // make positive
        neg = !neg;    // flip sign flag
    }

    // Main loop: keep shifting b until it becomes 0
    while (b > 0) 
    {
        if (b & 1)          // if lowest bit of b is 1
            res += a;       // add current a to result
        a <<= 1;            // double 'a'
        b >>= 1;            // halve 'b'
    }

    // Apply sign if needed
    return neg ? -res : res;
}

int main() 
{
    // Test cases
    printf("7 * 6 = %d\n", multiply(7,6));    // 42
    printf("13 * 0 = %d\n", multiply(13,0));  // 0
    printf("-3 * 5 = %d\n", multiply(-3,5));  // -15
    return 0;
}
