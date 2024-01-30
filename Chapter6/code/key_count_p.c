#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

struct key {
    char *word;
    int count;
} keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"return", 0},
    {"short", 0},
    {"signed", 0},
    {"sizeof", 0},
    {"static", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0}
};

int getword(char *, int);
struct key *
binsearch(char *, struct key *, int);

/* count c keywords */
int main(void)
{
    int n, c;
    char word[MAXWORD];
    struct key *p;
    while ((c = getword(word, MAXWORD))!= EOF && c != 'q')
        if (isalpha(word[0]))
            if ((p=binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;

    for (n = 0; n < (int) NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%d %s\n",
                    keytab[n].count, keytab[n].word);
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *
binsearch(char *word, struct key tab[], int n)
{
    int cond;
    struct key *low, *high, *mid;
    low = tab;
    high = tab + n;
    while (low < high)
    {
        mid = low + (high-low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else 
            return mid;
    }
    return NULL;
}


/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    else
        return c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
 
#define MAX_BUFF 100
static char buffer[MAX_BUFF];
int bp = 0;

int getch(void)
{
    return (bp > 0) ? buffer[--bp] : getchar();
}

void ungetch(int c)
{
    if (bp < MAX_BUFF)
        buffer[bp++] = c;
}
