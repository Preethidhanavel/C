/*9.Count how many lines are present in a text file.
Input: File name: lines.txt
Output: Total lines: 5*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *f=malloc(100*sizeof(char));
    if(f==NULL)
    return 0;
    printf("Enter the file name\n");
    scanf("%s",f);
    FILE*fp=fopen(f,"r");
    if(fp==NULL){
        printf("file doesn't exists\n");
        return 0;
    }
    char c;
    int line=0;
    while((c=fgetc(fp))!=EOF){
        if(c=='\n')
            line++;
    }

    printf("The number of lines present in the file %d\n",line);
}