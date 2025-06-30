/*11.Find the XOR of all numbers between L and R (inclusive) without iterating through each number.*/
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
int compute(int n,int m)
{
  return compute_xor(m)^compute_xor(n-1); 
}
int main()
{
    int n,m;
    printf("Enter the range value\n");
    scanf("%d%d",&n,&m);
    int n1=  compute(n,m);
    printf("The xor of all number in range is %d\n",n1);
}