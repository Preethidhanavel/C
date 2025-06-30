/*3.Program: Find highest frequency character in a string
          Input: "engineering"
          Output: 'e' appears 3 times*/

#include<Stdio.h>
void high_freq(char *s)
{
          int i,j,k,c,temp=0;
          char ch;
          for(i=0;s[i];i++)
          {
                for(j=i;j<i;j++)
                {
                        if(s[i]==s[j])
                                break;
                }
                if(i==j)
                {
                        for(k=i+1,c=1;s[k];k++)
                                if(s[i]==s[k])
                                c++;
                        if(temp<c)
                        {
                                temp=c;
                                ch=s[i];
                        }
                }

          }
          printf("%c appeared %d times\n",ch,temp);
}
int main()
{
        char s[100];
        printf("Enter the string\n");
        scanf("%[^\n]",s);
        high_freq(s);

    
}