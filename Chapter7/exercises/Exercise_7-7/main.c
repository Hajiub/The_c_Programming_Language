#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAXLINE 1000
char *getLine(FILE *, char *, int);
void panic(const char *format, ...);
int main(int ac, char **av)
{
    char *prog = av[0];
    FILE *input_stream = stdin;

    if (ac == 1)
        panic("Usage: %s [-f <filename>] -p \"pattern\"\n", prog);
    int fi, pi, n, count;
    fi = pi = count = n = 0;
    for (; count < ac; count++)
    {
        if (av[count][0] == '-')
            switch(av[count][1])
            {
                case 'p':
                    pi = count;
                    break;
                case 'f':
                    fi = count;
                    break;
                case 'n':
                    n = 1;
                default:
                    break;
            }
    }

    if (!pi || !av[pi+1])
        panic("Error: %s: pattern is required!\n", prog);

    if (fi && av[fi + 1])
    {
        input_stream = fopen(av[fi + 1], "r");
        if(!input_stream)
            panic("%s: Erorr opening file %s\n", prog, av[fi + 1]);
    }

    char line[MAXLINE];
    int nline = 0;
    while (getLine(input_stream, line, MAXLINE))
    {
        nline++;
        if (strstr(line, av[pi + 1]))
        {
            if (n)
            {
                printf("%i: %s", nline, line);
            }
            else
                printf("%s", line);
        }
    }
    return 0;
}

char *getLine(FILE *input_stream, char *s, int lim)
{
    //   char *fgets(char *s, int size, FILE *stream); 
    return fgets(s, lim, input_stream);
}


void panic(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(1);
}
