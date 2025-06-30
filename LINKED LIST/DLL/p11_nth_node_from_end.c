/*11. Nth Node from End Variants
Question:
Write a C program to retrieve the nth node from the end.

Sample data:
List: 1 3 5 11
n = 3

Expected output:
Result: 3*/

#include <stdio.h>
#include <stdlib.h>

typedef struct dll {
    int data;
    struct dll* prev;
    struct dll* next;
} dll;


dll* addend(dll* head, int data) 
{
    dll* newnode = (dll*)malloc(sizeof(dll));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) 
    {
        newnode->prev = NULL;
        return newnode;
    }

    dll* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
    return head;
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

dll* nth_from_end(dll* head, int n) 
{
    dll* tail = head;

    if (tail == NULL) return NULL;

    while (tail->next != NULL) 
    {
        tail = tail->next;
    }

    for (int i = 1; i < n; i++) 
    {
        if (tail->prev == NULL) 
        {
            return NULL;
        }
        tail = tail->prev;
    }

    return tail;
}

int main() 
{
    dll* head = NULL;
    int size, data, n;

    printf("enter number of nodes\n");
    scanf("%d", &size);

    printf("enter data for nodes\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &data);
        head = addend(head, data);
    }

    printf("enter n\n");
    scanf("%d", &n);

    printf("List: ");
    printlist(head);

    dll* result = nth_from_end(head, n);
    if (result != NULL)
        printf("Result: %d\n", result->data);
    else
        printf("List is shorter than %d elements.\n", n);

    return 0;
}
