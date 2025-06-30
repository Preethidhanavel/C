/*Move Last Element to Front
Input: 1 → 2 → 3 → 4 → 5
Expected Output: 5 → 1 → 2 → 3 → 4*/




#include <stdio.h>
#include <stdlib.h>

typedef struct dll {
    int data;
    struct dll* prev;
    struct dll* next;
} dll;

dll* newdll(int val) 
{
    dll* temp = (dll*)malloc(sizeof(dll));
    temp->data = val;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

dll* addend(dll* head, int val) 
{
    dll* temp = newdll(val);
    if (head == NULL) 
    {
        return temp;
    }
    dll* cur = head;
    while (cur->next) 
    {
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
    return head;
}

void printlist(dll* head) 
{
    while (head) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

dll* moveLastToFront(dll* head) 
{
    if (head == NULL) 
    {
        return head;
    }
    if (head->next == NULL) 
    {
        return head;
    }

    dll* last = head;
    while (last->next) 
    {
        last = last->next;
    }

    dll* secondLast = last->prev;
    secondLast->next = NULL;

    last->prev = NULL;
    last->next = head;
    head->prev = last;

    head = last;

    return head;
}

int main() 
{
    dll* head = NULL;
    int n, val;
    printf("enter number of nodes: ");
    scanf("%d", &n);
    printf("enter node values:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        head = addend(head, val);
    }

    head = moveLastToFront(head);

    printf("list after moving last to front: ");
    printlist(head);

    return 0;
}
