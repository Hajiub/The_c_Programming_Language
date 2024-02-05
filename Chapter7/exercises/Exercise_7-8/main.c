#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define PAGE_MAX_LINES 10
#define MAXLINE 8000

void panic(const char *format, ...);
void displayfile(FILE *, FILE *);

int main(int ac, char **av)
{
    FILE *f;
    char *prog = av[0];
    if(ac == 1)
        panic("Usage: %s <file1> <file2> <filen>\n", prog);
    
    while (--ac > 0)
    {
        if ((f = fopen(*++av, "r")) == NULL)    
        { 
            fprintf(stderr,"%s: can't open %s\n", prog, *av);
        }
        else
        {
            fprintf(stdout,"\n\n=================>%s<=================\n\n", *av);
            displayfile(f, stdout);
            fclose(f);
        }
    }
    if (ferror(stdout))
    {
        panic("%s: error writing stdout\n", prog);
    }
    exit(0);
}

void panic(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(1);
}

void displayfile(FILE *fp, FILE *ofp)
{
    int nl, pg;
    nl = 0;
    pg = 1;
    char line[MAXLINE];
   // char *fgets(char *s, int size, FILE *stream);
    while ((fgets(line, MAXLINE, fp)))
    {
        if(++nl == PAGE_MAX_LINES)
        {
            fprintf(ofp, "\n\t\t\tPage %d End.\n\n", pg);
            pg++;
            nl = 0;
        }
        fprintf(ofp,"%s", line);

    }
}
