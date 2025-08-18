/*20.How can structures be used to access hardware registers directly in embedded systems, and what are potential risks?*/


#include <stdint.h>
#include <stdio.h>

#define REG_ADDR 0x10000000

struct HWReg {
    volatile unsigned int ctrl;
    volatile unsigned int status;
};

#define HW ((struct HWReg *)REG_ADDR)

int main() {
    HW->ctrl = 0x01;
    unsigned int status = HW->status;
    printf("Control register set to: 0x%08X\n", HW->ctrl);
    printf("Status register read as: 0x%08X\n", status);
    return 0;
}
