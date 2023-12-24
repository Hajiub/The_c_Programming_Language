/* 
Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.
*/
#include <stdio.h>

typedef char * string;

size_t strlen(const string s)
{
    string p = s;
    while (*p)
        p++;
    return (size_t)(p - s);
}

int strend(string s, string t)
{
    size_t s_len = strlen(s);
    size_t t_len = strlen(t);
    
    if (t_len > s_len)
    {
        return 0;
    }

    size_t p = s_len - t_len;
    s += p;
    

    while (*s++ == *t++)    
        if( *t == '\0')
            return 1;
        
    return 0;
}

int main()
{
    string s = "hello, world";
    string t = "world";
    int result = strend(s, t);
    printf("%d\n", result);
    return 0;
}
