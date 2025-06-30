/*Remove N-th Node from End
Input: 1 → 2 → 3 → 4 → 5, n = 2
Expected Output: 1 → 2 → 3 → 5*/


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
    if (head == NULL) return temp;
    struct node* cur = head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = temp;
    return head;
}

struct node* removenode(struct node* head, int n) 
{
    int length = 0;
    struct node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    int pos = length - n + 1;
    if (pos <= 0) return head;
    if (pos == 1) 
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    temp = head;
    for (int i = 1; i < pos - 1; i++) 
    {
        temp = temp->next;
    }
    struct node* todelete = temp->next;
    temp->next = todelete->next;
    free(todelete);
    return head;
}

void printlist(struct node* head) 
{
    struct node* cur = head;
    while (cur != NULL) 
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int n, val, size;
    printf("enter number of nodes: ");
    scanf("%d", &size);
    printf("enter node values:\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &val);
        head = addend(head, val);
    }
    printf("enter n (node from end to remove): ");
    scanf("%d", &n);
    head = removenode(head, n);
    printf("list after removal: ");
    printlist(head);
    return 0;
}
