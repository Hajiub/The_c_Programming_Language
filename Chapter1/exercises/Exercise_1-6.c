// Verify that the expression getchar() != EOF is 0 or 1.
#include <stdio.h>
/*
    1. If getchar() successfully reads a character (not EOF), the expression becomes 1 because getchar() != EOF is true.
    2. If getchar() encounters the EOF character (commonly represented as -1 in ASCII), the expression becomes 0 because
    getchar() != EOF is false.
*/
int main()
{
    int c;
    while((c = getchar()) != EOF)
    {
        putchar(c);
    }
}