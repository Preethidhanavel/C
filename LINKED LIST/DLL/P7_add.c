/*
 Linked List Addition Variants
Question:
Write a C program to add two numbers represented by double linked lists.

Sample data:
List 1: 8 7 9 2
List 2: 2 1 2 3
 
Expected output:
Result: 0 9 1 6 (carry handled)
*/

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

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void pushFront(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    if (*head)
        (*head)->prev = node;
    *head = node;
}

struct Node* getTail(struct Node* head) {
    if (!head) 
    return NULL;
    while (head->next)
        head = head->next;
    return head;
}

struct Node* addLists(struct Node* head1, struct Node* head2) {
    struct Node* tail1 = getTail(head1);
    struct Node* tail2 = getTail(head2);
    struct Node* result = NULL;
    int carry = 0;

    while (tail1 || tail2 || carry) {
        int sum = carry;

        if (tail1) {
            sum += tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2) {
            sum += tail2->data;
            tail2 = tail2->prev;
        }

        carry = sum / 10;
        pushFront(&result, sum % 10);
    }

    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    appendNode(&list1, 8);
    appendNode(&list1, 7);
    appendNode(&list1, 9);
    appendNode(&list1, 2);

    appendNode(&list2, 2);
    appendNode(&list2, 1);
    appendNode(&list2, 2);
    appendNode(&list2, 3);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* result = addLists(list1, list2);

    printf("Result: ");
    printList(result);

    return 0;
}
