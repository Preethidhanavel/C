#include<stdio.h>
#include<stdlib.h>

   int front = 0,rear = 0;
struct st{
int x;
struct st* next;
}; 
void enqueue(struct st**);
void dequeue(struct st **);
void display(struct st *);
#define MAX 5
int main()
   {struct st *hptr=0;
           int op;
          while(1)
          {                  printf("Enter the option 1)insert 2)delete 3)display 4)exit\n");
                  scanf("%d",&op);
  
                  switch(op)
                  {
                          case 1 : enqueue(&hptr); break;
                          case 2 : dequeue(&hptr); break;
                          case 3 : display(hptr); break;
                          case 4 : printf("Q operation is Over!\n");return 0;
                         default: printf("Invalid option entered...\n"); break;
                  }
          }
  }
 void enqueue(struct st**ptr)
  {
          int ele;
 
          if(rear == MAX) {
          printf("Q is Overflow...\n");
          return;
          }
  struct st *temp=(struct st*)malloc(sizeof(struct st));
          printf("Enter the element to insert...\n");
          scanf("%d",&ele);
  
          temp->x = ele;
	  temp->next=*ptr;
	  *ptr=temp;
  rear++;
        
 }
 void dequeue(struct st **ptr)
  {
          if((rear == 0)||(front==rear)) {
          printf("Q is Underflow...\n");
          return;
          }
  
          //printf("%d is deleted from Q...\n",Q[front]);
           struct st *last,*prv;
	   last=*ptr;

	   while(last->next != 0) {
	prv = last;
	last = last->next;
	}

	if(last == *ptr)
	*ptr = 0;
	else
	prv->next = last->next;
	free(last);
last=NULL;

front++;
  }
  void display(struct st *ptr)
  {
          int i;
          while(ptr!=0){
		  printf("%d  ",ptr->x);
		  ptr=(ptr->next);}
          printf("\n");
  }

