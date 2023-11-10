/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
              s1 that matches any character in the string s2.
*/

#include <stdio.h>

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int shouldDelete;

    for (i = k = 0; s1[i] != '\0'; i++)
    {
        shouldDelete = 0;

        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                shouldDelete = 1;
                break; 
            }
        }

        if (!shouldDelete)
        {
            s1[k] = s1[i];
            k++;
        }
    }

    s1[k] = '\0'; 
}

int main() {
    char s1[] = "Hello, World!";
    char s2[] = "aeiou";

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}
