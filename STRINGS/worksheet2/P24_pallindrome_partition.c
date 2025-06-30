//24.Partition a string into the minimum number of palindromic substrings (Palindrome Partitioning).
//Input: "ababbbabbababa"
//Output: 3
#include <stdio.h>
#include <limits.h>
#include<string.h>


int is_Palindrome(char * s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}


int pal_Partition_Recursion(char * s, int i, int j) {
  
    
    if (i >= j || is_Palindrome(s, i, j))
        return 0;

    int res = INT_MAX, cuts;

    for (int k = i; k < j; k++) {
        cuts = 1 + pal_Partition_Recursion(s, i, k)+ pal_Partition_Recursion(s, k + 1, j);
        if(cuts<res)
        res=cuts;
    }

    return res;
}

int pal_Partition(char *s) {
  	return pal_Partition_Recursion(s, 0, strlen(s)-1);
}

int main() {
    char s[100];
    printf("Enter the string\n");
    scanf("%s",s);

    printf("%d\n",pal_Partition(s));

}