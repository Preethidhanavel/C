/*5.Structure Padding and Packed Attributes
Goal: Analyze memory layout and size differences of structs with and without packing for peripheral registers.
Activity:
Define a structure containing char, int, and short fields:
struct PeripheralRegs {
  char status;
  int control;
  short error;
};
Print the total size of the structure and the offsets of each member using offsetof().
Redefine the structure with __attribute__((packed)) and compare sizes and offsets.*/

#include <stdio.h>
#include <stddef.h>

struct PeripheralRegs {
    char status;
    int control;
    short error;
};

struct PeripheralRegsPacked {
    char status;
    int control;
    short error;
} __attribute__((packed));

int main() 
{
    printf("Without packing:\n");
    printf("Size of PeripheralRegs: %zu bytes\n", sizeof(struct PeripheralRegs));
    printf("Offset of status: %zu\n", offsetof(struct PeripheralRegs, status));
    printf("Offset of control: %zu\n", offsetof(struct PeripheralRegs, control));
    printf("Offset of error: %zu\n", offsetof(struct PeripheralRegs, error));

    printf("\nWith packing:\n");
    printf("Size of PeripheralRegsPacked: %zu bytes\n", sizeof(struct PeripheralRegsPacked));
    printf("Offset of status: %zu\n", offsetof(struct PeripheralRegsPacked, status));
    printf("Offset of control: %zu\n", offsetof(struct PeripheralRegsPacked, control));
    printf("Offset of error: %zu\n", offsetof(struct PeripheralRegsPacked, error));

    return 0;
}
