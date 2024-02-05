#include <stdio.h>
#include <stdarg.h>

// int scanf(const char *format, ...);
// scnaf("%i", &x);
void miniscanf(char *fmt, ...)
{
    va_list ap;
    char *p;
    int *ival;

    va_start(ap, fmt);
    p = fmt;
    switch(*++p)
    {
        case 'i':
        case 'd':
            ival = va_arg(ap, int *);
            scanf("%i", ival);
        default:
            break;
    }

}

int main(void)
{
    int x;
    printf("Enter a number: ");
    miniscanf("%i", &x);
    printf("%i\n", x);
    return 0;
}
