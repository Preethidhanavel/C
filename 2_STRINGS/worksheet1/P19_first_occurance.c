/*19.Program: Find first occurrence of a character in a given string
       Input: "elephant", find 'e'

        Output: Position: 0*/
#include<stdio.h>
void first_occurance(char *a,char c)
{
        int i;
        for(i=0;a[i];i++)
        {
                if(a[i]==c)
                {
                        printf("The character is found at %d\n",i);
                        break;
                }
        }
}
int main()
{
        char a[100],c;
        printf("Enter the string\n");
        scanf(" %[^\n]",a);
        printf("Enter the character\n");
        scanf(" %c",&c);

        first_occurance(a,c);

}