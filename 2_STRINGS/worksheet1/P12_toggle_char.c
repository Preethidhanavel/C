/*12.Program: Toggle case of each character of a string
         Input: "HeLLo"

         Output: "hEllO"*/
#include<stdio.h>
void toggle_character(char *s)
{
        int i;
        for(i=0;s[i];i++)
        {
                if(( (s[i]>='A')&&(s[i]<='Z'))||((s[i]>='a')&&(s[i]<='z')))
                        s[i]=s[i]^32;
        }
}
int main()
{
        char a[100];
        printf("Enter the string\n");
        scanf(" %[^\n]",a);
        toggle_character(a);
        printf("After toggling %s\n",a);

}