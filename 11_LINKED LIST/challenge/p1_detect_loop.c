/*Detect a Loop
Input: 1 → 2 → 3 → 4 → 5 (node 5 points back to node 2)
Expected Output: Loop detected. Starting node of loop is 2*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* addend(struct node* head, int val) 
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) 
    return temp;
    struct node* cur = head;
    while (cur->next != NULL) 
       cur = cur->next;
    cur->next = temp;
    return head;
}

struct node* detectloopstart(struct node* head) 
{
    struct node *slow = head, *fast = head;
    while (slow && fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
        {
            struct node* ptr1 = head;
            struct node* ptr2 = slow;
            while (ptr1 != ptr2) 
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            printf("Loop detected. Starting node of loop is %d\n", ptr1->data);
            return ptr1;
        }
    }
    printf("No loop found.\n");
    return NULL;
}

int main() 
{
    struct node* head = NULL;

    head = addend(head, 1);
    head = addend(head, 2);
    head = addend(head, 3);
    head = addend(head, 4);
    head = addend(head, 5);

    head->next->next->next->next->next = head->next;  

    detectloopstart(head);

    return 0;
}
