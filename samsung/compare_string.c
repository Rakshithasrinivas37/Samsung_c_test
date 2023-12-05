#include <stdio.h>
#include <string.h>
#include<stdbool.h>

int res = 0;

// Function to swap characters at positions i and j in a string
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void isSubsequence(char *str, char *T)
{
    char str1[10] = "\0";
        int num = 0, flag = 1;
        for(int i = 0;str[i] != '\0';i++)
        {
            for(int j = 0;j < num;j++)
            {
                if(str[i] == str1[j])
                {
                    flag = 0;
                }
            }
            if(flag == 1)
            {
                for(int j = 0;T[j] != '\0';j++)
                {
                    if(str[i] == T[j])
                    {
                        str1[num++] = str[i];
                    }
                }
            }
        }
        str1[num] = '\0';
        if(strcmp(str1, T) == 0)
        {
            res = 1;
        }
}


// Function to generate permutations of a string
void generatePermutations(char* str, char *T, int start, int end) 
{
    if (start == end && (strcmp(str, T) != 0)) 
    {
        //printf("%s\n", str);
        isSubsequence(str, T);
        return;
    }

    for (int i = start; i <= end; i++) 
    {
        // Swap the current character with the character at position 'i'
        swap(&str[start], &str[i]);

        // Recursively generate permutations for the remaining characters
        generatePermutations(str, T, start + 1, end);
    }
}

int main() {
    // Example usage:
    int t;
    scanf("%d", &t);

    int res1[t/2];

    for(int i = 0;i < t/2;i++)
    {
        char S[20], T[20];
        scanf("%s", S);
        scanf("%s", T);
        int freq_str[26] = {0};
        
        for(int i = 0;S[i] != '\0';i++)
        {
            freq_str[S[i] - 'a']++;
        }
        int flag = 0;
        if(strcmp(S, T) == 0)
        {
            for(int i = 0;i < 26;i++)
            {
                if(freq_str[i] == strlen(S))
                {
                    flag = 1;
                    res = 1;
                    break;
                }
            }
        }
        if(flag == 0)
        {
            generatePermutations(S, T, 0, strlen(S) - 1);
        }
        res1[i] = res;
    }
    for(int i = 0;i < t/2;i++)
    {
        if(res1[i] == 0)
        {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

