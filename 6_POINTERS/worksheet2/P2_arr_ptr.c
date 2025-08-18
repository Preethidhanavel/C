/*2.Array and Pointer Arithmetic
Goal: Traverse and manipulate arrays by using pointers and pointer arithmetic instead of array indexing.
Activity:
Log Session an array of integers.
Use a pointer to iterate through the array elements by incrementing the pointer.
Perform operations like summing the elements or modifying them using only the pointer (no array indices).
Implement a function that receives a pointer and size to reverse the array elements in place.*/
#include<stdio.h>
void reverse(int *p,int n)
{
			int a,i,*q=p+(n-1);
			for(;p<q;p++,q--)
			{
			a=*p;
			*p=*q;
			*q=a;
			//p++;
			//q--;
			}
}

int main()
{
			int n;
			printf("Enter the size of an array\n");
			scanf("%d",&n);
			int a[n];
			printf("Enter the array elements\n");
			int i;
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			for(i=0;i<n;i++)
				printf("%d ",a[i]);
			int *p=a;
			for(i=0;i<n;i++){
				*p++=i+100;}
			p=a;
			for(i=0;i<n;i++)
				printf("%d ",*p++);
			reverse(a,n);
			p=a;
			for(i=0;i<n;i++)
				printf("%d ",*p++);

}
