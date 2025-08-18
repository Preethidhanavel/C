/*Remove N-th Node from End
Input: 1 → 2 → 3 → 4 → 5, n = 2
Expected Output: 1 → 2 → 3 → 5*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->prev = node->next = NULL;
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

Node* removeNthFromEnd(Node* head, int n) {
    Node *fast = head, *slow = head;
    for (int i = 0; i < n; i++) {
        if (!fast) return head;
        fast = fast->next;
    }
    if (!fast) {
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        free(temp);
        return head;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* toDelete = slow->next;
    slow->next = toDelete->next;
    if (toDelete->next)
        toDelete->next->prev = slow;
    free(toDelete);
    return head;
}

int main() {
    Node* head = NULL;
    int n, val, removeN;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = append(head, val);
    }
    scanf("%d", &removeN);
    head = removeNthFromEnd(head, removeN);
    printList(head);
    return 0;
}
