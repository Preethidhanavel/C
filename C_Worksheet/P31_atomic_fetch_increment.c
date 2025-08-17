/*Q31. Atomic Fetch-and-Increment (x86 Inline ASM)-----------------------------------------------
Problem Statement:
 Atomically add 1 to *ptr and return the previous value*/

#include <stdio.h>
#include <stdatomic.h> // For atomic operations

// Declare a global atomic integer variable 'counter' initialized to 0
atomic_int counter = 0;

// Function to atomically fetch the current value and increment it by 1
int fetch_inc(atomic_int* p) 
{
    return atomic_fetch_add(p, 1); // Returns the old value before incrementing
}

int main() 
{
    // Atomically increment the counter and store the old value
    int old = fetch_inc(&counter);

    // Print the old and new values of the counter
    printf("old=%d new=%d\n", old, counter);

    return 0;
}
