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

int main() {
    char destination[100] = "Hello, ";
    char source[] = "world!";
    
    custom_strcat(destination, source);
    printf("%s\n", destination);

    return 0;
}
