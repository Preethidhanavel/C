/*15. Block Reversal Variants
Question:
Write a C program to reverse nodes in blocks of size k.

Sample data:
List: 1 2 3 4 5 6
k = 3

Expected output:
Reversed: 3 2 1 6 5 4

*/


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
    if (!head) return temp;
    dll* cur = head;
    while (cur->next) cur = cur->next;
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

dll* reverseblock(dll* head, int k) 
{
    if (!head || k <= 1) 
      return head;
    dll *cur = head, *prev = NULL, *next = NULL;
    int cnt = 0;
    while (cur && cnt < k) 
    {
        next = cur->next;
        cur->next = prev;
        cur->prev = next;
        prev = cur;
        cur = next;
        cnt++;
    }
    if (next) 
    {
        head->next = reverseblock(next, k);
        if (head->next)
            head->next->prev = head;
    }
    return prev;
}

int main() 
{
    dll* head = NULL;
    int n, val, k;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    printf("enter node values:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        head = addend(head, val);
    }

    printf("enter block size k: ");
    scanf("%d", &k);

    head = reverseblock(head, k);

    printf("reversed: ");
    printlist(head);

    return 0;
}
