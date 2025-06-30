/*6.Find the first missing positive integer in an unsorted array
Write an efficient algorithm to find the smallest missing positive integer from an unsorted array (in O(n) time and constant space).

Example: Input: [3, 4, -1, 1]
Output: 2*/
#include<stdio.h>
void sort_arr(int *a,int len)
{  
for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
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
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,j,s;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort_arr(a,n);
    int c=a[0];
    for(i=0;i<n;i++){
        if((c+i)!=a[i]){
    printf("The missing element is %d\n",i+1);
    break;
    }
    }
}