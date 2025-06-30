//1.Swap the contents of two strings without using any extra temporary string variables. The strings' values should be exchanged completely.
//Input: str1 = "hello", str2 = "world"
//Output: str1 = "world", str2 = "hello"


#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{ 
                int i;    
                int n=strlen(a);
                    for(i=0;i<n;i++)
                    {
                        a[i]=a[i]^b[i];
                        b[i]=a[i]^b[i];
                        a[i]=a[i]^b[i];
                    }
        
}
int main()
{
        char s1[100],s2[100];
        printf("Enter the string s1,s2\n");
        scanf("%s%s",s1,s2);
        printf("Before swapping string1:%s\nstring2:%s\n",s1,s2);
        if(strlen(s1)==strlen(s2))
        {
            swap(s1,s2);
            printf("After swapping string1:%s\nstring2:%s\n",s1,s2);
        }
        else
            printf("Size doesn't match\n");

}
 
    