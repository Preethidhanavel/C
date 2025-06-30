//Write a function that adds a new node at the end of a singly linked list. Make sure you handle memory allocation correctly.

#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    int roll;
    struct student* nxt;
}st;

void add_end(st** ptr)
{
    st* temp=malloc(sizeof(st));
    printf("Enter the data:\n");
    scanf("%d",&temp->roll);

    if((*ptr)==0)
    {
        temp->nxt = (*ptr);
        (*ptr) = temp;
    }
    else
    {
        st* last = (*ptr);
        while(last->nxt)
        last = last->nxt;

        temp->nxt = last->nxt;
        last->nxt = temp;
    }
}

void print(st* ptr)
{
    if(ptr!=NULL)
    {
        while(ptr)
        {
            printf("%d ",ptr->roll);
            ptr = ptr->nxt;
        }
    }
    else
    printf("Nothing is there\n");
    printf("\n");
}

void delete(st** ptr)
{
    st* temp;
    while((*ptr))
    {
        temp=(*ptr);
        (*ptr)=(*ptr)->nxt;
        free(temp);
        temp=NULL;
    }
}

int main()
{
    st* hptr=0;
    char op;
    do
    {
        add_end(&hptr);
        printf("Do you want to add another node:\n");
        scanf(" %c",&op);
    } while (op=='y');
    print(hptr); 
    delete(&hptr);
    print(hptr);
}