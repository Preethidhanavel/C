/*Q16. Bit Rotations (Left & Right)--------------------------------
Problem Statement:
 Rotate bits of a 32-bit value by d positions*/

#include <stdio.h>
#include <stdint.h>

// Rotate left: move bits left and bring shifted-out bits back to right
uint32_t rol(uint32_t x, int d) 
{ 
    d &= 31;                        // limit shift to 0–31
    return (x << d) | (x >> (32 - d));
}

// Rotate right: move bits right and bring shifted-out bits back to left
uint32_t ror(uint32_t x, int d) 
{ 
    d &= 31;                        // limit shift to 0–31
    return (x >> d) | (x << (32 - d));
}

int main(void) 
{

    uint32_t v = 0x12345678;        // test value

    // Rotate left by 8 bits
    printf("ROL(%08X, 8) = %08X\n", v, rol(v,8));

    // Rotate right by 8 bits
    printf("ROR(%08X, 8) = %08X\n", v, ror(v,8));

    return 0;
}

