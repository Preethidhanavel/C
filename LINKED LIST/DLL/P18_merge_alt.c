/*18.Alternate Node Merging Challenges
Question:
Write a C program to merge alternate nodes of two linked lists.

Sample data:
List1: 9 7 5
List2: 10 8 6

Expected output:
Merged list: 9 10 7 8 5 6*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = temp->prev = NULL;
    return temp;
}

Node* addEnd(Node* head, int val) {
    Node* temp = newNode(val);
    if (!head) return temp;
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* interleaveLists(Node* l1, Node* l2) {
    Node* head = NULL, *tail = NULL;

    while (l1 && l2) {
        Node* n1 = l1;
        l1 = l1->next;
        n1->next = NULL;
        n1->prev = tail;
        if (tail) tail->next = n1;
        else head = n1;
        tail = n1;

        Node* n2 = l2;
        l2 = l2->next;
        n2->next = NULL;
        n2->prev = tail;
        tail->next = n2;
        tail = n2;
    }

    Node* remain = l1 ? l1 : l2;
while (remain) {
    remain->prev = tail;
    tail->next = remain;
    tail = remain;
    remain = remain->next;
}
tail->next = NULL;


    return head;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n1, n2, val;

    printf("Enter number of nodes in List1: ");
    scanf("%d", &n1);
    printf("Enter values for List1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        list1 = addEnd(list1, val);
    }

    printf("Enter number of nodes in List2: ");
    scanf("%d", &n2);
    printf("Enter values for List2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        list2 = addEnd(list2, val);
    }

    Node* merged = interleaveLists(list1, list2);

    printf("Merged list: ");
    printList(merged);

    return 0;
}
