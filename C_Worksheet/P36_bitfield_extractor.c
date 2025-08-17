/* Q36. Byte-Aligned Bitfield Extractor-----------------------------------
Problem Statement:
 Extract bit_length bits starting at start_bit from a big-endian bit buffer*/

#include <stdio.h>
#include <stdint.h>

// Extract 'len' bits starting from bit position 'start' in the byte array 'b'
uint32_t extract(const uint8_t* b, int start, int len) 
{
    uint32_t r = 0; // Result accumulator

    for (int i = 0; i < len; i++) 
    {
        int bit = start + i;         // Absolute bit index
        int by = bit / 8;            // Byte index
        int pos = 7 - (bit % 8);     // Bit position within the byte (MSB is position 7)

        // Shift result left and add current bit (0 or 1)
        r = (r << 1) | ((b[by] >> pos) & 1);
    }

    return r; // Final extracted value
}

int main() 
{   
    uint8_t buf[] = {0b10110110, 0b01001100}; // Bits numbered 0 to 15
    printf("%u\n", extract(buf, 3, 6)); // Expected binary: 101100 → decimal: 44

    return 0;
}

