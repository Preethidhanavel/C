/*Merge Two Sorted Lists
Input: List1: 1 → 3 → 5, List2: 2 → 4 → 6
Expected Output: 1 → 2 → 3 → 4 → 5 → 6*/
#include<stdio.h>
#include<stdlib.h>
struct st{
    struct st*prv;
    int roll;
    struct st*next;
};
void add_end(struct st**ptr)
{
    struct st *temp=malloc(sizeof(struct st));
    printf("Enter the roll\n");
    scanf("%d",&temp->roll);
    if(*ptr==NULL)
    {
        temp->prv=temp->next=NULL;
        *ptr=temp;
    }
    else
    {
        struct st *last=*ptr;
        while(last->next!=NULL)
        last=last->next;

        temp->prv=last;
        temp->next=last->next;
        last->next=temp;
    }
}
void print(struct st *ptr)
{
	if(ptr != 0) {
	printf("%d \n",ptr->roll);
	print(ptr->next);
	}
}
struct st * merge_list(struct st *l1,struct st*l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    struct st *merge=NULL;
    struct st **lastptr=&merge;
    struct st *lastnode=NULL;
    while(l1!=NULL&&l2!=NULL)
    {
        if(l1->roll<=l2->roll)
        {
            *lastptr=l1;
            l1=l1->next;
        }
        else{
            *lastptr=l2;
            l2=l2->next;
        }
         (*lastptr)->prv = lastnode;    
        lastnode = *lastptr;     
        lastptr=&((*lastptr)->next);

    }
    *lastptr=(l1!=NULL)?l1:l2;
    if(*lastptr)
        (*lastptr)->prv=lastnode;
        return merge; 
}
int main()
{
    struct st *hptr=0,*hptr1=0;
    int n,m,i;
    printf("Enter how many nodes you want to create for list1 and list 2\n");
    scanf("%d%d",&n,&m);
    printf("Enter the node of list1\n");
    for(i=0;i<n;i++)
    add_end(&hptr);
    printf("Enter the node of list2\n");
    for(i=0;i<m;i++)
    add_end(&hptr1);
   // print(hptr);
   // printf("\n");
   // print(hptr1);
    struct st *merge=merge_list(hptr,hptr1);
    print(merge);
}