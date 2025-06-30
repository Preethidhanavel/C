/*5.Dynamic Memory with Structures
Goal
Understand how to allocate and free memory dynamically for structures, including use cases like linked lists and memory pools in embedded systems.

Activity
Use malloc() to allocate a structure dynamically and assign values to members.
Build a simple singly linked list using structure and pointers.
Implement a queue using structure-based nodes.
Write a memory pool manager that uses an array of structures and a free list.
Tip: Always check malloc() return and release memory using free() after usage.*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define POOL_SIZE 10

typedef struct Node {
    int data;              
    struct Node* nextFree;  
} Node;

static Node memoryPool[POOL_SIZE];


static Node* freeListHead = NULL;


void pool_init() {
    for (int i = 0; i < POOL_SIZE - 1; ++i) {
        memoryPool[i].nextFree = &memoryPool[i + 1];
    }
    memoryPool[POOL_SIZE - 1].nextFree = NULL;

    freeListHead = &memoryPool[0];
}


Node* pool_alloc() {
    if (freeListHead == NULL) {
     
        return NULL;
    }

    Node* allocatedNode = freeListHead;
    freeListHead = freeListHead->nextFree;

    allocatedNode->nextFree = NULL; 
    return allocatedNode;
}


void pool_free(Node* node) {
    if (node == NULL) return;

    node->nextFree = freeListHead;
    freeListHead = node;
}

void print_free_list() {
    Node* current = freeListHead;
    printf("Free List: ");
    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->nextFree;
    }
    printf("NULL\n");
}


int main() {
    pool_init();
    print_free_list();

    Node* n1 = pool_alloc();
    Node* n2 = pool_alloc();
    if (n1) n1->data = 100;
    if (n2) n2->data = 200;

    printf("Allocated Node 1:  with data %d\n",   n1->data );
    printf("Allocated Node 2:  with data %d\n", n2->data );

    print_free_list();

    pool_free(n1);
    pool_free(n2);

    print_free_list();

    return 0;
}

