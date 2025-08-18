//10.Print all permutations of a string in lexicographic order
//Generate and print every permutation of the given string sorted alphabetically.
//Example: Input: "abc"
//Output: "abc", "acb", "bac", "bca", "cab", "cba"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *s1[100];

void swap(char* a,char* b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
static int x=0;
void permutation(char* s,int k,int l)
{
    
    
    if(k == l)
    {
        s1[x]=malloc(100);
       // printf("%s\n",s);
        strcpy(s1[x],s);
        x++;
    }
    else
    {
       
        for(int i=k;i<=l;i++)
        {
            swap(&s[k],&s[i]);
            permutation(s,k+1,l);
            swap(&s[k],&s[i]);
        }
    }
}
void sort(char **res,int x)
{
    int i,j;
    char *temp;
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<x-i-1;j++)
        {
            if(strcmp(res[j],res[j+1])>0)
            {
                temp=res[j];
                res[j]=res[j+1];
                res[j+1]=temp;
            }
        }
    }
}
int main()
{
    char s[100];
    printf("Enter the  string\n");
    scanf("%s",s);
    permutation(s,0,strlen(s)-1);
    sort(s1,x);
     for(int i=0;i<x;i++)
    printf("%s ",s1[i]);
}