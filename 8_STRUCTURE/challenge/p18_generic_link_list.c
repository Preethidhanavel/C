/*18.How can you implement a generic linked list in C that can store data of any type?
struct GNode {
    void *data;
    struct GNode *next;
};*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gnode 
{
    void *data;
    struct gnode *next;
} gnode;

gnode* create_node(void *data, int size) 
{
    gnode *node = malloc(sizeof(gnode));
    node->data = malloc(size);
    memcpy(node->data, data, size);
    node->next = NULL;
    return node;
}

void append(gnode **head, void *data, int size) 
{
    gnode *new_node = create_node(data, size);
    if (!*head)
        *head = new_node;
    else 
    {
        gnode *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

void print_int_list(gnode *head) 
{
    while (head) 
    {
        printf("%d ", *(int *)(head->data));
        head = head->next;
    }
    printf("\n");
}

void free_list(gnode *head) 
{
    while (head) 
    {
        gnode *temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

int main() 
{
    gnode *head = NULL;
    int nums[] = {10, 20, 30, 40};

    for (int i = 0; i < 4; i++)
        append(&head, &nums[i], sizeof(int));

    print_int_list(head);
    free_list(head);
}
