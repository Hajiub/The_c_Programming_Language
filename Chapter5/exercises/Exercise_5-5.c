/*
Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
    operate on at most the first n characters of their argument strings. For example,
    strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
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

/* Copy no more than N characters of SRC to DEST. */
string strncpy(string dest, string src, size_t n)
{
    string p = dest;
    while (n > 0 && (*dest++ = *src++)) 
    {
        n--;
    }
    return p;
}

/* Append no more than N characters from SRC onto DEST. */
string strncat(string dest, string src, size_t n)
{
    size_t d_len = strlen(dest);
    char *p = dest + d_len; // Set p to the end of the destination string
    while (n > 0 && (*p++ = *src++))
    {
        n--;
    }
    return dest;
}


/* Compare N characters of S1 and S2. */
int strncmp(const string s1, const string s2, size_t n)
{
    char *s, *t;
    s = s1;
    t = s2;

    while(n > 0 && (*s++ == *t++))
    {
        if (*s == '\0')
            return 0;
        n--;
    }
    return (n == 0) ? 0: *s1 - *s2;
}


int main()
{
    // Example usage of strncpy
    char source[] = "Hello, World!";
    char destination[20];

    // Copy up to 10 characters from source to destination
    strncpy(destination, source, 10);

    // Print the result
    printf("strncpy Result: %s\n", destination);

    // Example usage of strncat
    char dest_cat[20] = "Hello, ";
    char source_cat[] = "World!";

    // Concatenate up to 5 characters from source_cat onto dest_cat
    strncat(dest_cat, source_cat, 5);

    // Print the result
    printf("strncat Result: %s\n", dest_cat);

    // Example usage of strncmp
    char str1[] = "Hello";
    char str2[] = "Hellp";

    // Compare up to 4 characters of str1 and str2
    int result = strncmp(str1, str2, 4);

    // Print the result
    printf("strncmp Result: %d\n", result);

    return 0;
}