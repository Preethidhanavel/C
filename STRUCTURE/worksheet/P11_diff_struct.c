/*11.Memory Layout of Structures
Goal
Analyze the internal memory layout of structures, including padding, alignment, and impact on memory optimization.

Activity
Define a structure and use sizeof() to observe unexpected sizes.
Use different data type orderings and compare structure size.
Simulate structure layout for peripheral memory mapping.
Apply structure packing using #pragma and compare memory efficiency.
Tip: Misaligned structures can cause performance hits on some architectures.*/
#include <stdio.h>

typedef struct {
    char a;
    int b;
    char c;
} StructA;

typedef struct {
    char a;
    char c;
    int b;
} StructB;

#pragma pack(1)
typedef struct {
    char a;
    int b;
    char c;
} PackedStruct;
#pragma pack()

typedef struct {
    volatile unsigned int CR;
    volatile unsigned short SR;
    volatile unsigned char DR;
    volatile unsigned char RESERVED;
} Peripheral;

int main() {
    StructA s1;
    StructB s2;
    PackedStruct s3;
    Peripheral p;

    printf("Size of StructA (default layout): %zu\n", sizeof(s1));
    printf("Size of StructB (optimized order): %zu\n", sizeof(s2));
    printf("Size of PackedStruct (#pragma pack(1)): %zu\n", sizeof(s3));
    printf("Size of Peripheral (register layout): %zu\n", sizeof(p));

    return 0;
}
