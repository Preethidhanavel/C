/* Q02. Count 1s in Binary Using Lookup Table-----------------------------------------
Problem Statement:
 Count the number of 1-bits in a 32-bit unsigned integer using an 8-bit (256-entry) lookup table.*/

 #include <stdio.h>

unsigned char bit_count[256];

void init_table() {
    for (int i = 0; i < 256; i++) {
        bit_count[i] = (i & 1) + bit_count[i >> 1];
    }
}

int count_ones(unsigned int x) {
    return bit_count[x & 0xFF] +
           bit_count[(x >> 8) & 0xFF] +
           bit_count[(x >> 16) & 0xFF] +
           bit_count[(x >> 24) & 0xFF];
}

int main() {
    init_table();
    unsigned int x;
    scanf("%d",&x);
    printf("Number of 1s in %u = %d\n", x, count_ones(x));
    return 0;
}
