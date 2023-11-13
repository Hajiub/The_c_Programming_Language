/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.
*/
#include <stdio.h>

int Strlen(char s[]) {
    int i = 0;
    while (s[i++]);
    return i - 1;
}

void reverse(char s[]) {
    int temp, i, j;
    for (i = 0, j = Strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* Fill a range with desired Char */
void cset(char s[], int start_index, char val, size_t count) {
    for (size_t i = 0; i < count; i++) {
        s[start_index++] = val;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int w) {
    int i, sign;
    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    int spaces_needed = w - i;
    if (spaces_needed > 0) {
        cset(s, i, ' ', spaces_needed);
        i += spaces_needed;
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char result[20];
    int width = 8;
    int values[] = {123, -456, 7890, 86754546, -1254854878};

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        itoa(values[i], result, width);
        printf("Integer: %d\n", values[i]);
        printf("String representation: %s\n", result);
        printf("\n");
    }

    return 0;
}
