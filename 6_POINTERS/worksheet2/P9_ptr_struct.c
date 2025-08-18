/*9.Pointer and Structures
Goal: Use pointers to access and modify structure members efficiently, including passing structures to functions.
Activity:
Define a structure and create a pointer to it.
Use the pointer to read and modify structure members.
Pass structure pointers to functions that update structure data.
Dynamically allocate memory for structures and handle them via pointers.*/
#include<stdio.h>
#include<stdlib.h>
struct st{
    int x;
};
void modify(struct st* ptr)
{
            ptr->x=32;
}

int main()
{
            struct st v;
            struct st *p=&v;
            scanf("%d",&p->x);
            printf("%d\n",p->x);
            modify(p);
            printf("%d\n",p->x);
            struct st*ptr=(struct st*)malloc(sizeof(struct st));
            scanf("%d",&ptr->x);
            printf("%d",ptr->x);

}
