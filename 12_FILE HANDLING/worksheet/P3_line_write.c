/*3.Take several lines from the user and write all of them into a file.
Input: File name: lines.txt
Number of lines: 3
Lines: Line one, Line two, Line three
Output: All lines saved in 'lines.txt'.*/

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
    int n,i;
    printf("Enter the number of lines you want to write\n");
    scanf("%d",&n);
    char *s=malloc(1000*sizeof(char));
    if(s==NULL) return 0;
    for(i=0;i<n;i++)
    {
        scanf(" %[^\n]",s);
        fprintf(fp,"%s",s);
    }
    printf("All lines saved in file\n");
}