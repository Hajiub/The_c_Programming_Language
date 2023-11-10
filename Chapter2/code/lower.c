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

void lower(char s[])
{
    int n = len(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 'a' - 'A';
        }
    }
}

int main()
{
    char name[] = "Abrham";
    lower(name);
    printf("%s\n", name);
    return 0;
}
