/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.
*/

#include <stdio.h>

#define MAXLINE 100

int getLine(char s[], int n)
{
    int i, c;
    for (i = 0; i < n && (c = getchar()) != EOF && c != '\n'; i++)
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

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; s[i]; i++)
    {
        switch (s[i])
        {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
        case ' ':
            t[j++] = '\\';
            t[j++] = 's';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
        default:
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}
void unescape(char s[], char t[])
{
    int i, j;
    for (j = i = 0; s[i]; i++)
    {
        if (s[i] == '\\')
        {
            switch (s[++i])
            {
            case 'n':
                t[j++] = '\n';
                break;
            case 's':
                t[j++] = ' ';
                break;
            case 't':
                t[j++] = '\t';
                break;
            default:
                t[j++] = '\\';
                t[j++] = s[i];
            }
        }
        else
        {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}


int main()
{
    int len;
    char line[MAXLINE] = {0};
    char escaped[MAXLINE] = {0};
    char unescaped[MAXLINE] = {0};

    while ((len = getLine(line, MAXLINE)))
    {
        printf("Original: %s", line);

        escape(line, escaped);
        printf("Escaped: %s", escaped);
        putchar('\n');
        unescape(escaped, unescaped);
        printf("Unescaped: %s", unescaped);
    }

    return 0;
}