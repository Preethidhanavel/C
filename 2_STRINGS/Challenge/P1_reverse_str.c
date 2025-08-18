//1. Reverse a string in-place without using extra memory
//Explain your approach to reversing a string by swapping characters from the start and end moving towards the center, without using extra storage.

//Example: Input: "interview"
//Output: "weivretni"

#include<stdio.h>
#include<string.h>
void reverse(char *s)
{
    char c,i,j;
    for(i=0,j=strlen(s)-1;i<j;i++,j--){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }

}
int main()
{

    char s[100];
    printf("Enter the string\n");
    scanf("%[^\n]",s);
    reverse(s);
    printf("After reversing %s\n",s);
}