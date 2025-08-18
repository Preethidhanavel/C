/*3.Write a program to modify specific portions of a given integer:
Set all bits in the Least Significant Byte (LSB) to 1
Set all bits in the Most Significant Byte (MSB) to 1
Set all bits in the Least Significant Nibble to 1
Set all bits in the Most Significant Nibble to 1
Set n bits to 1 (user input)
Clear n bits (set to 0), with n as input
Toggle n bits (user input)*/

#include<stdio.h>
void binary(int n)
{ 
        int i;
        for(i=31;i>=0;i--)
            printf("%d",(n>>i)&1);
}
void set_lsb(int n)
{
    int i;
    for(i=0;i<8;i++)
        n|=1<<i;
    binary(n);
    printf("\n");
}
void set_msb(int n)
{
    int i;
    for(i=24;i<32;i++)
        n|=1<<i;
    binary(n);
    printf("\n");
}
void set_lsb_nibble(int n)
{ 
    int i;
    for(i=0;i<4;i++)
        n|=1<<i;
    binary(n);
    printf("\n");
    
}
void set_msb_nibble(int n)
{   
    int i;
    for(i=28;i<32;i++)
        n|=1<<i;  
    binary(n);
    printf("\n");
}
void set_nbit(int n,int pos,int b)
{
    int i,len;
    if((pos+b)>32)
        len=32;
    else
        len=pos+b;
    for(i=pos;i<len;i++)
        n|=1<<i;
    binary(n);
    printf("\n");
}
void clear_nbit(int n,int pos,int b)
{
    int i;
    int len;
    if((pos+b)>32)
        len=32;
    else
        len=pos+b;
    for(i=pos;i<len;i++)
        n&=~(1<<i);
    binary(n);
    printf("\n");
}
void toggle_nbit(int n,int pos,int b)
{
        int i;
        int len;
        if((pos+b)>32)
         len=32;
        else
         len=pos+b;
        for(i=pos;i<len;i++)
            n^=1<<i;
        binary(n);
        printf("\n");
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    set_lsb(n);
    set_msb(n);
    set_lsb_nibble(n);
    set_msb_nibble(n);
    int b,pos;
    printf("Enter the number of bits\n");
    scanf("%d",&b);
    printf("Enter the starting position\n");
    scanf("%d",&pos);
    set_nbit(n,pos,b); 
    clear_nbit(n,pos,b); 
    toggle_nbit(n,pos,b); 
   
}