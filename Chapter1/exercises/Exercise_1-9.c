/* 
Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.
*/
#include <stdio.h>

#define true 1
#define false 0

int main() {
    int c, lastCharWasSpace;
    lastCharWasSpace = false;

    while ((c = getchar()) != EOF) 
    {
        if (c == ' ')
        {
            if(!lastCharWasSpace)
            {
                putchar(c);
                lastCharWasSpace = true;
            }
        }
        else
        {
            putchar(c);
            lastCharWasSpace = false;
        }

    }

    return 0;
}
