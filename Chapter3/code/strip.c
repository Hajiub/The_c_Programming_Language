#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverse(char s[])
{
    int i, j, temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++ ,j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void removeSpace(char s[]) {
    int end = strlen(s) - 1;

    // Find the index of the last non-space character
    while (end >= 0 && isspace(s[end])) {
        end--;
    }

    // Null-terminate the string at the new end
    s[end + 1] = '\0';
}

void strip(char s[])
{
    removeSpace(s);
    reverse(s);
    removeSpace(s);
    reverse(s);
}
int main() {
    char string[] = "                   Hello, world! My name is Abraham ElMahjoub, and I am a self-taught programmer. I started with the god language, which is C.                                        ";
    strip(string);
    printf("%s", string);
    putchar('\n');
    return 0;
}
