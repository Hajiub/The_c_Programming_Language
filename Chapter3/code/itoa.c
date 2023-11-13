#include <stdio.h>

// Function declarations
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

// This is the Functions defination !
int Strlen(char s[])
{
    int i = 0;
    while (s[i++]);
    return i - 1;
}

void reverse(char s[])
{
    int temp, i, j;
    for (i = 0, j = Strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
    {   
        n = -n;         /* make n positive if it's negative */
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0'; /* Get the last digit and convert it to character */
    } while((n /= 10) > 0);    /* Remove the last digit from n */

    if (sign < 0) /* Add the sign if the original number was negative */
    {
        s[i++] = '-';
    }

    s[i] = '\0'; /* Null terminate the string */
    reverse(s); /* Reverse the string to get correct order of digits */
}

