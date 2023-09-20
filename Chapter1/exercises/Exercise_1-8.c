// Write a program to count blanks, tabs, and newlines.
#include <stdio.h>

int main()
{
    const char *message = "Number of";

    int c, bl, tb, nl;
    bl = tb = nl = 0;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            ++bl;
        }
        else if (c == '\t')
        {
            ++tb;
        }
        else if (c== '\n')
        {
            ++nl;
        }
    }
    printf("%s blanks is: %d\n", message, bl);
    printf("%s tabs is: %d\n", message, tb);
    printf("%s new lines is: %d\n", message, nl);

    return 0;    
}