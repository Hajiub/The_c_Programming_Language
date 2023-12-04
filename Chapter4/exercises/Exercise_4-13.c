/*
Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place.
*/
#include <stdio.h>
#include <string.h>

void reverse(char [], int, int);
void swap(char *, char *);
int main(void)
{
    char s[] = "hello, world";
    reverse(s, 0, strlen(s) - 1);
    printf("reversed string %s\n", s);
}

// void reverse(char s[])
// {
//     size_t len = strlen(s);
//     int i, j, temp;
//     for (i = 0, j = len -1; i < j; i++, j--)
//     {
//         temp = s[i];
//         s[i] = s[j];
//         s[j] = temp;
//     }
// }
void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char s[], int start, int end)
{
    if (start < end)
    {
        // swap
        swap(&s[start], & s[end]);
        reverse(s, ++start, --end);
    }
}