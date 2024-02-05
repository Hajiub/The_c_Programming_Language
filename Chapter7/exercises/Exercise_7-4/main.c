#include <stdio.h>
#include <stdarg.h>

int minscanf(const char *fmt, ...) {
    va_list ap;
    const char *p;
    void *ptr;
    int count = 0;  // Number of items successfully matched and assigned

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            continue;
        }

        switch (*++p) {
            case 'u':
                ptr = va_arg(ap, unsigned int *);
                count += scanf("%u", (unsigned int *)ptr);
                break;
            case 'o':
                ptr = va_arg(ap, unsigned int *);
                count += scanf("%o", (unsigned int *)ptr);
                break;
            case 'd':
            case 'i':
                ptr = va_arg(ap, int *);
                count += scanf("%d", (int *)ptr);
                break;
            case 'x':
            case 'X':
                ptr = va_arg(ap, unsigned int *);
                count += scanf("%x", (unsigned int *)ptr);
                break;
            case 'e':
            case 'g':
            case 'G':
            case 'f':
                ptr = va_arg(ap, double *);
                count += scanf("%lf", (double *)ptr);
                break;
            case 'c':
                ptr = va_arg(ap, int *);
                count += scanf(" %c", (char *)ptr);
                break;
            case 's':
                ptr = va_arg(ap, char *);
                count += scanf("%s", (char *)ptr);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);

    return count;
}
int main(void)
{
    int x;
    printf("Enter a number: ");
    minscanf("%i", &x);
    printf("%i\n", x);
    return 0;
}
