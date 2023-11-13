#include <stdio.h>
#include <string.h>

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n;
    
    for (n = strlen(s) - 1; n >= 0; n--)
    {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        {
            break;
        }
    }
    s[n + 1] = '\0';
    return n;
}

int main() {
    char exampleString[] = "  Hello, world!    \t\n";
    
    int lastIndex = trim(exampleString);
    
    printf("Trimmed String: \"%s\"\n", exampleString);
    printf("Last non-whitespace character index: %d\n", lastIndex);

    return 0;
}