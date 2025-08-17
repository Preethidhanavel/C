/* Q29. Reverse Singly Linked List (Recursion, No Loops)----------------------------------------------------
Problem Statement:
 Reverse a singly linked list using recursion only*/

#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the linked list
typedef struct Node {
    int v;             // Value stored in the node
    struct Node* next; // Pointer to the next node
} Node;

// Function to push a new node with value v onto the front of the list
Node* push(Node* h, int v) 
{
    Node* n = malloc(sizeof(*n)); // Allocate memory for new node
    n->v = v;                     // Set the node's value
    n->next = h;                  // Link the new node to the current head
    return n;                     // Return new head of the list
}

// Recursive function to reverse the linked list
Node* rev(Node* h) 
{
    if (!h || !h->next) return h;     // Base case: empty list or single node
    Node* nh = rev(h->next);          // Reverse the rest of the list
    h->next->next = h;                // Make next node point back to current node
    h->next = NULL;                   // Break the original forward link
    return nh;                        // Return new head of the reversed list
}

int main() 
{
    Node* h = NULL;

    // Push values 1 to 4 onto the list: list becomes 4 -> 3 -> 2 -> 1
    for (int i = 1; i <= 4; i++) h = push(h, i);

    // Reverse the list: becomes 1 -> 2 -> 3 -> 4
    h = rev(h);

    // Print the reversed list
    for (Node* p = h; p; p = p->next) printf("%d ", p->v);
    puts(""); // Newline after printing the list

    return 0;
}
