/*
Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
    strcat(s,t) copies the string t to the end of s.
*/
#include <stdio.h>


void strcat_pv(char *s, const char *t)
{
    // Find the end of s
    while (*s)
        s++;

    // Copy t
    while ((*s++ = *t++))
        ;
}


int main()
{
    char source[100] = "hello, world";
    char des[] = " my name is Abraham";
    strcat_pv(source, des);
    printf("%s\n", source);
}