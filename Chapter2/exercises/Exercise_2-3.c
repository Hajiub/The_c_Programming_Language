/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
              (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
              through 9, a through f, and A through F. 
*/
#include <stdio.h>

int htoi(char s[])
{
    int i, n;
    n = 0;
    
    // Check if the string starts with "0x" or "0X"
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2; // Start from the character after "0x" or "0X"
    } else {
        i = 0; // Start from the beginning of the string
    }
    
    for (; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f'); i++) {
        // Convert the hexadecimal character to its integer value
        if (s[i] >= '0' && s[i] <= '9') {
            n = n * 16 + (s[i] - '0');
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            n = n * 16 + (s[i] - 'A' + 10);
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            n = n * 16 + (s[i] - 'a' + 10);
        }
    }
    
    return n;
}

int main()
{
    char num[] = "0XFF12";
    int result = htoi(num);
    printf("Hexadecimal: %s\n", num);
    printf("Decimal: %d\n", result);
    
    return 0;
}
