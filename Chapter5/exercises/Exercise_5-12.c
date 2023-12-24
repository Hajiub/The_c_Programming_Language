/*
Exercise 5-12. Extend entab and detab to accept the shorthand
entab -m +n
to mean tab stops every n columns, starting at column m. Choose convenient (for the user)
default behavior.
*/
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_WIDTH 4

void detab(int);
void entab(int, int, int);

int main(int argc, char **argv) {
    int m, n;

    if (argc < 2) {
        entab(1, DEFAULT_TAB_WIDTH, 0);
    } else if (argc == 2 && sscanf(argv[1], "-%d +%d", &m, &n) == 2) {
        entab(m, n, 1);
    } else {
        fprintf(stderr, "Usage: %s [-m +n]\n", argv[0]);
        return 1;
    }

    return 0;
}

void detab(int tw) {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0; i < tw; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
}

void entab(int start, int step, int shorthand) {
    int nb, nt, pos, c;

    nb = 0;
    nt = 0;
    pos = 1;

    for (; (c = getchar()) != EOF; ++pos) {
        if (c == ' ') {
            if ((pos % step) != 0) {
                ++nb;
            } else {
                nb = 0;
                ++nt;
            }
        } else {
            for (; nt > 0; --nt) {
                if (shorthand && pos > start) {
                    putchar('\t');
                    pos = pos + step - 1;
                } else {
                    putchar(' ');
                }
            }
            if (c == '\t') {
                nb = 0;
            } else {
                for (; nb > 0; --nb) {
                    putchar(' ');
                }
            }

            putchar(c);

            if (c == '\n') {
                pos = 0;
            } else if (c == '\t') {
                pos = pos + (step - (pos - start) % step) - 1;
            }
        }
    }
}
