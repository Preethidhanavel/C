/* Q33. Circular Queue w/o Modulo-----------------------------
Problem Statement:
Queue with indices that wrap to zero when reaching SIZE without using modulo operator*/

#include <stdio.h>

#define N 5               // Queue size (number of elements it can hold is N-1)

// Circular queue array and head/tail pointers
int q[N], head = 0, tail = 0;

// Compute the next index in circular manner
int next(int i) 
{ 
    return (i + 1 == N) ? 0 : (i + 1); 
}

// Enqueue value into the queue
int enq(int v) {
    int n = next(head);       // Compute next position
    if (n == tail) 
        return -1; // Queue is full
    q[head] = v;              // Store value at head
    head = n;                 // Move head forward
    return 0;                 // Success
}

// Dequeue value from the queue
int deq(int* v) 
{
    if (head == tail) 
        return -1; // Queue is empty
    *v = q[tail];                // Retrieve value at tail
    tail = next(tail);           // Move tail forward
    return 0;                    // Success
}

int main(void) 
{
    enq(1); // Queue: [1]
    enq(2); // Queue: [1, 2]

    int x;
    deq(&x); // Remove 1
    printf("%d\n", x); // Output: 1

    enq(3); // Queue: [2, 3]
    enq(4); // Queue: [2, 3, 4]
    enq(5); // Queue: [2, 3, 4, 5]

    // Try to enqueue when full → should fail
    printf("enq full=%d\n", enq(6)); // Output: enq full=-1

    // Dequeue remaining elements and print them
    while (deq(&x) == 0) 
        printf("%d ", x); // Output: 2 3 4 5
    puts(""); // Print newline

    return 0;
}
