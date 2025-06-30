/*
List Rotation Challenges
Question:
Write a C program to rotate a double linked list to the right by k places.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
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

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || k == 0)
        return head;

    int len = getLength(head);
    k = k % len;
    if (k == 0)
        return head;

    struct Node* tail = head;
    while (tail->next)
        tail = tail->next;

    struct Node* newTail = tail;
    for (int i = 0; i < k; i++)
        newTail = newTail->prev;

    struct Node* newHead = newTail->next;

    newTail->next = NULL;
    newHead->prev = NULL;

    tail->next = head;
    head->prev = tail;

    return newHead;
}

int main() {
    struct Node* head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 7);
    appendNode(&head, 9);

    int k = 2;

    printf("Original list: ");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated list: ");
    printList(head);

    return 0;
}
