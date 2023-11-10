#include <stdio.h>

int isDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1; // Character is a digit
    }
    return 0; // Character is not a digit
}

int main()
{
    char digit = '5'; // Example character
    int result = isDigit(digit);
    
    if (result)
    {
        printf("It's a digit.\n");
    }
    else
    {
        printf("It's not a digit.\n");
    }

    return 0;
}
