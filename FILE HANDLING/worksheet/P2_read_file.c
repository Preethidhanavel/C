/*2.Open an existing file and display its contents on the screen.
Input: File name: test.txt
Output: Hello, this is my first file!*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *f=malloc(100*sizeof(char));
    if(f==NULL) return 0;
    printf("File name:");
    scanf(" %s",f);
    FILE *fp=fopen(f,"r");
    if(fp==NULL)
    {
        perror("fopen");
        return 0;
    }
    char c;
    while((c=fgetc(fp))!=EOF)
        printf("%c",c);
    printf("\n");
}