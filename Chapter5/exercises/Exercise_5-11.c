/*
Exercise 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
    accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.
*/

/*
Exercise 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAB_WIDTH 4

void detab(int tw);
void entab(int tw);

int main(int argc, char **argv) {
    if (argc < 2)
        entab(TAB_WIDTH);
    else
        entab(atoi(argv[1]));
    return 0;
}


void detab(int tw) 
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
	{
            for (int i = 0; i < tw; i++)
	    {
                putchar(' ');
            }
        }
       	else 
	{
            putchar(c);
        }
    }
}

void entab(int tw)
{
    int nb, nt, pos, c;

    nb = 0;
    nt = 0;

    for (pos = 1; (c = getchar()) != EOF; ++pos)
        if (c == ' ') {
            if ((pos % tw) != 0)
                ++nb;
            else {
                nb = 0;
                ++nt;
            }
        } else {
            for (; nt > 0; --nt)
                putchar('\t');
            if (c == '\t')
                nb = 0;
            else
                for (; nb > 0; --nb)
                    putchar(' ');

            putchar(c);

            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                pos = pos + (tw - (pos - 1) % tw) - 1;
        }
}
