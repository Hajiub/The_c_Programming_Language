/*
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
*/
#include <stdio.h>

#define MAXLINE 1000
int getLine(char *, int);

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        printf("%s", line);
    }
}

int getLine(char *line, int lim)
{
    int c, i;
    c = getchar();
    
    for (i = 0; i < lim - 1; i++)
    {
        if (c == EOF)
        {
            break;
        }
        
        if (c == '\n')
        {
            break;
        }
        
        line[i] = c;
        c = getchar();
    }
    
    if (c == '\n')
    {
        line[i++] = '\n';
    }
    
    line[i] = '\0';
    return i;
}
