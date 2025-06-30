/*13.Rotate bits of a given number
Question: Write a C program to rotate bits of a number to the left or right by a given number of positions.
Sample data: Input: number=16 (binary 00010000), rotate left by 2
Expected output: Result after rotation: 64 (binary 01000000)*/

#include<stdio.h>
typedef unsigned char u8;
void binary(u8 n)
{
     int i;
        for(i=7;i>=0;i--)
            printf("%d",(n>>i)&1);
        printf("\n");
}
void rot_left(u8 n,int r)
{
    int i,j;
    int x=n<<r;
    int y=n>>(8-r);
    printf("Result after rotation:%d\n",x|y);
    binary(x|y);
    
  
}
int main()
{
    u8 n;
    printf("Enter the number\n");
    scanf("%d",&n);
    binary(n);
    printf("\n");
    int r;
    printf("Enter the number of rotation\n");
    scanf("%d",&r);
    rot_left(n,r);
}