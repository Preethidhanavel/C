/* Q20. Float  Binary (No Union)-----------------------------
Problem Statement:
 Render the IEEE-754 32-bit pattern of a float without using a union type*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Function to print the bit representation of a float
void float_to_bits(float f) 
{
    uint32_t u; 
    // Copy raw bytes of float into an unsigned int
    memcpy(&u, &f, 4);

    // Print all 32 bits from MSB to LSB
    for (int i = 31; i >= 0; i--) 
    {
        putchar((u >> i) & 1 ? '1' : '0'); // print '1' or '0'

        // Add spaces to separate sign | exponent | mantissa
        if (i == 31 || i == 23) 
            putchar(' ');
    }
    putchar('\n'); // newline after printing
}

int main() 
{
    float x = -13.25f; // test value
    printf("%f -> ", x);
    float_to_bits(x);  // show binary IEEE-754 representation
    return 0;
}

