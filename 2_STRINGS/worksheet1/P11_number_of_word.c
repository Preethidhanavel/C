/*11.Program: Count total number of words in a string
          Input: "C programming is fun"

          Output: 4*/
#include<stdio.h>
#include<string.h>
void count_word(char *s)
{
        int i,c=1;

        for(i=0;s[i];i++)
        {
            if(s[i]==' ')
                c++;
        }
        printf("The number of words  %d\n",c);
}
void remove_space(char *a)
{
        int i,k;
        for(i=0;a[i];i++)
        {
                if((a[i]==' ')&&(a[i+1]==' '))
                {
                        for(k=i;a[k];k++)
                                a[k]=a[k+1];
                        i--;
                }
                if((i==0)||(i==strlen(a)-1))
                {
                        if(a[i]==' ')
                                for(k=i;a[k];k++)
                                        a[k]=a[k+1];
                }

        }

}
int main()
{
        char a[100];
        printf("Enter the string\n");
        scanf(" %[^\n]",a);

        remove_space(a);
        count_word(a);

}