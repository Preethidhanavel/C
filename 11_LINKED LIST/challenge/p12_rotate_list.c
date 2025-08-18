/*Rotate Linked List
Input: 1 → 2 → 3 → 4 → 5, k = 2
Expected Output: 4 → 5 → 1 → 2 → 3*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void addend(struct node** head, int data) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL) 
    {
        *head = newnode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

int length(struct node* head) 
{
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}

struct node* rotateright(struct node* head, int k) 
{
    if (!head || !head->next || k == 0)
        return head;

    int len = length(head);
    k = k % len;
    if (k == 0) 
    return head;

    struct node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = head;

    int steps = len - k-1;
    struct node* newtail = head;
    for (int i = 1; i < steps; i++)
        newtail = newtail->next;

    struct node* newhead = newtail->next;
    newtail->next = NULL;

    return newhead;
}

void printlist(struct node* head) 
{
    struct node* temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    struct node* head = NULL;
    int n, val, k;
    printf("no of node:\n");
    scanf("%d", &n);

    printf("enter node data:");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        addend(&head, val);
    }

    printf("k:");
    scanf("%d", &k);

    head = rotateright(head, k);

    printlist(head);

    return 0;
}
