/*Q26. Fixed Pool Allocator (Bump Pointer)---------------------------------------
Problem Statement:
 Allocate sequentially from a fixed pool with no free; reset only*/

#include <stdio.h>
#include <stddef.h>

#define POOL 128                // total memory pool size (bytes)

// Static memory pool
static unsigned char mem[POOL]; 
static size_t off = 0;          // current allocation offset

// Allocate memory from pool (bump pointer allocation)
void* bump_alloc(size_t n) 
{
    if (off + n > POOL)         // check if enough space left
        return NULL;            // not enough memory

    void* p = &mem[off];        // pointer to free block
    off += n;                   // bump offset forward
    return p;                   // return allocated block
}

// Reset pool (frees everything at once)
void reset_pool(void) 
{
    off = 0;                    // reset offset to beginning
}

int main() 
{
    // Allocate an int and assign value
    int* a = bump_alloc(sizeof(int));
    *a = 42;

    // Allocate a string buffer and copy "HELLO"
    char* s = bump_alloc(6);
    for (int i = 0; i < 5; i++)
        s[i] = "HELLO"[i];
    s[5] = '\0';   // null-terminate string

    // Print stored values
    printf("*a=%d, s=%s\n", *a, s);

    // Reset the pool (all allocations freed at once)
    reset_pool();

    return 0;
}
