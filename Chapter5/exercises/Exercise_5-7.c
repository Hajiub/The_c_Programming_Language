/*
Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
    calling alloc to maintain storage. How much faster is the program?
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLINE_LEN 1000

char lines[MAXLINES][MAXLINE_LEN];

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar())!= EOF && c!= '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i] = c;

    s[i] = '\0';

    return i;
}

int readlines(char lines[][MAXLINE_LEN], int maxlines)
{
    int len, nlines;
    while ((len = getLine(lines[nlines], MAXLINE_LEN)) > 0)
    {
        if (nlines >= maxlines) 
            return -1;
        
        else
            lines[nlines++][len - 1] = '\0';
    }
    return nlines;
}

int main(void)
{
    int nlines;
    nlines = readlines(lines, MAXLINES);
    for (int i  = 0; i < nlines; i++)
    {
        printf("%s\n", lines[i]);
    }
    return 0;
}