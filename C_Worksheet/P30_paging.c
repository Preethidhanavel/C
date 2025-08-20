/* Q30. Virtual Memory Paging (Toy Page Table)------------------------------------------
Problem Statement:
 Translate a virtual address to a physical pointer 
 using a simple page table; return NULL on page fault*/

#include <stdio.h>
#include<stdint.h>
#define PAGE_SIZE 4096  // Size of each page in bytes (4 KB)

// Page table maps virtual page numbers (0-3) to physical frame numbers
// -1 means the page is not mapped
int page_table[4] = {3, -1, 1, 2}; // VA pages 0→frame 3, 1→unmapped, 2→frame 1, 3→frame 2

// Function to translate a virtual address (va) to a physical address (pa)
void* translate(unsigned va) 
{
    int pg = va / PAGE_SIZE;        // Calculate the virtual page number
    int off = va % PAGE_SIZE;       // Calculate the offset within the page

    // If page is out of range or unmapped, return NULL
    if (pg < 0 || pg >= 4 || page_table[pg] == -1) return NULL;

    // Calculate the physical address: frame number * page size + offset
    unsigned pa = (unsigned)page_table[pg] * PAGE_SIZE + off;

    // Cast the physical address to void* for return
    return (void*)(uintptr_t)pa;
}

int main(void) 
{
    unsigned va = 0x00001234; // Virtual address in page 0
    printf("VA 0x%X -> PA %p\n", va, translate(va));

    va = 0x2000 + 0x55;       // Virtual address in page 2 (0x2000 = 8192)
    printf("VA 0x%X -> PA %p\n", va, translate(va));

    return 0;
}
