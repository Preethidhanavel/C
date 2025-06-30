/*Sort a Linked List
Input: 3 → 1 → 5 → 2 → 4
Expected Output: 1 → 2 → 3 → 4 → 5*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}

Node* append(Node* head, int data) {
    Node* temp = newNode(data);
    if (!head) return temp;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = temp;
    temp->prev = tail;
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* insertionSort(Node* head) {
    if (!head) 
    return NULL;
    Node* sorted = NULL;

    while (head) {
        Node* cur = head;
        head = head->next;
        cur->prev = cur->next = NULL;

        if (!sorted) {
            sorted = cur;
        } 
        else if (cur->data < sorted->data) {
            cur->next = sorted;
            sorted->prev = cur;
            sorted = cur;
        } 
        else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < cur->data) {
                temp = temp->next;
            }
            cur->next = temp->next;
            if (temp->next) temp->next->prev = cur;
            temp->next = cur;
            cur->prev = temp;
        }
    }
    return sorted;
}

int main() {
    Node* head = NULL;
    int n, val;
    printf("Enter the number of node\n");
    scanf("%d", &n);
    printf("Enter the value of node\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = append(head, val);
    }

    head = insertionSort(head);
    printList(head);

    return 0;
}
