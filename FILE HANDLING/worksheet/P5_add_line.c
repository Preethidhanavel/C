/*5.Add more lines to the end of a file without erasing its current content.
Input: File name: lines.txt
Number of new lines: 2
New lines: Line four, Line five
Output: File now contains: Line one, Line two, Line three, Line four, Line five*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *f=malloc(1000*sizeof(char));
    if(f==NULL) return 0;
    printf("Enter the file name\n");
    scanf(" %s",f);
    FILE *fp=fopen(f,"a");
    if(fp==NULL)
    {
        perror("fopen");
        return 0;
    }
    int n,i;
    printf("Enter the number of new lines\n");
    scanf("%d",&n);
    char *s=malloc(1000*sizeof(char));
    if(s==NULL)
    return 0;
    for(i=0;i<n;i++)
    {
        printf("Enter th new line\n");
        scanf(" %[^\n]",s);
        fprintf(fp,"%s",s);
    }
    printf("file now contains new line content also\n");

}