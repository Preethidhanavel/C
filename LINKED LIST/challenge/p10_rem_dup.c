/*Remove Duplicates (Unsorted List)
Input: 1 → 2 → 3 → 2 → 1 → 4
Expected Output: 1 → 2 → 3 → 4*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void addend(struct node** head, int val) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
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

void printlist(struct node* head) 
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void removedup(struct node* head) 
{
    struct node* curr = head;
    while (curr != NULL) 
    {
        struct node* runner = curr;
        while (runner->next != NULL) 
        {
            if (runner->next->data == curr->data) 
            {
                struct node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } 
            else 
            {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

int main() 
{
    struct node* head = NULL;
    int n, val;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        addend(&head, val);
    }

    printlist(head);
    removedup(head);
    printlist(head);

    return 0;
}
