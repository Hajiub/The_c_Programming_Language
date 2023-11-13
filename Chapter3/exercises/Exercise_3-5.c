/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.
*/
#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int length = strlen(s);
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b) {
    const char digits[] = "0123456789ABCDEF";
    int i = 0;

    if (n < 0) {
        n = -n;
    }

    do {
        s[i++] = digits[n % b];
    } while ((n /= b) > 0);

    s[i] = '\0';

    reverse(s);
}

int main() {
    int n = 2; 
    char s[100]; 
    int b = 8;

    itob(n, s, b);

    printf("%d in base %d is %s\n", n, b, s);

    return 0;
}
