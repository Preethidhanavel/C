/* Q39. Variable-Length Integer Encoding (Varint)---------------------------------------------
Problem Statement:
 Encode an unsigned integer using 7-bit groups with continuation bits.*/

#include <stdio.h>
#include <stdint.h>

// Encode a 32-bit unsigned integer 'v' into variable-length integer format
int encode_varint(uint32_t v, uint8_t* out) 
{
    int i = 0;
    // While more than 7 bits remain
    while (v >= 0x80) 
    {
        // Take lower 7 bits, set MSB to 1 to indicate continuation
        out[i++] = (v & 0x7F) | 0x80;
        v >>= 7; // Shift right by 7 bits to process next chunk
    }
    // Last byte: lower 7 bits with MSB=0 to indicate end
    out[i++] = v;
    return i; // Return total bytes written
}

int main() 
{
    uint8_t out[5];                // Output buffer 
    int n = encode_varint(300, out); // Encode the number 300

    // Print encoded bytes in hex
    for (int i = 0; i < n; i++)
        printf("%02X ", out[i]);
    puts(""); // Newline

    return 0;
}
