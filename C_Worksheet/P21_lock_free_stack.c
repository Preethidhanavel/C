/* Q21. Lock-Free Stack (CAS)-------------------------
Problem Statement:
 Implement push/pop on a singly-linked stack using atomic compare-and-swap*/

#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>

// Node structure for stack
typedef struct Node { 
    int v;                 // value stored
    struct Node* next;     // pointer to next node
} Node;

// Atomic pointer to top of stack (shared)
_Atomic(Node*) top = NULL;

// Push operation (lock-free)
void push(Node* n) 
{
    Node* old;
    do {
        old = atomic_load(&top);   // read current top
        n->next = old;             // new node points to old top
    } while (!atomic_compare_exchange_weak(&top, &old, n));
}

// Pop operation (lock-free)
Node* pop(void) {
    Node* old;
    do {
        old = atomic_load(&top);   // read current top
        if (!old) 
            return NULL;     // stack empty
    } while (!atomic_compare_exchange_weak(&top, &old, old->next));
    return old;                    // return popped node
}

int main() 
{
    for (int i = 0; i < 3; i++) 
    {
        Node* n = malloc(sizeof(*n));
        n->v = i;
        push(n);
    }

    // Pop all nodes until stack is empty
    for (Node* p; (p = pop()); ) 
    {
        printf("pop %d\n", p->v);
        free(p);
    }

    return 0;
}
