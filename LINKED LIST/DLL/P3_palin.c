//PALINDROME OR NOT
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    struct student* prv;
    int roll;
    struct student* nxt;
}st;

void add_end(st** ptr)
{
    st* temp = (st*)malloc(sizeof(st));
    printf("Enter the details:\n");
    scanf("%d",&temp->roll);

    if((*ptr)==0)
    {
        temp->prv=temp->nxt=(*ptr);
        (*ptr)=temp;
    }
    else
    {
        st* last = (*ptr);
        while(last->nxt)
        last=last->nxt;

        temp->nxt=last->nxt;
        last->nxt=temp;
        temp->prv=last;
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
    if(ptr!=0)
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

void palin(st* ptr)
{
    st *p1=ptr,*p2=ptr;
    int i,c=count(ptr);
    
    while(p2->nxt)
    p2=p2->nxt;

    for(i=0;i<c/2;i++)
    {
        if((p1->roll)!=(p2->roll))
        break;

        p1=p1->nxt;
        p2=p2->prv;
    }

    if(i!=c/2)
    printf("Not Plaindrome\n");
    else
    printf("Palindrome\n");
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
    
    palin(hptr);

}