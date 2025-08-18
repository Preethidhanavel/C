//21.Check if a string is an interleaving of two other strings, i.e., formed by merging them maintaining order.
//Input: s1 = "abc", s2 = "def", s3 = "adbcef"
//Output: True


#include <stdio.h>
#include <string.h>

int check_Interleaved(char *s1, char *s2, char *s3, int i, int j, int k) {
    if (s3[k] == '\0') {
        return (s1[i] == '\0' && s2[j] == '\0') ? 1 : 0;
    }

    int result = 0;

    if (s1[i] != '\0' && s1[i] == s3[k]) {
        result = check_Interleaved(s1, s2, s3, i + 1, j, k + 1);
    }

    if (!result && s2[j] != '\0' && s2[j] == s3[k]) {
        result = check_Interleaved(s1, s2, s3, i, j + 1, k + 1);
    }

    return result;
}

int main() {
    char s1[100], s2[100], s3[200];

    printf("Enter the string 1\n");
    scanf("%[^\n]", s1);
    printf("Enter the string 2\n");
    scanf(" %[^\n]", s2);
    printf("Enter the string 3\n");
    scanf(" %[^\n]", s3);

    if (strlen(s3) != strlen(s1) + strlen(s2)) 
    {
        printf("Output: False\n");
    } else if (check_Interleaved(s1, s2, s3, 0, 0, 0))
    {
        printf("Output: True\n");
    }
     else
    {
        printf("Output: False\n");
    }

    return 0;
}