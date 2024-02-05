#include <stdio.h>

int main(void) 
{
    printf("Case 1: Hello, world!\n");

    int number = 42;
    printf("Case 2: The answer to everything is %d\n", number);

    float pi = 3.14159;
    printf("Case 3: The value of pi is %.2f\n", pi);

    char character = 'A';
    printf("Case 4: The first letter of the alphabet is '%c'\n", character);

    int hexValue = 255;
    printf("Case 5: The hexadecimal representation of %d is %x\n", hexValue, hexValue);

    char message[] = "Programming";
    printf("Case 6: %-15s is fun!\n", message);

    return 0;
}

