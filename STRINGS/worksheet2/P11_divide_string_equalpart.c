//11.Divide a string into N equal parts and print each part separately.
//Input:"abcdefgh",N=4;
//Output:"ab","cd","ef","gh"

#include<stdio.h>
#include<string.h>
void divide_string(char *s,int k)
{       int i,l=strlen(s);
      for(i=0;i<l;i++)
    {
        printf("%c",s[i]);
        if((i+1)%k==0)
            printf("  ");
    }
}

int main()
{
    char s[20];
    printf("Enter string:\n");
    scanf("%s",s);
    int i,N,l=strlen(s),k;
    printf("Enter N value:\n");
    scanf("%d",&N);

    if(l%N != 0)
    {
        printf("string cannot be divided equally\n");
        return 0;
    }

    k=l/N;
    divide_string(s,k);
  

}