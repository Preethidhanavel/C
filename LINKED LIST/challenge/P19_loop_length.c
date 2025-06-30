/*
Find the Length of a Loop
Input: 1 → 2 → 3 → 4 → 2 (loop includes nodes 2, 3, 4)
Expected Output: Loop length is 3
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

int findLoopLength(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int count = 1;
            struct Node* temp = slow;
            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0;
}

int main() 
{
    struct Node* head = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    int loopLength = findLoopLength(head);
    if (loopLength)
        printf("Loop length is %d\n", loopLength);
    else
        printf("No loop found\n");

    return 0;
}
