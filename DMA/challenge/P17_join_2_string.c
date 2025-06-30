/*Write a function that joins two strings together using dynamic memory allocation. 
Make sure your code works if either string is empty or NULL.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* joinStrings(const char *str1,const char *str2)
{
    if(str1==NULL) str1="";
    if(str2==NULL) str2="";
    int len1=(int)strlen(str1);
    int len2=(int)strlen(str2);
    char *result=malloc(len1+len2+1);
    if(result==NULL) 
      return NULL;
    memcpy(result,str1,len1);
    memcpy(result+len1,str2,len2);
    result[len1+len2]='\0';
    return result;
}

int main()
{
    char *s1="Hello, ";
    char *s2="World!";
    char *joined=joinStrings(s1,s2);
    if(joined!=NULL)
    {
        printf("%s\n",joined);
        free(joined);
    }
    
}
