//10.Print all permutations of a given string. All possible arrangements of characters should be printed.
//Input:"ABC"
//Output:"ABC","ACB","BAC","BCA","CAB","CBA"

#include<stdio.h>
#include<string.h>

void swap(char* a,char* b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char* s,int k,int l)
{
    if(k == l)
    {
        printf("%s\n",s);
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

int main()
{
    char s[100];
    printf("Enter the  string\n");
    scanf("%s",s);
    permutation(s,0,strlen(s)-1);

}