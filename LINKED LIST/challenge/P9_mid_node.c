/*
Find the Middle Node
Input: 1 → 2 → 3 → 4 → 5
Expected Output: 3
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

struct Node* findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() 
{
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    struct Node* middle = findMiddle(head);
    if (middle)
        printf("%d\n", middle->data);

    return 0;
}
