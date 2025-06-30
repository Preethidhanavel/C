/*Check for Palindrome
Input: 1 → 2 → 3 → 2 → 1
Expected Output: True (The list is a palindrome)*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) 
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void addend(struct node** head, int data) 
{
    struct node* newnode = createnode(data);
    if (*head == NULL) {
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
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* reverseList(struct node* head) 
{
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int isPalindrome(struct node* head) 
{
    if (head == NULL || head->next == NULL)
        return 1;
    struct node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct node* secondHalf = reverseList(slow->next);
    struct node* firstHalf = head;
    struct node* tempSecond = secondHalf;
    int palindrome = 1;
    while (tempSecond != NULL) {
        if (firstHalf->data != tempSecond->data) {
            palindrome = 0;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }
    slow->next = reverseList(secondHalf);
    return palindrome;
}

int main() 
{
    struct node* head = NULL;
    int n, data;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        addend(&head, data);
    }
    printf("List: ");
    printlist(head);
    if (isPalindrome(head))
        printf("Linked list is a palindrome.\n");
    else
        printf("Linked list is not a palindrome.\n");
    
}
