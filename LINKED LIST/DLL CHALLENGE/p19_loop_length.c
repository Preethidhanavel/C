/*Find the Length of a Loop
Input: 1 → 2 → 3 → 4 → 2 (loop includes nodes 2, 3, 4)
Expected Output: Loop length is 3
*/


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

void addend(dll** head, int val) 
{
    dll* temp = newdll(val);
    if (*head == NULL) 
    {
        *head = temp;
        return;
    }
    dll* cur = *head;
    while (cur->next) 
    {
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
}

void detectloop(dll* head) 
{
    dll* slow = head;
    dll* fast = head;

    while (slow && fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) 
        {
            int length = 1;
            dll* temp = slow->next;
            while (temp != slow) 
            {
                length++;
                temp = temp->next;
            }
            printf("loop length is %d\n", length);
            return;
        }
    }
    printf("no loop found\n");
}

int main() 
{
    dll* head = NULL;

    addend(&head, 1);
    addend(&head, 2);
    addend(&head, 3);
    addend(&head, 4);
    addend(&head, 5);


    head->next->next->next->next->next = head->next;
    head->next->prev = head->next->next->next->next;

    detectloop(head);

    return 0;
}
