#include <stdio.h>
#include <limits.h>

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
void bin(int n, char s[])
{
    
    int i = 0;

    // Check if the number is negative
    int isNegative = 0;
    if (n < 0 && n <= UINT_MAX)
    {
        isNegative = 1;
        n = -n;  // Make n positive for further processing
    }

    do
    {
        s[i++] = n % 2 + '0';
    } while ((n /= 2) > 0);

    if (isNegative)
    {
        s[i++] = '1'; // Set the most significant bit to 1 for negative numbers
    }

    s[i] = '\0';
    reverse(s);
}


int main() {
    int number = INT_MAX;
    char s[32] = {'0'};
    bin(number, s);
    for (int i = 0; s[i]; i++)
    {
        putchar(s[i]);
    }
    putchar('\n');
    return 0;
}
