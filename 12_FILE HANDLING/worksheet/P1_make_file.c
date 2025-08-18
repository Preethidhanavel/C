/*1.Make a new file and save some text entered by the user.
Input: File name: test.txt
Text: Hello, this is my first file!
Output: File 'test.txt' created and saved.*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *f=malloc(100*sizeof(char));
    if(f==NULL) return 0;
    printf("File name:");
    scanf(" %s",f);
    FILE *fp=fopen(f,"w");
    if(fp==NULL)
    {
        perror("fopen");
        return 0;
    }
    char *s=malloc(1000*sizeof(char));
    if(s==NULL)
    return 0;
    printf("enter the data to be written in file\n");
    scanf(" %[^\n]",s);
    fprintf(fp,"%s",s);
    printf("File test.txt successfully created and saved\n");
    free(s);
    s=NULL;
}