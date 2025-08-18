/*Find the Middle Node
Input: 1 → 2 → 3 → 4 → 5
Expected Output: 3*/


#include <stdio.h>
#include <stdlib.h>

typedef struct dll {
    int data;
    struct dll* prev;
    struct dll* next;
} dll;

dll* newdll(int val) {
    dll* temp = (dll*)malloc(sizeof(dll));
    temp->data = val;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

dll* addend(dll* head, int val) {
    dll* temp = newdll(val);
    if (!head) return temp;
    dll* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

void findmid(dll* head) {
    dll* slow = head;
    dll* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow) 
    printf("middle node: %d\n", slow->data);
}

int main() {
    dll* head = NULL;
    int n, val;
    printf("enter number of nodes: ");
    scanf("%d", &n);
    printf("enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = addend(head, val);
    }
    findmid(head);
    return 0;
}
