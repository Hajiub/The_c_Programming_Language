#include <stdio.h>

/* strlen: return length of string s */
size_t strlen(const char *s)
{
    size_t n;
    
    for (n = 0; *s; s++)
        n++;
    
    return n;
}
size_t strlen_v2(const char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;
    return (size_t)(p - s);
}
size_t strlen_v3(const char *s)
{
    char *p = s;
    while (*p++);
    return (size_t)(p - s);
}
int main(void)
{
    char *s = "Hello"; // 5
    size_t len = strlen(s);
    printf("%li\n", len);
    return 0;
}