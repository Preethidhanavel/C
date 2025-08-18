/*Adjacent Node Swapping Variants
Question:
Write a C program to swap every two adjacent nodes.

Sample data:
List: 1 2 3 4 5

Expected output:
Swapped list: 2 1 4 3 5*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

Node* append(Node* head, int data) {
    Node* node = newNode(data);
    if (!head) return node;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    node->prev = temp;
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* swapPairs(Node* head) {
    if (!head || !head->next)
        return head;

    Node* dummy = newNode(0);
    dummy->next = head;
    head->prev = dummy;

    Node* cur = dummy;

    while (cur->next && cur->next->next) {
        Node* first = cur->next;
        Node* second = first->next;

        first->next = second->next;
        if (second->next)
            second->next->prev = first;

        second->prev = cur;
        second->next = first;

        first->prev = second;
        cur->next = second;

        cur = first;
    }

    head = dummy->next;
    head->prev = NULL;
    free(dummy);
    return head;
}

int main() {
    Node* head = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = append(head, val);
    }

    printf("Original list:\n");
    printList(head);

    head = swapPairs(head);

    printf("Swapped list:\n");
    printList(head);

    return 0;
}
