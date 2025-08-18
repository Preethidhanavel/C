/*7.How can you count the number of set bits in a floating-point number?*/
#include<stdio.h>
int main()
{
    float f;
    printf("Enter the float value\n");
    scanf("%f",&f);
    char *p=(char *)&f;
    int i,j,c=0;
    p=p+3;
    for(i=3;i>=0;i--)
    {
      for(j=7;j>=0;j--)
      {
        if(((*p)>>j)&1)
          c++;
      //  printf("%d",((*p>>j)&1));
      }
        p--;
    }
    printf("\nthe number of bits set is %d\n",c);
}