//32.Use dynamic programming to check if a string is an interleaving of two other strings.
//Input: s1 = "abc", s2 = "def", s3 = "adbcef"
//Output: True

#include<stdio.h>
#include<string.h>
int check_str_interleave(char *a,char *b)
{
      int i,j,c=0;
      for(i=0;a[i];i++)
      {
      for(j=0;b[j];j++)
      {
         if(a[i]==b[j])
         c++;
      }
      if(c==strlen(a))
      return 1;
      else 
      return 0;
      }

}
int main()
{
      char s1[100],s2[100],str[200];
      printf("Enter the string s1 , s2\n");
      scanf("%s %s",s1,s2);
      printf("Enter the string str\n");
      scanf("%s",str);
      printf("The string %s  %s  %s\n",s1,s2,str);
      int n1=check_str_interleave(s1,str);
      int n2=check_str_interleave(s2,str);
      if(n1==n2)
      printf("True\n");
      else
      printf("false\n");
}