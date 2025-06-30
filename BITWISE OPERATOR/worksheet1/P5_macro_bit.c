/*5.Write macros to set, clear, and toggle the nth bit using bitwise operators.*/
#include<stdio.h>
#define SET_BIT(n,pos)  (n|(1<<pos))
#define CLEAR_BIT(n,pos) (n&~(1<<pos))
#define TOGGLE_BIT(n,pos) (n^(1<<pos))
void binary(int n)
{ 
        int i;
        for(i=31;i>=0;i--)
                printf("%d",(n>>i)&1);
        printf("\n");
}
int main()
{
        int n,pos;
        printf("Enter the numberr and position\n");
        scanf("%d%d",&n,&pos);
        int x=SET_BIT(n,pos);
        binary(x);
        x=CLEAR_BIT(n,pos);
        binary(x);
        x=TOGGLE_BIT(n,pos);
        binary(x);
        }