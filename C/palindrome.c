#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHUNK 1024

void trim(char *line)
{
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}

void printPalindrome(char* str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        printf("%c", str[i]);
}
 
// This function prints the longest palindrome substring (LPS) of str[]. It also returns the length of the longest palindrome
void longestPalindrome(char* str)
{
    int size = strlen(str);
    if (size < 2)
        return; 
 
    int maxLength = 1, start = 0;
    int left, right;
    
    for (int i = 0; i < size; i++) {
        left = i - 1;
        right = i + 1;
        
        while (right < size && str[right] == str[i])
            right++;
 
        while (left >= 0 && str[left] == str[i])
            left--;

        // Simetric palindrome
        while (left >= 0 && right < size && str[left] == str[right]) {
            left--;
            right++;
        }
 
        int length = right - left - 1;
        if (maxLength < length) {
            maxLength = length;
            start = left + 1;
        }
    }
    
    printPalindrome(str, start, start + maxLength - 1);
    printf(" - Size: %d\n", maxLength);
}

int main()
{
    FILE* fp;
    char line[CHUNK];
    fp = fopen("palindromes.txt", "r");
    //Run interactively over every line
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        trim(line);
        longestPalindrome(line);
    }
    fclose(fp);
    system("pause");
    return 0;
}