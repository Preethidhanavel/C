/*Q24. CRC32 (0xEDB88320)----------------------
Problem Statement:
 Compute CRC32 over a byte buffer using the reflected polynomial 0xEDB88320*/

#include <stdio.h>
#include <stdint.h>

// Function to compute CRC32 checksum
uint32_t crc32(const unsigned char* d, size_t n) 
{
    uint32_t c = ~0u;   // start with all bits = 1 (0xFFFFFFFF)

    // Process each byte
    for (size_t i = 0; i < n; i++) 
    {
        c ^= d[i];  // XOR current byte into CRC
        for (int j = 0; j < 8; j++) 
        {
            // If LSB is 1 → apply polynomial, else just shift
            c = (c >> 1) ^ (0xEDB88320u & (-(int)(c & 1)));
        }
    }

    return ~c;  // Final XOR (invert bits)
}

int main() 
{
    const unsigned char s[] = "123456789";  // standard CRC test string
    printf("CRC32 = %08X\n", crc32(s, 9));  // compute and print CRC32
    return 0;
}
