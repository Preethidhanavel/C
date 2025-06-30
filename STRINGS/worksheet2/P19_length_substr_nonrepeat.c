//19.Find the length of the longest substring with no repeating characters.
//Input: "abcabcbb"
//Output: 3

#include<stdio.h>
#include<string.h>

int long_substr(char *s)
{
    int i,j,start,len,maxlen=0,index;
    start=0;
    for(i=0;s[i];i++)
    {
        for(j=start;j<i;j++)
        {
            if(s[i]==s[j])
            {
                start=j+i;
                break;
            }
        }
        len=i-start+1;
        if(len>maxlen)
        {
            maxlen=len;
            //index=start;
        }
    }
   
    return maxlen;
}


int main()
{
    char s[100];
    printf("Enter the string\n");
    scanf("%[^\n]",s);
    printf("output: %d",long_substr(s));
}