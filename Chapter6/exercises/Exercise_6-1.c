/* Exercise 6-1. 
*  Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control
*  line. write a better version.
*/

#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
int getword(char *, int);
int main(void)
{
    char word[MAXWORD];
    int c;
    while ((c = getword(word, MAXWORD)) != EOF && c != 'q')
        if (isalpha(c))
            printf("%s\n", word);
}


int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF) {
        *w++ = c;
    } else {
        return c;
    }

    if (!isalpha(c))
    {
        if (c == '/')
        {
            if ((c = getch()) == '/')
                while ((c = getch()) != '\n');
            else if (c == '*') {
                for (c = getch(); c != '*' && (c = getch()) != '/'; );
            }
        }
        else if (c == '#') 
        {
            while ((c = getch()) != '\n');
        }
        else if (c == '\"')
        {
            for (c = getch(); c != '\"'; c = getch());
        }

        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

#define MAXBUFF 100
static char buffer[MAXBUFF];
static int bp = 0;

int getch(void)
{
   return (bp > 0) ? buffer[--bp] : getchar();
}

void ungetch(int c)
{
    if (bp <  MAXBUFF)
        buffer[bp++] = c;
}
