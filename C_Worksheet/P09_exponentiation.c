/*Q09. Fast Exponentiation (Binary Method)---------------------------------------
Problem Statement:
 Compute base^exp using exponentiation by squaring with integer arithmetic*/
 #include <stdio.h>

// Function to compute base^exp using fast exponentiation (binary method)
long power(long base, long exp) 
{
    long result = 1;          // start with result = 1

    // Loop until exponent becomes 0
    while (exp > 0) 
    {
        if (exp & 1)          // if the current bit of exp is 1
            result *= base;   // multiply result by current base

        base *= base;         // square the base
        exp >>= 1;            // shift exponent right (divide by 2)
    }
    return result;            // final answer
}

int main() {
    // Test cases
    printf("2^10 = %ld\n", power(2,10));  // 1024
    printf("3^5 = %ld\n", power(3,5));    // 243
    printf("5^0 = %ld\n", power(5,0));    // 1
    return 0;
}
