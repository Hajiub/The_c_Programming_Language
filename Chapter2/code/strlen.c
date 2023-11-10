#include <stdio.h>

const int stringlen(const char *);

int main()
{
    char *s = "h";
    printf("%i\n", stringlen(s));
    return 0;
}

const int stringlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    return i;
}