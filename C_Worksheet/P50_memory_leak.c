/*Q50. Memory Leak Tracker (Simple)--------------------------------
Problem Statement:
 Track outstanding allocations to report leaks at program end*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure to track allocated memory blocks
typedef struct {
    void* p;      // Pointer to allocated memory
    size_t sz;    // Size of the allocation
} Entry;

static Entry tab[128];  // Table to store up to 128 memory allocations
static int cnt = 0;     // Current number of active allocations

// Custom malloc that tracks allocations
void* my_malloc(size_t sz) 
{
    void* p = malloc(sz);                         // Allocate memory
    if (p && cnt < 128) 
    {                         // If allocation successful and space in table
        tab[cnt].p = p;                           // Store pointer
        tab[cnt].sz = sz;                         // Store size
        cnt++;                                    // Increment allocation count
    }
    return p;
}

// Custom free that removes pointer from tracking table
void my_free(void* p) 
{
    for (int i = 0; i < cnt; i++) 
    {
        if (tab[i].p == p) 
        {                      // Found matching allocation
            free(p);                              // Free the memory
            tab[i] = tab[--cnt];                  // Replace with last entry, reduce count
            return;
        }
    }
}

// Report all memory leaks (unfreed allocations)
void report_leaks(void) 
{
    for (int i = 0; i < cnt; i++)
        printf("LEAK %p size %zu\n", tab[i].p, tab[i].sz);
}

int main() 
{
    int* a = my_malloc(4);  *a = 10;              // Allocate and use memory
    char* b = my_malloc(10);                      // Allocate another block (will leak)

    my_free(a);                                   // Properly free 'a'

    report_leaks();                               // Should report 'b' as a leak

    return 0;
}
