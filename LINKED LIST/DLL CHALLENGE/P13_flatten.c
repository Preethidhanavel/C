/*
Flatten a Multilevel double Linked List
Input: 1 → 2 → 3, node 2’s child: 7 → 8, node 8’s child: 11
Expected Output: 1 → 2 → 7 → 8 → 11 → 3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
    struct Node* child;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    node->child = NULL;
    return node;
}

Node* flatten(Node* head) {
    Node* curr = head;
    while (curr) {
        if (curr->child) {
            Node* next = curr->next;
            Node* child = curr->child;
            curr->next = child;
            child->prev = curr;
            curr->child = NULL;
            Node* tail = child;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = next;
            if (next) {
                next->prev = tail;
            }
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* n1 = createNode(1);
    Node* n2 = createNode(2);
    Node* n3 = createNode(3);
    Node* n7 = createNode(7);
    Node* n8 = createNode(8);
    Node* n11 = createNode(11);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    n2->child = n7;
    n7->next = n8;
    n8->prev = n7;

    n8->child = n11;

    Node* flat = flatten(n1);
    printList(flat);

    return 0;
}
