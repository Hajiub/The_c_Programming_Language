#include <stdio.h>

int Strlen(char s[])
{
    int i = 0;
    while (s[i++]);
    return i - 1;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int temp, i ,j;
    for (i = 0, j = Strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
int main()
{
    char s[] = "Hello, world";
    reverse(s);
    printf("%s\n", s);
}