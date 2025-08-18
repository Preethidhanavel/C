/*13.In an array where all numbers occur an even number of times except two numbers
 that occur an odd number of times, find those two numbers.*/

 #include<stdio.h>
void find_odd_occur(int *arr, int n) 
 {
    int xor = 0,x,y;
  
    for (int i = 0; i < n; i++) {
        xor ^= arr[i];
    }
   int set_bit = xor & (-xor);

    x = 0;
    y = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i] & set_bit)
            x ^= arr[i];
        else
            y ^= arr[i];
    }
    printf("The unique two numbers are %d %d\n",x,y);
}

 int main() 
 {

    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int arr[n];
    int i,j;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    find_odd_occur(arr, n);

 }