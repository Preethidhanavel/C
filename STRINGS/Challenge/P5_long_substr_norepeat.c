//5.Find the longest substring without repeating characters
//Find the length or substring which has all unique characters without any repetition.

//Example: Input: "abcabcbb"
//Output: "abc"


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
            index=start;
        }
    }
    char res[100];
    strncpy(res,s+index,maxlen);
    res[maxlen]='\0';
    printf("%s\n",res);
    return maxlen;
}


int main()
{
    char s[100];
    printf("Enter the string\n");
    scanf("%[^\n]",s);
    printf("output: %d",long_substr(s));
}