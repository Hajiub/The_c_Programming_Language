/*
Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
    instead of array indexing. Good possibilities include getLine (Chapters 1 and 4), atoi, itoa,
    and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
    (Chapter 4).
*/
#include <stdio.h>


size_t strlen(char *s)
{
    char *p = s;
    while (*p)
        p++;
    return (size_t)(p - s);
}

size_t getLine (char *buffer, int lim)
{
    char *p;
    int c;
    for (p = buffer; (p - buffer) < lim && (c = getchar()) != EOF && c != '\n'; p++)
    {
        *p = c;
    }
    *p = '\0';
    return (size_t) (p - buffer);
}

int isSpace(const char c)
{
    return c ==' ' || c == '\t' || c == '\n' || c == '\r';
}

int isDigit(const char c)
{
    return c >= '0' && c <= '9';
}
/* Convert a string to an integer. */
int atoi(char *p)
{
    int n, sign;
    while (isSpace(*p))
        p++;
    
    sign = (*p == '-') ? - 1: 1;
    if (*p == '+' || *p == '-')
        p++;
    
    for (n = 0; isDigit(*p); p++)
        n = 10 * n + (*p - '0');
    return n * sign;
}

/* Convert an integer to a string. */
char *itoa(int n)
{
    
    static char buf[16];
    char *p = buf + 15;
    *p = '\0';
    int sign;
    if ((sign = n) < 0)
    {
        n = -n;
    }
    do
    {
        *--p = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
    {
        *p = '-';
    }
    return p;
}

void reverse(char *s)
{
    char *s1, *s2;
    char temp;
    s1 = s;
    s2 = s + strlen(s1) - 1;
    while (s1 < s2)
    {
        temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        s1++;
        s2--;
    }
}

void itoa_(int n, char *t)
{
    int sign;
    char *s = t;
    if ((sign = n) < 0)
    {
        n = -n;
    }
    do
    {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
    {
        *s++ = '-';
    }
    *s = '\0';
    reverse(t);
}
/* Return a pointer to the first occurrence of character __c in string __s. */
char *strindex(char *__s, int __c)
{
    size_t s_len = strlen(__s);
    char *p = __s;
    while ((size_t)(p - __s) < s_len)
    {
        if (*p == __c)
            return p;
        p++;
    }
    return NULL;
}

int main() 
{
    char *result;
    char s[] = "Hello, world";
    char c = 'w';
    result = strindex(s, c);
    if (result == NULL)
    {
        return -1;
    }
    printf("%s\n", result);
    return 0;
}
