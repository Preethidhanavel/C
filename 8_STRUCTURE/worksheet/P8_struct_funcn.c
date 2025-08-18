/*8.Structures and Functions
Goal
Learn how to pass structures to and return structures from functions and understand the trade-offs between pass-by-value and pass-by-reference.

Activity
Write a function that takes a structure as a value argument and modifies it.
Write a function that takes a pointer to structure and modifies it.
Return a structure from a function and print its values.
Measure memory usage and performance difference between pass-by-value and reference.
Tip: Prefer passing by pointer in embedded systems for performance and memory efficiency.*/
#include<stdio.h>
#include<stdlib.h>
struct st{
int x;
};
void value_fun(struct st v1)
{
v1.x=8;
}
void reference_fun(struct st *v1)
{
v1->x=9;
}
struct st * struct_ptr(struct st *v)
{

v->x=10;
return v;
}
int main()
{
struct st v={2};
struct st*p=&v;
printf("%d\n",v.x);
value_fun(v);
printf("%d\n",v.x);
reference_fun(p);
printf("%d\n",v.x);
struct st *p1=(struct st*)malloc(sizeof(struct st));
p=struct_ptr(p1);
printf("%d\n",p->x);
}
