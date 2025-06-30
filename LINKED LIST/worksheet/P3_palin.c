//Write a C program to check if a singly linked list is a palindrome.
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

int count(st* ptr)
{
    int c=0;
    if(ptr!=NULL)
    {
        while(ptr)
        {
            c++;
            ptr = ptr->nxt;
        }
        return c;
    }
    else
    return c;
}

void check(st* ptr)
{
    st* temp,*t=ptr;
    int c=count(ptr),i,j;

    for(j=0;j<c/2;j++)
    {
        temp = t; 
        for(i=0;i<c-j-1;i++)
        temp = temp->nxt;

        if(temp->roll != ptr->roll){
            printf("Linked List is not a Palindrome:\n");
            return;
        }
        ptr = ptr->nxt;
    }
    printf("Linked List is a Palindrome:\n");
}

int main()
{
    st* hptr=0;

    add_end(&hptr);
    add_end(&hptr);
    add_end(&hptr);
    add_end(&hptr);

    print(hptr);
    check(hptr);
}