/*8.Pointer and Multi-Dimensional Arrays
Goal: Access and manipulate elements of multi-dimensional arrays using pointers and pointer arithmetic.
Activity:
Declare a 2D array.
Use pointers to iterate through rows and columns.
Implement operations such as matrix transpose or addition using pointer arithmetic only.
Pass multi-dimensional arrays as pointers to functions and manipulate elements.*/
#include<stdio.h>
#include<stdlib.h>
void manipulate(int **p,int m,int n)
{
				int i,j,c;
				for(i=0;i<m;i++)
				{
					for(j=i+1;j<n;j++){
						c=p[i][j];
						p[i][j]=p[j][i];
						p[j][i]=c;
				}
				}
}
int main()
{
				int m,n,i,j,k;
				printf("Enter the row and column of matrix\n");
				scanf("%d%d",&m,&n);
				int **p=(int **)malloc(m*sizeof(int*));
				for(i=0;i<m;i++)
					p[i]=(int *)malloc(n*sizeof(int));

				int **q=(int **)malloc(m*sizeof(int*));
				for(i=0;i<m;i++)
					q[i]=(int *)malloc(n*sizeof(int));
				for(i=0;i<m;i++){
					for(j=0;j<n;j++)
						scanf("%d",&p[i][j]);
				}

				for(i=0;i<m;i++){
					for(j=0;j<n;j++)
						printf("%d ",p[i][j]);
						printf("\n");
				}
				for(i=0;i<m;i++){
					for(j=i+1;j<n;j++){
						int c=p[i][j];
							p[i][j]=p[j][i];
							p[j][i]=c;
				}
				}
				printf("After transpose\n");
				for(i=0;i<m;i++){
					for(j=0;j<n;j++)
						printf("%d ",p[i][j]);
						printf("\n");
				}
				manipulate(p,m,n);

				for(i=0;i<m;i++){
					for(j=0;j<n;j++)
						printf("%d ",p[i][j]);
						printf("\n");
				}
}
