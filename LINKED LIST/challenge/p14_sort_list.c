/*Sort a Linked List
Input: 3 → 1 → 5 → 2 → 4
Expected Output: 1 → 2 → 3 → 4 → 5*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void addend(struct node** head, int data) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
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
    struct node* temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sortlist(struct node* head) 
{
    if (head == NULL) return;

    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) 
        {
            if (ptr1->data > ptr1->next->data) 
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    struct node* head = NULL;
    int n, val;

    printf("number of nodes:\n");
    scanf("%d", &n);

    printf("enter node data:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        addend(&head, val);
    }

    sortlist(head);

    printf("sorted list: ");
    printlist(head);

    return 0;
}
