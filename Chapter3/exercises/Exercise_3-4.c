/*
    Exercise 3-4. In a two's complement number representation, our version of itoa does not
    handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
    not. Modify it to print that value correctly, regardless of the machine on which it runs.
*/
#include <stdio.h>
#include <limits.h>


int Strlen(char s[]);
void reverse(char s[]);
void itoa(int n, char s[]);

int main() {
    char result[20];

    int values[] = {123, -456, 7890, 86754546, -1254854878};

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        itoa(values[i], result);
        printf("Integer: %d\n", values[i]);
        printf("String representation: %s\n", result);
        printf("\n");
    }

    return 0;
}


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


void itoa(int n, char s[]) {
    int i, sign;

    sign = n;

    i = 0;

    if (n == INT_MIN) {
        s[i++] = -(n % 10) + '0';
        n /= 10;
    }
    else {
        if (sign < 0) {
            n = -n;
        }
    }

    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}
