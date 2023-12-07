/*
Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
    strcat(s,t) copies the string t to the end of s.
*/
#include <stdio.h>


/* custom_strcat: concatenate t to the end of s; s must have enough space */
void custom_strcat(char s[], const char t[])
{
    int i, j;
    i = j = 0;
    
    // Find the end of s
    while (s[i] != '\0') {
        i++;
    }

    while ((s[i++] = t[j++]) != '\0'); // Copy t
}
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