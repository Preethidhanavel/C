/*Remove Duplicates (Unsorted List)
Input: 1 → 2 → 3 → 2 → 1 → 4
Expected Output: 1 → 2 → 3 → 4*/


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

void removedup(dll* head) 
{
    dll* curr = head;
    while (curr) 
    {
        dll* runner = curr->next;
        while (runner) 
        {
            dll* next = runner->next;
            if (runner->data == curr->data) 
            {
                if (runner->prev) 
                {
                    runner->prev->next = runner->next;
                }
                if (runner->next) 
                {
                    runner->next->prev = runner->prev;
                }
                free(runner);
            }
            runner = next;
        }
        curr = curr->next;
    }
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
    removedup(head);
    printf("after removing duplicates: ");
    printlist(head);
    return 0;
}
