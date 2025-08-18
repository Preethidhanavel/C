/*11.Pointer and Linked List
Goal: Implement a singly linked list using pointers for node management and dynamic memory allocation.
Activity:
Define a node structure with data and next pointer.
Log Session functions to add nodes at the beginning, end, or middle of the list using pointers.
Traverse the list using pointers to access and print data.
Delete nodes and free memory dynamically.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct st{
int x;
struct st*next;
}ST;
void add_begin(struct st**);
void add_middle(struct st**);
void add_end(struct st**);
void print(struct st*);
int main()
{
	struct st*hptr=0;
	char op;
	do{
	add_begin(&hptr);
	//add_middle(&hptr);
	//add_end(&hptr);
	printf("do you want to enter the data again\n");
	scanf(" %c",&op);
	}while((op=='y')||(op=='Y'));
	print(hptr);
	recursion(hptr);

}
void add_begin(struct st **ptr)
{
	struct st*temp=(struct st*)malloc(sizeof(struct st));
	printf("Enterr the elements\n");
	scanf("%d",&temp->x);
	temp->next=*ptr;
	*ptr=temp;
}
void add_end(ST **ptr)  //Function call : add_end(&hptr)
{
	ST *temp;
	temp = (ST *)malloc(sizeof(ST));
	printf("Enter the roll,name & marks\n");
	scanf("%d",&temp->x);

	if(*ptr == 0) {
	temp->next = *ptr;
	*ptr = temp;
	}
	else {
	ST *last = *ptr;  
	
	while(last->next != 0)
      last = last->next;
	
	temp->next = last->next;
	last->next = temp;
	}
}
void add_middle(ST **ptr)  
{
	ST *temp;
	temp = (ST *)malloc(sizeof(ST));
	printf("Enter the roll,name & marks\n");
	scanf("%d",&temp->x);

	if((*ptr == 0)||(temp->x < (*ptr)->x)) 
	{
	temp->next = *ptr;
	*ptr = temp;
	}
	else {
	ST *last = *ptr; 
	
	while((last->next != 0)&&(temp->x > last->next->x))
        last = last->next;
	
	temp->next = last->next;
	last->next = temp;
	}
}
void recursion(struct st*ptr)
{

	if(ptr==NULL)
		return;
	//printf("%d ",ptr->x);
	recursion(ptr->next);
	printf("%d ",ptr->x);
}
void print(struct st * ptr)
{
	while(ptr!=0){
		printf("%d ",ptr->x);
	ptr=ptr->next;
	}
	printf("\n");

}
