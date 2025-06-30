/*Find Intersection with Arbitrary Lengths
Input: List1: 1 → 2 → 3 → 4 → 5, List2: 9 → 8 → 5 (node 5 shared)
Expected Output: Intersection at node with value 5
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void add(struct node** head, int d) 
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;

    if (*head == NULL) 
    {
        *head = n;
        return;
    }

    struct node* t = *head;
    while (t->next != NULL)
        t = t->next;
    t->next = n;
}

int len(struct node* head) 
{
    int c = 0;
    while (head != NULL) 
    {
        c++;
        head = head->next;
    }
    return c;
}

struct node* intersect(struct node* a, struct node* b) 
{
    int la = len(a);
    int lb = len(b);
    int d = abs(la - lb);

    struct node* longl = (la > lb) ? a : b;
    struct node* shortl = (la > lb) ? b : a;

    for (int i = 0; i < d; i++)
        longl = longl->next;

    while (longl && shortl) 
    {
        if (longl == shortl)
            return longl;
        longl = longl->next;
        shortl = shortl->next;
    }

    return NULL;
}

int main() {
    struct node* a = NULL;
    struct node* b = NULL;

    add(&a, 1);
    add(&a, 2);
    add(&a, 3);
    add(&a, 4);
    add(&a, 5);

    add(&b, 9);
    add(&b, 8);

    struct node* t = a;
    while (t && t->data != 5)
        t = t->next;

    if (t) 
    {
        struct node* tb = b;
        while (tb->next)
            tb = tb->next;
        tb->next = t;
    }

    struct node* x = intersect(a, b);

    if (x)
        printf("intersection at node with value: %d\n", x->data);
    else
        printf("no intersection found\n");

    return 0;
}
