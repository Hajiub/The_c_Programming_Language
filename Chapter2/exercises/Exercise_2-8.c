/*
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.
*/
#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
    int size = sizeof(unsigned) * 8; // Get the size of an unsigned integer in bits
    n = n % size;
    
    
    return (x >> n) | (x << (size - n));
}

int main()
{
    unsigned x = 0b10111010; // Binary: 10111010
    int n = 3;

    unsigned result = rightrot(x, n);

    printf("Original x: %08x\n", x);
    printf("Rotated x:  %08x\n", result);

    return 0;
