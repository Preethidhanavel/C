/* Q04. Custom Fixed-Size Block Allocator-------------------------------------
Problem Statement:
 Design a tiny allocator that manages N fixed-size blocks from a static array, 
 supporting allocate/free in O(1) average time*/

#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 16      // Each block is 16 bytes
#define NUM_BLOCKS 4       // Total 4 blocks available

// Memory pool: 4 blocks, each of size 16 bytes
static unsigned char pool[NUM_BLOCKS][BLOCK_SIZE];

// Stack-like free list to track available blocks
static int free_list[NUM_BLOCKS];
static int top = -1;       // Index of the top of the free list stack

// Initialize allocator: push all block indices onto free_list
void init_allocator() 
{
    for (int i = 0; i < NUM_BLOCKS; i++) {
        free_list[++top] = i;   // Store block index into free_list
    }
}

// Allocate one block (if available)
void* my_alloc() 
{
    if (top < 0)                 // No free blocks left
        return NULL;
    return pool[free_list[top--]]; // Return block and pop from free_list
}

// Free a block and push it back to free_list
void my_free(void* ptr) 
{
    // Find index of block within pool
    int index = ((unsigned char*)ptr - (unsigned char*)pool) / BLOCK_SIZE;
    free_list[++top] = index;   // Push block back onto free_list
}

int main() 
{
    init_allocator();               // Initialize allocator

    void* a = my_alloc();           // Allocate first block
    void* b = my_alloc();           // Allocate second block
    printf("Allocated block A at %p\n", a);
    printf("Allocated block B at %p\n", b);

    my_free(a);                     // Free first block
    printf("Freed block A\n");

    void* c = my_alloc();           // Allocate again (reuses freed block)
    printf("Allocated block C at %p (reused A)\n", c);

    return 0;
}
