#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct student
{
	struct student *prv;
	int roll;
	char name[20];
	float marks;
	struct student *next;
}ST;

void add_begin(ST **ptr)  
{
	ST *temp;
	temp = (ST *)malloc(sizeof(ST));
	printf("Enter the roll,name & marks\n");
	scanf("%d%s%f",&temp->roll,temp->name,&temp->marks);

	temp->prv = 0;
	temp->next = *ptr;
	
	if(*ptr != 0)
	(*ptr)->prv = temp;
	
	*ptr = temp;	
}
void add_end(ST **ptr)  
{
	ST *temp;
	temp = (ST *)malloc(sizeof(ST));
	printf("Enter the roll,name & marks\n");
	scanf("%d%s%f",&temp->roll,temp->name,&temp->marks);
	if(*ptr == 0)
	{
		temp->prv = 0;
		temp->next = 0;
		*ptr = temp;
	}
	else
	{
		ST *last = *ptr;
		while(last->next != 0)
		last = last->next;

		temp->prv = last;
		temp->next = last->next;
		last->next = temp;
	}
}
void add_middle(ST **ptr)  
{
	ST *temp;
	temp = (ST *)malloc(sizeof(ST));
	printf("Enter the roll,name & marks\n");
	scanf("%d%s%f",&temp->roll,temp->name,&temp->marks);

	if((*ptr == 0)||(temp->roll < (*ptr)->roll)) 
	{
		temp->prv = 0;
		temp->next = *ptr;

		if(*ptr != 0)
		(*ptr)->prv = temp;

		*ptr = temp;
	}
	else {
	ST *last = *ptr; 
	
	while((last->next != 0)&&(temp->roll > last->next->roll))
        last = last->next;
	
	temp->prv = last;
	temp->next = last->next;

	if(last->next != 0)
	last->next->prv = temp;	
	
	last->next = temp;
	}
}
void print(ST *ptr)
{
	if(ptr != 0) {
	printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
	print(ptr->next);
	}
}
void rev_print(ST *ptr)
{
	while(ptr->next != 0)
	ptr = ptr->next;

	while(ptr != 0)
	{
	   printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
	   ptr = ptr->prv;
	}	
}
int main()
{
	ST *hptr = 0;
	char ch;
	do{
	//add_begin(&hptr);
	add_end(&hptr);
	//add_middle(&hptr);
	printf("U want to continue to add a node(y/n)\n");
	scanf(" %c",&ch);
	}while((ch == 'y')||(ch == 'Y'));
    print(hptr);
    rev_print(hptr);
}
