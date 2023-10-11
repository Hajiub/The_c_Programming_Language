/*  
    Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
*/
#include <stdio.h>

#define MAX_CHARS 128 

int main()
{
    int c;
    int chars_len[MAX_CHARS] = {0};

    while ((c = getchar()) != EOF)
    {
        if (c >= 0 && c < MAX_CHARS)
        {
            chars_len[c]++;
        }
    }

    for (int i = 32; i < MAX_CHARS; i++)
    {
        if (chars_len[i] > 0)
        {
            printf("%c  | ", i);
            for (int j = 0; j < chars_len[i]; j++)
            {
                printf("* ");
            }
            putchar('\n');
        }
    }
    
    
    if (chars_len['\t'] > 0)
    {
        printf("\\t | ");
        for (int j = 0; j < chars_len['\t']; j++)
        {
            printf("* ");
        }
        putchar('\n');
    }
    
    if (chars_len['\n'] > 0)
    {
        printf("\\n | ");
        for (int j = 0; j < chars_len['\n']; j++)
        {
            printf("* ");
        }
        putchar('\n');
    }

    return 0;
}
