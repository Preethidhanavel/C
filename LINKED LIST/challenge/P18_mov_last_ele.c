/*
Move Last Element to Front
Input: 1 → 2 → 3 → 4 → 5
Expected Output: 5 → 1 → 2 → 3 → 4
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* moveLastToFront(struct Node* head) {
    if (!head || !head->next)
        return head;

    struct Node* secondLast = NULL;
    struct Node* last = head;

    while (last->next) {
        secondLast = last;
        last = last->next;
    }

    secondLast->next = NULL;
    last->next = head;
    head = last;

    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head = moveLastToFront(head);
    printList(head);

    return 0;
}
