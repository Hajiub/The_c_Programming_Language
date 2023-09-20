#include <stdio.h>

/*
read a character
while (charater is not end-of-file indicator)
    output the character just read
    read a character
*/

int main(int argc, char **argv)
{
    int c;
    while((c = getchar()) != EOF)
    {
        putchar(c);
    }
    return 0;
}