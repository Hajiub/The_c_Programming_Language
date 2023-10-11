/* 
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
               easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/
#include <stdio.h>

#define MAXLEN 10
#define IN 1
#define OUT 0

int main(int argc, char *argv[])
{
    int c, state, wl;
    int words_len[MAXLEN] = {0};
    state = OUT;
    wl  = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (wl  <= MAXLEN && state)
            {
                words_len[wl]++;
                wl = 0;
                state = OUT;
            }
        }
        else
        {
            ++wl;
            state = IN;
        }
    }
    for (int i = 1; i <= MAXLEN; i++)
    {
        printf("%i ", i);
        for (int j = 0; j < words_len[i]; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}