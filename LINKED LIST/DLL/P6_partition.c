/*
Partitioning with Dual Pivots
Question:
Write a C program to partition a linked list around a value x.

Sample data:
List: 3 5 7 5 9 2 1
x = 5

Expected output:
Reordered list: 3 2 1 5 7 5 9
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

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* partitionList(struct Node* head, int x) {
    struct Node *lessHead = NULL, *lessTail = NULL;
    struct Node *greaterHead = NULL, *greaterTail = NULL;

    while (head) {
        struct Node* next = head->next;
        head->prev = head->next = NULL;

        if (head->data < x) {
            if (!lessHead) {
                lessHead = lessTail = head;
            } 
            else {
                lessTail->next = head;
                head->prev = lessTail;
                lessTail = head;
            }
        } 
        else {
            if (!greaterHead) {
                greaterHead = greaterTail = head;
            } 
            else {
                greaterTail->next = head;
                head->prev = greaterTail;
                greaterTail = head;
            }
        }
        head = next;
    }

    if (!lessHead) 
    return greaterHead;

    lessTail->next = greaterHead;
    if (greaterHead)
        greaterHead->prev = lessTail;

    return lessHead;
}

int main() {
    struct Node* head = NULL;

    appendNode(&head, 3);
    appendNode(&head, 5);
    appendNode(&head, 7);
    appendNode(&head, 5);
    appendNode(&head, 9);
    appendNode(&head, 2);
    appendNode(&head, 1);

    int x = 5;

    printf("Original list: ");
    printList(head);

    head = partitionList(head, x);

    printf("Reordered list: ");
    printList(head);

    return 0;
}

