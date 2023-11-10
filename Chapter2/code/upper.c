#include <stdio.h>

int len(const char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void upper(char s[])
{
    int n = len(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 'a' - 'A';
        }
    }
}
int main()
{
    char name[] = "Abrham";
    upper(name);
    printf("%s\n", name);
    return 0;
}