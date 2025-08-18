/*4.Pointer and Function
Goal: Use pointers to pass variables or arrays to functions so that the function can modify the original data.
Activity:
Write a function that takes pointers as parameters to swap two integer variables.
Log Session a function that modifies the elements of an array via a pointer.
Pass a pointer to a function to update the contents of a structure or a dynamically allocated memory block.*/
#include<stdio.h>
struct st{
        int a;
        char name[20];
        float f;
};
void swap(int *a,int *b)
{
                int c;
                c=*a;
                *a=*b;
                *b=c;
}
void modify(struct st*p)
{
                p->a=40;
                strcpy(p->name,"hi");
                p->f=90;

}
void arr_modify(int *a,int n)
{
                int i;
                for(i=0;i<n;i++)
                {
                    *(a+i)=i+22;
                }
}
int main()
{
                struct st v={12,"hello",20.5};
                struct st *p=&v;
                printf("roll:%d name:%s float:%f\n",v.a,v.name,v.f);
                modify(p);
                printf("roll:%d name:%s float:%f\n",v.a,v.name,v.f);
                int a,b;
                printf("Enter the elements for swapping\n");
                scanf("%d%d",&a,&b);
                swap(&a,&b);
                printf("After swapping %d  %d\n",a,b);
                int n;
                printf("Enter the number of array elements\n");
                scanf("%d",&n);
                int arr[n],i;
                printf("Enter the array elements\n");
                for(i=0;i<n;i++)
                    scanf("%d",&arr[i]);
                printf("Before modifying array\n");
                for(i=0;i<n;i++)
                    printf("%d ",arr[i]);
                arr_modify(arr,n);
                printf("\nAfter modifying array\n");
                for(i=0;i<n;i++)
                    printf("%d ",arr[i]);

}
