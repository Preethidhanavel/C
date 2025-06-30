/*How do anonymous unions make your code easier to read or maintain? 
Can you give a simple example where an anonymous union inside a structure helps when working with hardware or communication data?*/
#include <stdio.h>

struct Register {
    unsigned int status;
    union {
        struct {
            unsigned int low;
            unsigned int high;
        };
        unsigned long long full;
    };
};

int main() {
    struct Register reg;

    reg.status = 1;
    reg.low = 0xAAAAAAAA;
    reg.high = 0xBBBBBBBB;

    printf("Status: %u\n", reg.status);
    printf("Low: 0x%X\n", reg.low);
    printf("High: 0x%X\n", reg.high);
    printf("Full (64-bit): 0x%llX\n", reg.full);

    reg.full = 0x1122334455667788ULL;

    printf("\nAfter writing to full:\n");
    printf("Low: 0x%X\n", reg.low);
    printf("High: 0x%X\n", reg.high);
    printf("Full (64-bit): 0x%llX\n", reg.full);

    return 0;
}

