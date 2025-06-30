//2.Find the first non-repeating character in a given string
//Identify the first character that does not repeat anywhere else in the string, optimizing for time and space complexity.
//Example: Input: "swiss"
//Output: 'w'

#include<stdio.h>
void find_nonrepeated_char(char *s)
{
      int i,freq[256]={0};
      for(i=0;s[i];i++)
         freq[s[i]]++;
      for(i=0;s[i];i++)
      {
         if(freq[s[i]]==1){
         printf("The first non_Repeating character is %c\n",s[i]);
         break;
         }
      }

}
int main()
{
      char s[100];
      printf("Enter the string\n");
      scanf("%[^\n]",s);
      find_nonrepeated_char(s);

}