/*4.Read every line from a file and store those lines in an array.
Input: File name: lines.txt
Output: Line one, Line two, Line three (as array elements)*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *f=malloc(100*sizeof(char));
    if(f==NULL) return 0;
    printf("Enter the file name\n");
    scanf(" %s",f);
    FILE *fp=fopen(f,"r");
    if(fp==NULL)
    {
        perror("fopen");
        return 0;
    }
    char *s=malloc(1000*sizeof(char));
    if(s==NULL) return 0;
    int i=0;
    char c;
    while((c=fgetc(fp))!=EOF)
        s[i++]=c;
    s[i]='\0';
    printf("The data read from file\n");
    printf("%s\n",s);
}