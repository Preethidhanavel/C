/*6.Copy everything from one file and save it into another file.
Input: Source file: lines.txt
Destination file: copy.txt
Output: File 'lines.txt' copied to 'copy.txt'.*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *f1=malloc(100*sizeof(char));
    char *f2=malloc(100*sizeof(char));
    printf("Enter the source file name\n");
    scanf(" %[^\n]",f1);
    printf("Enter the destination file name\n");
    scanf(" %[^\n]",f2);
    FILE *fp1=fopen(f1,"r");
    if(fp1==NULL) return 0;
    FILE *fp2=fopen(f2,"w");
    if(fp2==NULL) return 0;
    char c;
    while((c=fgetc(fp1))!=EOF)
        fputc(c,fp2);
    printf("Data from \"%s\" copied to \"%s\"\n",f1,f2);
}