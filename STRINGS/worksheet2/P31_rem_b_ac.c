//31.Remove all occurrences of character 'b' and substring "ac" from a string.
//Input: "abacb"
//Output: "a"

#include<stdio.h>
#include<string.h>
void remove_b(char *s)
{
int i,j,k;

            for(i=0;s[i];i++)
        {
                if(s[i]=='b'){
                    for(j=i;s[j];j++)
                        s[j]=s[j+1];
                }
                      
        }
}

void remove_ac(char *s)
{
  char *t;
        while(  (t=strstr(s,"ac"))!=NULL)
            memmove(t,t+2,strlen(t+2)+1);

}
int main()
{ char s[100];
    printf("Enter the string\n");
    scanf("%s",s);
    remove_b(s);
  //  printf("After removing char b  %s\n",s);
     remove_ac(s);
    printf("After removing char b and str ac is  %s\n",s);
}