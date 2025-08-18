/*4.Function Pointers in Structures
Goal
Learn how to include and use function pointers inside structures for callback mechanisms and dynamic behavior in embedded systems.

Activity
Define a structure containing function pointers.
Initialize it with different functions and invoke them.
Use this setup to simulate a hardware driver interface with different behavior implementations.
Demonstrate dynamic assignment and execution of function pointers based on a condition or input.
Tip: Use typedef for cleaner function pointer declarations.*/
#include<stdio.h>
typedef void(*sum)(int ,int);
struct st{
sum fp;

};
void add(int a,int b)
{
printf("in sum\n");
}
void sub(int a ,int b){
printf("in sub \n");
}
int main()
{
int op;
struct st v;
printf("Enter the option\n");
scanf("%d",&op);
switch(op){
	case 1:v.fp=add;break;
	case 2:v.fp=sub;break;
	default:printf("invalid option\n");return 0;
}
v.fp(2,1);
}
