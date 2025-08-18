/* Halving the List Challenges
Question:
Write a C program to split a list into two halves.

Sample data:
List: 1 2 3 4 5 6

Expected output:
First half: 1 2 3
Second half: 4 5 6*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* addend(struct node* head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = temp->prev = NULL;
    if (head == NULL) return temp;
    struct node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

void printlist(struct node* head) {
    struct node* cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void splitList(struct node* head, struct node** first, struct node** second) {
    struct node* slow = head;
    struct node* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        if (fast) 
            slow = slow->next;
    }
    *first = head;
    *second = slow->next;
    if (*second) (*second)->prev = NULL;
    slow->next = NULL;
}

int main() 
{
    struct node* head = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
    int n, val;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the value node %d\n",i+1);
        scanf("%d", &val);
        head = addend(head, val);
    }

    splitList(head, &first, &second);

    printf("First half: ");
    printlist(first);

    printf("Second half: ");
    printlist(second);

    return 0;
}
