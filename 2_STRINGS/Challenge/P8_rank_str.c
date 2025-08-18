//8.Find the lexicographic rank of a string (with duplicates)
//Calculate the position of the string in the sorted list of all its permutations.
//Example: Input: "string"
//Output: 598


#include <stdio.h>
#include<string.h>


int fact(int n) { 
    int res = 1;
    for (int i = 2; i <= n; i++) 
    {
         res *= i; 
    }
    return res;
}


int findSmallerInRight(char* str, int low) {
    int countRight = 0;
    for (int i = low + 1; str[i]; i++)
        if (str[i] < str[low])
            ++countRight;
    return countRight;
}

int findRank(char * str) {
    int n = strlen(str);
    
    int rank = 1;  
    int countRight;

    for (int i = 0; i < n; ++i) {
        countRight = findSmallerInRight(str, i);

        rank += countRight * fact(n - i - 1);
    }

    return rank;
}

int main() {
    char str[100];
    printf("Enter the string\n");
    scanf("%s",str);
    printf("%d \n",findRank(str));
    return 0;
}