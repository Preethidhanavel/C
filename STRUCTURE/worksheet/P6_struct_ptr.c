/*6.Structure Pointers and Memory Access
Goal
Understand the use of pointers to structures for efficient memory access and how to use the arrow operator for member access.

Activity
Declare a pointer to a structure and allocate memory using malloc().
Use arrow operator to assign and print structure member values.
Simulate memory-mapped peripheral access using structure pointers.
Illustrate how structure pointers simplify code in register programming.
Tip: Always initialize structure pointers and check for NULL before dereferencing.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint32_t CTRL;
    uint32_t STATUS;
    uint32_t DATA;
} Peripheral;

int main() 
{
    Peripheral* device = (Peripheral*)malloc(sizeof(Peripheral));
    if (device == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    device->CTRL = 0x01;
    device->STATUS = 0x0F;
    device->DATA = 0xABCD1234;

    printf("CTRL   = 0x%08X\n", device->CTRL);
    printf("STATUS = 0x%08X\n", device->STATUS);
    printf("DATA   = 0x%08X\n", device->DATA);

    Peripheral* PERIPHERAL_BASE = (Peripheral*)0x40000000;
    printf("Simulated peripheral base address: %p\n", PERIPHERAL_BASE);

    free(device);
    return 0;
}

