/* Q47. Page Table Entry (Bitfields) Simulator------------------------------------------
Problem Statement:
 Model a PTE with present/rw/user/frame fields and print its decoded meaning*/

#include <stdio.h>

// Page Table Entry (PTE) structure using bitfields
struct PTE {
    unsigned present : 1;   // Present bit (1 bit)
    unsigned rw : 1;        // Read/Write permission bit (1 bit)
    unsigned user : 1;      // User/Supervisor bit (1 bit)
    unsigned frame : 29;    // Frame address (29 bits)
};

int main(void) {
    // Initialize a PTE with example values
    struct PTE e = { .present = 1, .rw = 1, .user = 0, .frame = 0x12345 };

    // Print the fields of the page table entry
    printf("P=%u RW=%u U=%u FRAME=%X\n", e.present, e.rw, e.user, e.frame);

    return 0;
}
