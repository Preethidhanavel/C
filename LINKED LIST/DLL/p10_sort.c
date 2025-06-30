/*
10. Linked List Sorting Challenges
Question:
Write a C program to sort a double linked list using merge sort.

Sample data:
List: 2 3 1 7 5

Expected output:
Sorted list: 1 2 3 5 7*/



#include <stdio.h>
#include <stdlib.h>

typedef struct dll {
    int data;
    struct dll* prev;
    struct dll* next;
} dll;

void addend(dll** head, int data) 
{
    dll* newnode = (dll*)malloc(sizeof(dll));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (*head == NULL) 
    {
        *head = newnode;
        return;
    }

    dll* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void printlist(dll* head) 
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

dll* split(dll* head) 
{
    dll* slow = head;
    dll* fast = head;

    while (fast->next && fast->next->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    dll* second = slow->next;
    slow->next = NULL;
    if (second) second->prev = NULL;
    return second;
}

dll* merge(dll* first, dll* second) 
{
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->data <= second->data) 
    {
        first->next = merge(first->next, second);
        if (first->next)
            first->next->prev = first;
        first->prev = NULL;
        return first;
    } 
    else 
    {
        second->next = merge(first, second->next);
        if (second->next)
            second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

dll* mergesort(dll* head) 
{
    if (!head || !head->next)
        return head;

    dll* second = split(head);
    head = mergesort(head);
    second = mergesort(second);

    return merge(head, second);
}

int main() 
{
    dll* head = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter list elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        addend(&head, value);
    }

    head = mergesort(head);

    printf("Sorted list: ");
    printlist(head);

    return 0;
}
