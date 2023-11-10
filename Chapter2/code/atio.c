#include <stdio.h>


int atio(char *);

int main()
{
    char digits[] = "12345";
    printf("%i\n", atio(digits));
    
    char nonDigits[] = "abc";
    printf("%i\n", atio(nonDigits));
}
int atio(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i]  >= '0' && s[i] <= '9'; i++)
    {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}