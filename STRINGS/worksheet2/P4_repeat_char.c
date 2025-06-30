//4.Find the character that appears most frequently in the input string and print it.
//Input: "sample string"
//Output: 's'

#include<stdio.h>
void find_repeated_char(char *s)
{
 int i,freq[256]={0};
        for(i=0;s[i];i++)
            freq[s[i]]++;
 int max=0;
 char c;
        for(i=0;i<256;i++)
        {
            if(max<freq[i])
            {
                max=freq[i];
                c=i;
            }
        }

    printf("The most frequent character is %c\n",c);
}
int main()
{
    char s[100];
    printf("Enter the string\n");
    scanf("%[^\n]",s);
    find_repeated_char(s);

}