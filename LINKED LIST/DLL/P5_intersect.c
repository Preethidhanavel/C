/*
Intersection Finder Variants
Question:
Write a C program to find the intersection point of two doubly linked lists.

Sample data:
List A: 1 2 → 3 4
List B: 5 → 3 4

Expected output:
Intersection found at node with data: 3
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

int getLength(struct Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* findIntersection(struct Node* headA, struct Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    int diff = abs(lenA - lenB);

    if (lenA > lenB) {
        while (diff--) headA = headA->next;
    } 
    else {
        while (diff--) headB = headB->next;
    }

    while (headA && headB) {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}

int main() {
    struct Node* common1 = newNode(3);
    common1->next = newNode(4);
    common1->next->prev = common1;

    struct Node* headA = newNode(1);
    headA->next = newNode(2);
    headA->next->prev = headA;
    headA->next->next = common1;
    common1->prev = headA->next;

    struct Node* headB = newNode(5);
    headB->next = common1;
    common1->prev = headB;

    struct Node* intersection = findIntersection(headA, headB);
    if (intersection)
        printf("Intersection found at node with data: %d\n", intersection->data);
    else
        printf("No intersection found\n");

    return 0;
}
