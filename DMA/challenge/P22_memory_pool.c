/*How could you build a simple memory pool using a fixed-size array in C? 
How would you write your own versions of malloc and free using this pool?*/
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 32
#define POOL_SIZE 1024

static unsigned char memory_pool[POOL_SIZE];
static void *free_list = NULL;

void pool_init() {
    size_t num_blocks = POOL_SIZE / BLOCK_SIZE;
    free_list = memory_pool;

    for (size_t i = 0; i < num_blocks - 1; ++i) {
        void *current = memory_pool + i * BLOCK_SIZE;
        void *next = memory_pool + (i + 1) * BLOCK_SIZE;
        *(void **)current = next;
    }

    void *last = memory_pool + (num_blocks - 1) * BLOCK_SIZE;
    *(void **)last = NULL;
}

void *pool_malloc() {
    if (!free_list) {
        return NULL;
    }

    void *block = free_list;
    free_list = *(void **)free_list;
    return block;
}

void pool_free(void *ptr) {
    if (!ptr || ptr < (void *)memory_pool || ptr >= (void *)(memory_pool + POOL_SIZE)) {
        return;
    }

    *(void **)ptr = free_list;
    free_list = ptr;
}

int main() {
    pool_init();

    void *a = pool_malloc();
    void *b = pool_malloc();
    void *c = pool_malloc();

    printf("Allocated: %p %p %p\n", a, b, c);

    pool_free(b);
    pool_free(a);
    pool_free(c);

    void *d = pool_malloc();
    void *e = pool_malloc();

    printf("Reallocated: %p %p\n", d, e);

    return 0;
}
