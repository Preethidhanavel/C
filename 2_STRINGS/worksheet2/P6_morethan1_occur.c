//6.Print all characters that occur more than once in a string.
//Input: "programming"
//Output: r g m

#include<Stdio.h>
void high_freq(char *s)
{
int i,freq[256]={0};
            for(i=0;s[i];i++)
                 freq[s[i]]++;
            for(i=0;i<256;i++)
            {
                  if(freq[i]>1)
                        printf("%c appeared more than once\n",i);
            }
}
int main()
{
        char s[100];
        printf("Enter the string\n");
        scanf("%[^\n]",s);
        high_freq(s);

    
}