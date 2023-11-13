/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.
*/
/*
    Input: "a-z0-9"
    Ouptu: "abcdefghijklmnopqrstuvwxyz0123456789"
*/
#include <stdio.h>

#include <stdio.h>

void expand(const char s1[], char s2[]) {
    int i = 0; // index for s1
    int j = 0; // index for s2

    while (s1[i]) {
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0') {
            // Check for a valid range shorthand like a-z
            char start = s1[i - 1];
            char end = s1[i + 1];

            if ((start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z') ||
                (start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z') ||
                (start >= '0' && start <= '9' && end >= '0' && end <= '9')) {
                
                for (char c = start + 1; c <= end; c++) {
                    s2[j++] = c;
                }
                i++;
            } else {
                s2[j++] = s1[i];
            }
        } else {
            s2[j++] = s1[i];
        }
        i++;
    }
    s2[j] = '\0';
}

int main() {
    const char shorthand[] = "A-Z";
    char expanded[100];

    expand(shorthand, expanded);

    printf("Original: %s\nExpanded: %s\n", shorthand, expanded);

    return 0;
}
