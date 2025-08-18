/*5.Dynamic Memory Allocation
Goal: Allocate, reallocate, and free memory dynamically for different data types and structures while avoiding memory leaks.
Activity:
Allocate memory for an array using malloc.
Expand or shrink the allocated memory using realloc.
Initialize the allocated memory using calloc.
Free allocated memory after use.
Handle cases where allocation fails.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
				int *p=(int *)malloc(2*sizeof(int));
				int i;
				printf("Enter the elements of malloc\n");
				for(i=0;i<2;i++)
					scanf("%d",&p[i]);
				for(i=0;i<2;i++)
					printf("%d ",p[i]);
				printf("\n");
				int *q=(int*)realloc(p,3*sizeof(int));
				printf("Enter the elements of realloc\n");
				for(i=2;i<5;i++)
					scanf("%d",&q[i]);
				for(i=0;i<5;i++)
					printf("%d ",q[i]);
				printf("\n");
				for(i=0;i<5;i++)
					printf("%d ",p[i]);
				printf("\n");
				int *r=(int *)calloc(3,sizeof(int));
				for(i=0;i<3;i++)
					printf("%d ",r[i]);
				printf("\n");

				printf("Enter the elements of calloc\n");
				for(i=0;i<3;i++)
					scanf("%d",&r[i]);
				for(i=0;i<3;i++)
					printf("%d ",r[i]);
				printf("\n");

				free(p);
				for(i=0;i<2;i++)
					printf("%d ",p[i]);
				printf("\n");
				//free(q);
				for(i=0;i<5;i++)
					printf("%d ",q[i]);
				printf("\n");
				free(r);
				for(i=0;i<3;i++)
					printf("%d ",r[i]);
				printf("\n");

}
