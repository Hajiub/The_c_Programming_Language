/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
               write a program that reverses its input a line at a time. 
*/
#include <stdio.h>

#define MAXLINE 1000

int getLine(char *, int);
void reverse(char *, int);

int main()
{
    int c, len;
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)))
    {
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}

int getLine(char *s, int max)
{
    int i, c;
    for (i = 0; i  < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}
void reverse(char *s, int len)
{
    int i, j;
    j = len - 1; 
    char temp;
    for (i = 0; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
