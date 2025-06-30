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
void print(ST *ptr)
{
	if(ptr != 0) {
	printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
	print(ptr->next);
	}
}
int count(ST *ptr)
{
	int c = 0;
	while(ptr != 0) {
	c++;
	ptr = ptr->next;
	}
	return c;
}
void rev_data(ST *ptr)
{
	ST *p1,*p2;
	ST temp;
	int i,j,c = count(ptr);
        int size = sizeof(ST)-8;

	p1 = ptr;
        p2 = ptr;
        for(j=0;j<c-1;j++)
        p2 = p2->next;

   for(i=0;i<c/2;i++)
   {
	   memcpy((int *)&temp+1,(int *)p1+1,size);	  
	   memcpy((int *)p1+1,(int *)p2+1,size);	  
	   memcpy((int *)p2+1,(int *)&temp+1,size);	 
 
	   p1 = p1->next;
	   p2 = p2->prv;
   }
}
void rev_links(ST **ptr)
{
	ST *temp;

	while(*ptr != 0) 
	{
		temp = (*ptr)->prv;
		(*ptr)->prv = (*ptr)->next;
		(*ptr)->next = temp;
	
		*ptr = (*ptr)->prv;
	}
		*ptr = temp->prv;
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
    rev_data(hptr);
    print(hptr);
    rev_links(hptr);
    print(hptr);

}