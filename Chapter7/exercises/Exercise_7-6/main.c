#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

void panic(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr,fmt, ap);
    va_end(ap);
    exit(1);
}


int main(int ac, char **av)
{
    char *prog = av[0];
    if(ac < 3)
        panic("Usage %s <file_name1> <file_name2>\n", prog);

    FILE *f1 = fopen(av[1], "r");
    FILE *f2 = fopen(av[2], "r");

    if (f1 == NULL)
        panic("%s: %s: No such file or directory\n", prog, av[1]);
    else if (f2 == NULL)
        panic("%s: %s: No such file or directory\n", prog, av[2]);
    
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line1, MAX_LINE_LENGTH, f1) != NULL && fgets(line2, MAX_LINE_LENGTH, f2) != NULL)
    {
        line_number++;
        
        if (strcmp(line1, line2) != 0)
        {
            printf("Files differ at line %d:\n", line_number);
            printf("File 1: %s", line1);
            printf("File 2: %s", line2);
            break;
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
