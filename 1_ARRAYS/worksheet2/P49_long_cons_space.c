/*49. Find longest consecutive sequence
Question description:
write a C program to find the length of the longest consecutive elements sequence.
Sample data:
Input: 100 4 200 1 3 2
Expected Output:
Longest consecutive sequence length: 4(1,2,3,4)*/

#include<stdio.h>
#include<stdlib.h>
void sort(int *a,int len)
{
    int i,j;
    for ( i = 0; i < len - 1; i++) {
        for ( j = i + 1; j < len; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
 int ele;
    printf("Enter the number of elemets:\n");
    scanf("%d",&ele);
    int a[ele];
    int i,j=0,k=0;

    printf("Enter the array elements\n");
        for(i=0;i<ele;i++)
        scanf("%d",&a[i]);   
        
        sort(a,ele);
        int res = 1, cnt = 1;
   
    for (int i = 1; i < ele; i++) 
    {      
      	if (a[i] == a[i-1]) 
          	continue;

        if (a[i] == a[i - 1] + 1) {
            cnt++;
        } 
        else {      
            cnt = 1;
        }
        if(cnt>res)
        res = cnt;
    }
   
printf("The longest consecutive element length is %d\n ",res);

}