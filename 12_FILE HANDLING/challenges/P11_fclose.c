/*11.What are the consequences of not closing a file in C? 
Describe what can go wrong in a long-running server application and how to monitor and prevent such issues.*/

#include<stdio.h>
int main()
{
    FILE* fp = fopen("test1.txt","r");
    char ch;
    while((ch=fgetc(fp))!=EOF)
    printf("%c",ch);

    fclose(fp);//To Prevent Consequences of not Closing a File
}