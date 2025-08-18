/*Pairwise Swap Nodes
Input: 1 → 2 → 3 → 4 → 5
Expected Output: 2 → 1 → 4 → 3 → 5*/
#include <stdio.h>
#include <stdlib.h>

typedef struct dll {
    int data;
    struct dll* next;
    struct dll* prev;
} dll;

dll* newdll(int data) 
{
    dll* temp = (dll*)malloc(sizeof(dll));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

dll* addend(dll* head, int data) 
{
    dll* temp = newdll(data);
    if (head == NULL)
        return temp;
    dll* curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
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

dll* pairwise_reverse(dll* head) 
{
    if (head == NULL) return NULL;

    dll* curr = head;

    while (curr != NULL && curr->next != NULL) 
    {
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;

        curr = curr->next->next;
    }

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

    head = pairwise_reverse(head);

    printf("reversed in pairs: ");
    printlist(head);

    return 0;
}
