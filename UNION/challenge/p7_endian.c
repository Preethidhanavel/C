/*If you use a union in a program that runs on different computer systems (like little-endian or big-endian CPUs), 
what kind of problems could happen when you try to use the same memory as different types?

union EndianTest {
    int i;
    char c[4];
};*/



#include <stdio.h>

union endian_test 
{
    int i;
    char c[4];
};

int main() {
    union endian_test e;
    e.i = 0x12345678;

    printf("Integer: 0x%x\n", e.i);
    printf("Bytes: %x %x %x %x\n", e.c[0], e.c[1], e.c[2], e.c[3]);

    if (e.c[0] == 0x78)
        printf("Little-endian system\n");
    else if (e.c[0] == 0x12)
        printf("Big-endian system\n");
    
}
