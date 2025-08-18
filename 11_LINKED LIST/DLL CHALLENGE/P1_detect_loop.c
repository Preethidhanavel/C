/*Detect a Loop
Input: 1 → 2 → 3 → 4 → 5 (node 5 points back to node 2)
Expected Output: Loop detected. Starting node of loop is 2*/
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

Node* detectLoopStart(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (!fast || !fast->next)
        return NULL;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() 
{
    Node* head = NULL;
    Node* loopNode = NULL;
    int n, val;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the value node %d\n",i+1);
        scanf("%d", &val);
        head = append(head, val);
        if (i == 1) loopNode = head;
    }

    Node* temp = head;
    while (temp->next) 
        temp = temp->next;
    temp->next = loopNode;
    if (loopNode) 
    loopNode->prev = temp;

    Node* start = detectLoopStart(head);
    if (start)
        printf("Loop detected. Starting node of loop is %d\n", start->data);
    else
        printf("No loop detected.\n");

    return 0;
}
