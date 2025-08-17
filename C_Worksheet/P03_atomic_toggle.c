/* Q03. Atomic Toggle of a GPIO Bit (MMIO Register)-----------------------------------------------
Problem Statement:
 Safely toggle a specific GPIO bit in a memory-mapped I/O register without 
 race conditions during interrupts*/
 #include <stdio.h>
#include <stdint.h>

// simulate memory-mapped register
volatile uint32_t GPIO_REG = 0;
#define BIT (1 << 4)

void toggle_bit() {
    GPIO_REG ^= BIT; // XOR toggles
}

int main() {
    printf("Initial GPIO_REG = 0x%X\n", GPIO_REG);
    toggle_bit();
    printf("After toggle = 0x%X\n", GPIO_REG);
    toggle_bit();
    printf("After toggle again = 0x%X\n", GPIO_REG);
    return 0;
}
