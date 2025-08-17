/* Q10. Detect Loop in a Singly Linked List (Floyd’s Cycle)-------------------------------------------------------
Problem Statement:
 Given the head of a singly linked list, detect if a cycle exists using O(1) extra space*/

 #include <stdio.h>
#include <stdlib.h>

// Definition of a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node with given data
struct Node* newNode(int data) 
{
    struct Node* n = malloc(sizeof(struct Node)); // allocate memory
    n->data = data;       // store value
    n->next = NULL;       // no next yet
    return n;
}

// Detect cycle in linked list using Floyd’s cycle-finding algorithm
int has_cycle(struct Node* head) 
{
    struct Node *slow = head, *fast = head;

    // Move fast by 2 steps and slow by 1 step
    while (fast && fast->next) {
        slow = slow->next;            // move slow by 1
        fast = fast->next->next;      // move fast by 2

        if (slow == fast)             // if they meet → cycle exists
            return 1;
    }
    return 0; // reached end → no cycle
}

int main()
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);

    // Create cycle: last node points back to node 2
    head->next->next->next = head->next;

    // Detect cycle
    if (has_cycle(head))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}

