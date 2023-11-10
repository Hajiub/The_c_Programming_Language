/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/
#include <stdio.h>

unsigned invert(int x, int p, int n)
{
    return x ^ ~(~0 << n) << (p + 1 - n);
}

int main()
{
    unsigned x =  0b10111010;
    int p = 4;
    int n = 3;

    unsigned result = invert(x, p, n);

    printf("Original x: %08x\n", x);
    printf("Modified x: %08x\n", result);
}