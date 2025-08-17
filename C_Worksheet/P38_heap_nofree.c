/* Q38. Minimal Custom Heap (No Free)---------------------------------
Problem Statement:
 Implement a tiny heap with linear growth and no deallocation*/

#include <stdio.h>

#define HEAP 64                   // Define total heap size in bytes

static unsigned char h[HEAP];    // Static heap memory buffer
static int hp = 0;               // Heap pointer: next free byte index

// Simple allocator: allocate 'n' bytes from the heap
void* my_alloc(int n) 
{
    if (hp + n > HEAP)           // Check if enough space remains
        return NULL;             // Return NULL if out of memory

    void* p = &h[hp];            // Pointer to the start of allocated block
    hp += n;                     // Move heap pointer forward by n bytes
    return p;                    // Return allocated memory pointer
}

int main() 
{
    // Allocate space for an int and store 99
    int* a = my_alloc(sizeof(int));
    *a = 99;

    // Allocate space for 6 chars (a string "Hello" + null terminator)
    char* s = my_alloc(6);
    if (s) 
    {                     // Check allocation success
        s[0] = 'H';
        s[1] = 'e';
        s[2] = 'l';
        s[3] = 'l';
        s[4] = 'o';
        s[5] = 0;               // Null-terminate the string
    }

    // Print the stored int and string
    printf("%d %s\n", *a, s);

    return 0;
}
