/*4.Program: Find lowest frequency character in a string
          Input: "engineering"
         Output: 'g', 'r', 'n' each appear once*/
#include<stdio.h>
#include<limits.h>
void low_freq(char *s)
{
            int i,j,k,c,temp=1;
            char ch;
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
                    {
                        if(s[i]==s[k])
                            c++;
                    }
                    if(c==1)
                    {
                        temp=c;
                        ch=s[i];
                        printf("%c appeared %d times\n",ch,temp);
                    }            
                }
            }
}

void low_freq1(char *s)
{
            int a[256]={0};
            int i,temp;
            for(i=0;s[i];i++)
            {
                a[s[i]]++;
            }
            temp =INT_MAX;
            for(i=0;i<256;i++)
            {
                if((temp>a[i])&&(a[i]>0))
                {
                    temp=a[i];
                    char ch=i;
                }
            }
            for(i=0;i<256;i++)
            {
                if(temp==a[i])
                    printf("  %c appeared %d times\n",i,temp);
            }

}
int main()
{
            char s[100];
            printf("Enter the string\n");
            scanf("%[^\n]",s);
            low_freq1(s);    
}