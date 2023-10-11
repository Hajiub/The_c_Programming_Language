/*
    Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. 
*/
#include <stdio.h>

#define MAXLINE 1000
int getLine(char line[], int max);

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > 80)
        {
            printf("%s", line);
        }
    }
}

int getLine(char s[], int max)
{
    int i, c;
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}