/*1.Write a program to perform the following operations on the Least and Most Significant Bits (LSB/MSB) of a given integer:
Set the LSB to 1
Clear the LSB (set to 0)
Toggle the LSB
Set the MSB to 1
Clear the MSB (set to 0)
Toggle the MSB
Set a specific bit to 1
Clear a specific bit
Toggle a specific bit*/

#include<stdio.h>
void binary(int n)
{ 
        int i;
        for(i=31;i>=0;i--)
                printf("%d",(n>>i)&1);
}
void set(int n,int pos)
{
        printf("inside set a bit fun\n");
        n|=(1<<pos);
        printf("After bitwise operation %d\n",n);
        binary(n);


}
void clear(int n,int pos)
{
        printf("\ninside clear a bit fun\n");
        n&= ~(1<<pos);
        printf("After bitwise operation %d\n",n);
        binary(n);

}
void toggle(int n,int pos)
{
        printf("\ninside toggle a bit fun\n");
        n^=(1<<pos);
        printf("After bitwise operation %d\n",n);
        binary(n);

    }
int main()
{
        int n,pos;
        printf("Enter the number\n");
        scanf("%d",&n);
        printf("enter the position\n");
        scanf("%d",&pos);
      
        set(n,pos);     
        clear(n,pos);
        toggle(n,pos);   
     

}