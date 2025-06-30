//30. Find the longest substring common to two given strings.
//Input: "abcdxyz", "xyzabcd"
//Output: "abcd"


#include<stdio.h>
#include<string.h>
void find_longest_substr(char *str1,char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);
    
    int l = 0;  
    int x = 0; 
    
   
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j <= m; j++) {
         
            char subStr1[j - i + 1];
            strncpy(subStr1, str1 + i, j - i);
            subStr1[j - i] = '\0'; 
            
            
            if (strstr(str2, subStr1)) {
                int len = j - i;
                if (len > l) {
                    l = len;
                    x = i;
                }
            }
        }
    }
    
    if (l > 0) {
        char result[l + 1];
        strncpy(result, str1 + x, l);
        result[l] = '\0';
        printf("Longest Common Substring: %s\n", result);
    } else {
        printf("No common substring found\n");
    }
}


int main()
{
    char s[100];
    printf("Enter the string 1\n");
    scanf("%s",s);
    char p[100];
    printf("Enter the string 2\n");
    scanf("%s",p);
    find_longest_substr(s,p);

}