/* Q04. Custom Fixed-Size Block Allocator-------------------------------------
Problem Statement:
 Design a tiny allocator that manages N fixed-size blocks from a static array, 
 supporting allocate/free in O(1) average time*/

#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 16
#define NUM_BLOCKS 4

static unsigned char pool[NUM_BLOCKS][BLOCK_SIZE];
static int free_list[NUM_BLOCKS];
static int top = -1;

void init_allocator() 
{
    for (int i = 0; i < NUM_BLOCKS; i++) {
        free_list[++top] = i;
    }
}

void* my_alloc() 
{
    if (top < 0) 
        return NULL;
    return pool[free_list[top--]];
}

void my_free(void* ptr) 
{
    int index = ((unsigned char*)ptr - (unsigned char*)pool) / BLOCK_SIZE;
    free_list[++top] = index;
}

int main() 
{
    init_allocator();
    void* a = my_alloc();
    void* b = my_alloc();
    printf("Allocated block A at %p\n", a);
    printf("Allocated block B at %p\n", b);
    my_free(a);
    printf("Freed block A\n");
    void* c = my_alloc();
    printf("Allocated block C at %p (reused A)\n", c);
    return 0;
}
