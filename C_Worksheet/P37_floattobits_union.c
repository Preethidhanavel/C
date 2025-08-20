/* Q37. Float  IEEE-754 Bits (Union Method)----------------------------------------
Problem Statement:
 Show sign, exponent, fraction using a union type*/

#include <stdio.h>
#include <stdint.h>

// Union allows the same memory to be viewed as float or 32-bit integer
union FloatUnion {
    float f;       // store as float
    uint32_t u;    // view raw 32-bit binary
};

// Function to print IEEE-754 fields of a float
void print_float_bits(float num) 
{
    union FloatUnion fu;
    fu.f = num; // store number in union

    // Extract sign (1 bit: bit 31)
    uint32_t sign = (fu.u >> 31) & 0x1;

    // Extract exponent (8 bits: bits 30..23)
    uint32_t exponent = (fu.u >> 23) & 0xFF;

    // Extract fraction (23 bits: bits 22..0)
    uint32_t fraction = fu.u & 0x7FFFFF;

   printf("Sign     = %u\n", sign);
    printf("Exponent = %u (stored), unbiased = %d\n", exponent, (int)exponent - 127);
    printf("Fraction = 0x%06X\n", fraction);

    // Print full raw 32-bit binary (for clarity)
    printf("Raw bits = ");
    for (int i = 31; i >= 0; i--) {
        printf("%u", (fu.u >> i) & 1);
        if (i == 31 || i == 23) 
            printf(" "); // add space after sign & exponent
    }
    printf("\n\n");
}

int main() {
    // Test with some numbers
    print_float_bits(5.75f);     
    print_float_bits(-3.5f);     
    print_float_bits(0.15625f);  
    return 0;
}

