//7.Remove from the first string all characters that appear in the second string.
//Input: str1 = "hello world", str2 = "low"
//Output: "he rd"
#include<stdio.h>
void remove_strchar_main(char *str1,char *str2)
{
 int i, j, k = 0;

    for (i = 0; str1[i]; i++) 
    {
        int found = 0;
        for (j = 0; str2[j]; j++) 
        {
            if (str1[i] == str2[j]) 
            {
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            str1[k++] = str1[i]; 
        }
    }
    str1[k] = '\0';

    printf("Result: \"%s\"\n", str1);    

}
int main()
{
        char a[100],b[100];
        printf("Enter the string 1 and substring\n");
        scanf("%[^\n] %[^\n]",a,b);
        remove_strchar_main(a,b);
        printf("After removing %s\n",a);

}
