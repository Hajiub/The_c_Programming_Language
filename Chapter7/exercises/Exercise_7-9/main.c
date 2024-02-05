#include <stdio.h>
#include <string.h>

int v1_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

int v2_isupper(int c)
{
    return (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", c) != NULL);
}


int main(void)
{
    char c = 'A';
    printf("%i\n", v2_isupper(c));
    return 0;
}
