/*10.Log Session a function that rotates an array to the right by k elements using pointers.*/
#include<stdio.h>
void rot_right(int *a,int ele,int n)
{
    int start,i,j;
         for(i=0;i<n;i++)
    {
        start=a[ele-1];
        for(j=ele-1;j>0;j--)
        {
            *(a+j)=*(a+(j-1));
        }
        a[0]=start;
    }
}
int main()
{
    
    int a[5],t,i,j,end,ele,n;

    ele = sizeof(a) / sizeof(a[0]);

    printf("Array: ");
    for(i = 0; i < ele; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Rotate right by:");
    scanf("%d",&n);
    rot_right(a,ele,n);

   
       printf("output:");
     for(i=0;i<ele;i++)
    {
        printf("%d ",a[i]);
    }

}