/*9.Introduction to Structures in C
Goal
Grasp the basic concept of structures in C, including their need, syntax, and difference from arrays and unions.

Activity
Define a simple structure with multiple data types.
Compare it with an array and a union with similar members.
Initialize the structure in different ways and print values.
Analyze why structures are preferred in peripheral register grouping.
Tip: Structures allow logically grouping different data types under one name.*/
#include<stdio.h>
struct st{
int x;
char ch;
};
union u{int x1;
char ch1;};
int main()
{
struct st v={1,'a'};

union u ut;
v.x=9;
v.ch='h';
struct st *p=&v;
scanf("%d %c",&v.x,&v.ch);
//scanf("%d %c",&p->x,&p->ch);
printf("%d  %c\n",v.x,v.ch);
printf("structure size%ld  union size%ld\n",sizeof(v),sizeof(ut));
}
