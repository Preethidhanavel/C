/*16.You're given a large memory block. You need to implement your own memory allocator using pointer arithmetic to simulate 
malloc() and free(). How do you track block sizes and free regions?*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 1024
#define COLS 64
#define MEM_SIZE (ROWS * COLS)

char memory[ROWS][COLS]; 

typedef struct BlockHeader {
    size_t size;
    int free;
    struct BlockHeader* next;
} BlockHeader;

BlockHeader* free_list = NULL;

void init_memory() {
    free_list = (BlockHeader*)memory;
    free_list->size = MEM_SIZE - sizeof(BlockHeader);
    free_list->free = 1;
    free_list->next = NULL;
}

void* my_malloc(size_t size) {
    BlockHeader* curr = free_list;
    while (curr) {
        if (curr->free && curr->size >= size) {
            if (curr->size >= size + sizeof(BlockHeader) + 1) {
                BlockHeader* new_block = (BlockHeader*)((char*)(curr + 1) + size);
                new_block->size = curr->size - size - sizeof(BlockHeader);
                new_block->free = 1;
                new_block->next = curr->next;

                curr->size = size;
                curr->next = new_block;
            }

            curr->free = 0;
            return (void*)(curr + 1); 
        }
        curr = curr->next;
    }
    return NULL; 
}

void my_free(void* ptr) 
{
    if (!ptr) 
        return;

    BlockHeader* block = (BlockHeader*)ptr - 1;
    block->free = 1;

    BlockHeader* curr = free_list;
    while (curr && curr->next) {
        if (curr->free && curr->next->free &&(char*)curr + sizeof(BlockHeader) + curr->size == (char*)curr->next) 
        {
          
            curr->size += sizeof(BlockHeader) + curr->next->size;
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

void print_blocks() 
{
    BlockHeader* curr = (BlockHeader*)memory;
    int i = 0;
    printf("Memory Blocks:\n");
    while ((char*)curr < (char*)memory + MEM_SIZE) {
        printf(" Block %d: Addr=%p, Size=%zu, Free=%d\n", i++, (void*)curr, curr->size, curr->free);
        if ((char*)curr + sizeof(BlockHeader) + curr->size >= (char*)memory + MEM_SIZE)
            break;
        curr = (BlockHeader*)((char*)curr + sizeof(BlockHeader) + curr->size);
    }
}

int main() 
{
    init_memory();

    void* p1 = my_malloc(100);
    void* p2 = my_malloc(200);
    void* p3 = my_malloc(150);

    printf("After allocations:\n");
    print_blocks();

    my_free(p2);
    my_free(p3);
    printf("\nAfter freeing p2:\n");
    print_blocks();

    void* p4 = my_malloc(180);
    printf("\nAfter allocating p4 (180 bytes):\n");
    print_blocks();

    return 0;
} 