/*
 Loop Detection Challenges
Question:
Write a C program to detect and remove a loop.

Sample data:
List: 1 → 2 → 3 → 4 → 5 → (loop to 2)
 
Expected output:
Loop detected and removed.
List after removal: 1 2 3 4 5
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

void removeLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow == fast) {
        slow = head;
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } 
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
        printf("Loop removed\n");
    } 
    else {
        printf("No loop found\n");
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->prev = head;
    head->next->next = newNode(30);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(40);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = head->next;

    if (detectLoop(head)) {
        printf("Loop detected\n");
        removeLoop(head);
    } 
    else {
        printf("No loop detected\n");
    }

    printList(head);
    return 0;
}
