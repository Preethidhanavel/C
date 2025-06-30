/*
 Kth Node Swapping Variants
Question:
Write a C program to swap Kth node from beginning and end in a double linked list 

Sample data:
List: 1 2 3 4 5
k = 2
Expected output:
Swapped list: 1 4 3 2 5
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void appendNode(struct Node** head, int data) {
    struct Node* node = newNode(data);
    if (!*head) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
    node->prev = temp;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void swapKthNodes(struct Node** headRef, int k) {
    int n = getLength(*headRef);
    if (k > n) 
    return;
    if (2 * k - 1 == n) 
    return;

    struct Node* first = *headRef;
    for (int i = 1; i < k; i++)
        first = first->next;

    struct Node* second = *headRef;
    for (int i = 1; i < n - k + 1; i++)
        second = second->next;

    if (first->prev)
        first->prev->next = second;
    if (first->next)
        first->next->prev = second;

    if (second->prev)
        second->prev->next = first;
    if (second->next)
        second->next->prev = first;

    struct Node* tempPrev = first->prev;
    struct Node* tempNext = first->next;

    first->prev = second->prev;
    first->next = second->next;

    second->prev = tempPrev;
    second->next = tempNext;

    if (k == 1)
        *headRef = second;
    if (k == n)
        *headRef = first;
}

int main() {
    struct Node* head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    int k = 2;

    printf("Original list: ");
    printList(head);

    swapKthNodes(&head, k);

    printf("Swapped list: ");
    printList(head);

    return 0;
}
