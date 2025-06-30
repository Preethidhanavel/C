/*3. Working with Const and Volatile Pointers
Goal: Demonstrate how const and volatile qualifiers affect pointer behavior in hardware register access.
Activity: 
Define a dummy hardware register address using #define:
#define REG_BASE 0x40000000
Declare pointers with different qualifiers:
1.volatile uint32_t *reg_modifiable = (uint32_t *)REG_BASE;
2.const uint32_t *reg_readonly = (const uint32_t *)REG_BASE;
3.const volatile uint32_t *reg_const_volatile = (const volatile uint32_t *)REG_BASE;

Attempt to write to and read from each pointer and note compiler behavior.*/



#include<stdio.h>
#include <stdint.h>

#define REG_BASE 0x40000000

void main() 
{
    volatile uint32_t *reg_modifiable = (uint32_t *)REG_BASE;
    const uint32_t *reg_readonly = (const uint32_t *)REG_BASE;
    const volatile uint32_t *reg_const_volatile = (const volatile uint32_t *)REG_BASE;


    *reg_modifiable=0x123456;
    uint32_t val1 = *reg_modifiable;
    //*reg_readonly = 0xABCD1234; //compile time error
    uint32_t val2 = *reg_readonly; 

    //*reg_const_volatile = 0x87654321; //compile time error
    uint32_t val3 = *reg_const_volatile; 
}



