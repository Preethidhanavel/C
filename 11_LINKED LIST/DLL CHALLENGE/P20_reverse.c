/*Reverse Alternate K Nodes
Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, k = 2
Expected Output: 2 → 1 → 3 → 4 → 6 → 5 → 7 → 8*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* addend(struct node* head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = temp->prev = NULL;
    if (head == NULL) return temp;
    struct node* cur = head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

void printlist(struct node* head) {
    struct node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

struct node* reverse_k(struct node* head, int k, struct node** nextStart) {
    struct node* curr = head;
    struct node* prev = NULL;
    int count = 0;
    while (curr != NULL && count < k) {
        struct node* next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        count++;
    }
    *nextStart = curr;
    return prev;
}

struct node* reverse_alt_k(struct node* head, int k) {
    if (head == NULL) 
        return NULL;
    struct node* nextStart = NULL;
    struct node* newHead = reverse_k(head, k, &nextStart);
    if (head != NULL) {
        head->next = nextStart;
        if (nextStart) nextStart->prev = head;
    }
    struct node* temp = nextStart;
    int count = 0;
    while (temp != NULL && count < k - 1) {
        temp = temp->next;
        count++;
    }
    if (temp && temp->next) 
        temp->next = reverse_alt_k(temp->next, k);
    if (temp && temp->next) 
        temp->next->prev = temp;
    return newHead;
}

int main() {
    struct node* head = NULL;
    int n, val, k;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the value %d\n",i+1);
        scanf("%d", &val);
        head = addend(head, val);
    }
    printf("Enter the value of k\n");
    scanf("%d", &k);
    head = reverse_alt_k(head, k);
    printlist(head);
    return 0;
}
