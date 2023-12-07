#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 10
#define SIZE 100
int buffer[BUFSIZE];

int bfp = 0;
int getch(void);
void ungetch(int);
int getint(int *pn);

int main(void)
{
    int n, array[SIZE];
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    return (bfp > 0) ? buffer[--bfp] : getchar();
}

void ungetch(int c)
{
    if (bfp >= BUFSIZE)
    {
        printf("Error: buffer is full\n");
        return;
    }
    buffer[bfp++] = c;
}
