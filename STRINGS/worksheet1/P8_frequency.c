/* 8.Program: Count frequency of each character in a string
         Input: "success"
         Output:
          s = 3
         u = 1
         c = 2
         e = 1*/
#include<stdio.h>
void count_frequency(char *s)
{
int i,j,k,c;
for(i=0;s[i];i++)
{
    for(j=0;j<i;j++)
    {
        if(s[i]==s[j])
            break;
    }
    if(i==j)
    {
        for(k=i+1,c=1;s[k];k++)
            if(s[i]==s[k])
                c++;
        printf("%c = %d\n",s[i],c);
    }
}
}
int main()
{
char a[100];
printf("Enter the string\n");
scanf("%[^\n]",a);
count_frequency(a);

}