#include <stdio.h>

int is_alpha(int c)
{
    return (c >= 65 && c <= 122);
}
int is_lower(int c)
{ 
    return (c >= 97 && c <= 122);
}

int to_lower(int c)
{
    if(is_alpha(c))
    {
        if(is_lower(c))
            return c;
        return c + 32;
    }
    return c;
}

int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(to_lower(c));
    }
    return 0;
}
