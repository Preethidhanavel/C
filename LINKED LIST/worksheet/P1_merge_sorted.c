//Write a C program to merge two sorted singly linked lists into a single sorted linked list.
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

st* mergeSortedLists(st* l1, st* l2) 
{
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    st* mergedHead = NULL;
   st** lastPtrRef = &mergedHead;

    while (l1 != NULL && l2 != NULL)
     {
        if (l1->roll <= l2->roll) 
        {
            *lastPtrRef = l1;
            l1 = l1->nxt;
        } 
        else 
        {
            *lastPtrRef = l2;
            l2 = l2->nxt;
        }
        lastPtrRef = &((*lastPtrRef)->nxt);
    }

    
    *lastPtrRef = (l1 != NULL) ? l1 : l2;

    return mergedHead;
}


int main()
{
    st* list1=0;
    st* list2=0;
    
    add_end(&list1);
    add_end(&list1);
    add_end(&list1);
    
    printf("List1:\n");
    print(list1); 

    add_end(&list2);
    add_end(&list2);
    add_end(&list2);
    
    printf("List2:\n");
    print(list2); 

    st* mergedList = mergeSortedLists(list1, list2);

    printf("Merged list: ");
    print(mergedList);
}