#include <stdio.h>
#include <stdarg.h>


void panic(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    //int vfprintf(FILE *stream, const char *format, va_list ap);  
    vfprintf(stdout, format, ap);
    va_end(ap);
    return;
}

int main(void)
{
    panic("Ivalid name %s\n", "Abraham");
    return 0;
}
