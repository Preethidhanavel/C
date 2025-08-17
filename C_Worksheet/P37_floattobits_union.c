/* Q37. Float  IEEE-754 Bits (Union Method)----------------------------------------
Problem Statement:
 Show sign, exponent, fraction using a union type*/

#include <stdio.h>
#include <stdint.h>

// Define a union to view the same memory as either a float or a 32-bit unsigned int
union U {
    float f;       // Floating-point view
    uint32_t u;    // Unsigned int view (bit-level)
};

int main() 
{
    union U v;
    v.f = 3.5f; // Assign a float value
    printf("%08X\n", v.u); 

    return 0;
}
