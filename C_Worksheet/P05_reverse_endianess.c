/* Q05. Reverse Endianness of a 32-bit Integer------------------------------------------
Problem Statement:
 Convert a 32-bit value between little-endian and big-endian byte orders.*/
 
#include <stdio.h>
#include <stdint.h>

// Function to reverse the byte order (endian swap)
uint32_t reverse_endian(uint32_t x) {
    return ((x >> 24) & 0xFF) |        // move byte 4 to byte 1
           ((x >> 8)  & 0xFF00) |      // move byte 3 to byte 2
           ((x << 8)  & 0xFF0000) |    // move byte 2 to byte 3
           ((x << 24) & 0xFF000000);   // move byte 1 to byte 4
}

int main() {
    uint32_t val = 0x12345678;   // sample value
    // print original and reversed endian values
    printf("Original: 0x%X, Reversed: 0x%X\n", val, reverse_endian(val));
    return 0;
}
