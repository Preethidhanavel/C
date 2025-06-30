/*8.Compute the XOR of all integers in the range from 1 up to n without iterating over the entire range.*/
#include<stdio.h>
int compute_xor(int n)
{
 switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }

}
int main()
{
    int n;
    printf("Enter the range value\n");
    scanf("%d",&n);
    int n1=  compute_xor(n);
    printf("The xor of all number in range is %d\n",n1);
}