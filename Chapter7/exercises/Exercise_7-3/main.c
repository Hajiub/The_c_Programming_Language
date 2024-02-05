#include <stdio.h>
#include <stdarg.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    unsigned  uval;
    void *ptr;
    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) 
    {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
            case 'u':
                uval = va_arg(ap, unsigned int);
                printf("%u",uval);
                break;
            case 'o':
                ival = va_arg(ap, unsigned int);
                printf("%o", ival);
                break;
            case 'd':
            case 'i':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'x':
               uval = va_arg(ap, unsigned int);
               printf("%x", uval);
               break;
            case 'X':
               uval = va_arg(ap, unsigned int);
               printf("%X", uval);
               break;
            case 'e':
               dval = va_arg(ap, double);
               printf("%e", dval);
               break;
            case 'g':
            case 'G':
               dval = va_arg(ap, double);
               printf("%g", dval);
               break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 'c':
                ival = va_arg(ap, int);
                putchar(ival);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}


int main() 
{
    minprintf("Testing minprintf:\n");
    
    int intValue = 42;
    minprintf("Integer (decimal): %d\n", intValue);

    unsigned uValue = 123;
    minprintf("Unsigned (decimal): %u\n", uValue);

    minprintf("Octal: %o\n", intValue);
    minprintf("Hexadecimal (lowercase): %x\n", intValue);
    minprintf("Hexadecimal (uppercase): %X\n", intValue);

    double doubleValue = 3.14;
    minprintf("Double (scientific notation): %e\n", doubleValue);
    minprintf("Double (general format): %g\n", doubleValue);
    minprintf("Double (fixed-point notation): %f\n", doubleValue);

    char charValue = 'A';
    minprintf("Character: %c\n", charValue);

    char stringValue[] = "Hello, World!";
    minprintf("String: %s\n", stringValue);

    return 0;
}
