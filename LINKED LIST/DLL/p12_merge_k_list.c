/*12. Merging K Sorted Lists Challenges
Question:
Write a C program to merge K sorted linked lists.

Sample data:
List-1: 10 20 50
List-2: 30 40 60
List-3: 10 70 100

Expected output:
Merged list: 10 10 20 30 40 50 60 70 100*/


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

dll* mergetwodllists(dll* l1, dll* l2) 
{
    dll dummy;
    dll* tail = &dummy;
    dummy.next = NULL;
    dummy.prev = NULL;

    while (l1 != NULL && l2 != NULL) 
    {
        if (l1->data < l2->data) 
        {
            tail->next = l1;
            l1->prev = tail;
            l1 = l1->next;
        } 
        else 
        {
            tail->next = l2;
            l2->prev = tail;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    dll* rest = (l1 != NULL) ? l1 : l2;

    while (rest != NULL) 
    {
        tail->next = rest;
        rest->prev = tail;
        tail = tail->next;
        rest = rest->next;
    }

    if (dummy.next != NULL)
        dummy.next->prev = NULL;

    return dummy.next;
}

dll* mergekdllists(dll* lists[], int k) 
{
    if (k == 0)
        return NULL;
    while (k > 1) 
    {
        int i = 0;
        for (; i < k / 2; i++) 
        {
            lists[i] = mergetwodllists(lists[i], lists[k - 1 - i]);
        }
        k = (k + 1) / 2;
    }
    return lists[0];
}

int main() 
{
    int k;
    printf("enter number of lists: ");
    scanf("%d", &k);
    dll* lists[k];
    for (int i = 0; i < k; i++) 
    {
        lists[i] = NULL;
        int n;
        printf("enter number of elements in list %d: ", i + 1);
        scanf("%d", &n);
        printf("enter elements in sorted order:\n");
        for (int j = 0; j < n; j++) 
        {
            int val;
            scanf("%d", &val);
            lists[i] = addend(lists[i], val);
        }
    }

    dll* mergedlist = mergekdllists(lists, k);
    printf("merged list: ");
    printlist(mergedlist);

    return 0;
}
