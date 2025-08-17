/* Q45. SPSC Lock-Free Ring Queue
-----------------------------
Problem Statement:
 Single-producer/single-consumer integer queue with head/tail indices updated by owner only.*/

#include <stdio.h>
#include <stdatomic.h>

#define QSZ 8                 // Queue size (capacity)
int q[QSZ];                   // Circular buffer array
atomic_int head = 0, tail = 0; // Atomic indices for head (enqueue) and tail (dequeue)

// Enqueue value v into the queue
// Returns 0 on success, -1 if queue is full
int enq(int v) 
{
    int h = atomic_load_explicit(&head, memory_order_relaxed);          // Load current head index
    int n = (h + 1) % QSZ;                                              // Calculate next head position (wrap-around)

    // Check if queue is full: next head equals tail
    if (n == atomic_load_explicit(&tail, memory_order_acquire))
        return -1; // Queue full, cannot enqueue

    q[h] = v;                                                          // Store value at current head
    atomic_store_explicit(&head, n, memory_order_release);            // Update head index to next position
    return 0;
}

// Dequeue value from the queue into *v
// Returns 0 on success, -1 if queue is empty
int deq(int* v) 
{
    int t = atomic_load_explicit(&tail, memory_order_relaxed);         // Load current tail index

    // Check if queue is empty: tail equals head
    if (t == atomic_load_explicit(&head, memory_order_acquire))
        return -1; // Queue empty, cannot dequeue

    *v = q[t];                                                         // Retrieve value at tail
    atomic_store_explicit(&tail, (t + 1) % QSZ, memory_order_release); // Update tail index to next position
    return 0;
}

int main() 
{
    // Enqueue values 0..4
    for (int i = 0; i < 5; i++)
        enq(i);

    int x;
    // Dequeue and print all values until queue is empty
    while (deq(&x) == 0)
        printf("%d ", x);
    puts("");

    return 0;
}
