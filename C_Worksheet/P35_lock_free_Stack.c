/* Q35. Lock-Free Stack via CAS (Alternate)---------------------------------------
Problem Statement:
 Same goal as Q21; emphasize ABA hazard and mitigation (tagged pointers)*/

#include <stdio.h>
#include <stdatomic.h>
#include <stdint.h>

// Define a tagged pointer: contains a pointer + a tag (usually a version counter)
typedef struct {
    void* ptr;          // Actual pointer
    unsigned int tag;   // Tag or version number
} tagged_ptr;

// Declare an atomic tagged pointer (used as a shared head pointer)
_Atomic(tagged_ptr) head;

// Function to atomically compare and swap the global 'head'
int cas_head(tagged_ptr* expected, tagged_ptr desired) 
{
    // atomic_compare_exchange_strong:
    // If head == *expected, then head = desired and return 1 (true)
    // Else, *expected is updated with current value of head and return 0 (false)
    return atomic_compare_exchange_strong(&head, expected, desired);
}

int main(void) 
{
    // Initialize head to (NULL, 0)
    head = (tagged_ptr){ .ptr = NULL, .tag = 0 };

    // First CAS attempt: expected = current head, desired = (0x1, tag+1)
    tagged_ptr exp = head;
    tagged_ptr des = { .ptr = (void*)0x1, .tag = exp.tag + 1 };
    printf("CAS1 %s\n", cas_head(&exp, des) ? "ok" : "fail"); // Expected to succeed

    // Second CAS attempt: expected = current head, desired = (0x2, tag+1)
    exp = head; // Update expected to current head again
    des = (tagged_ptr){ .ptr = (void*)0x2, .tag = exp.tag + 1 };
    printf("CAS2 %s\n", cas_head(&exp, des) ? "ok" : "fail"); // Expected to succeed

    return 0;
}
