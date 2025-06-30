/*Flatten a Multilevel Linked List
Input: 1 → 2 → 3, node 2’s child: 7 → 8, node 8’s child: 11
Expected Output: 1 → 2 → 7 → 8 → 11 → 3
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* child;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

struct Node* flattenList(struct Node* head) {
    if (!head) 
    return NULL;

    struct Node* curr = head;
    struct Node* stack[100];
    int top = -1;

    while (curr) {
        if (curr->child) {
            if (curr->next)
                stack[++top] = curr->next;

            curr->next = curr->child;
            curr->child = NULL;
        }

        if (!curr->next && top >= 0)
            curr->next = stack[top--];

        curr = curr->next;
    }

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    head->next->child = createNode(7);
    head->next->child->next = createNode(8);
    head->next->child->next->child = createNode(11);

    head = flattenList(head);
    printList(head);

    return 0;
}
