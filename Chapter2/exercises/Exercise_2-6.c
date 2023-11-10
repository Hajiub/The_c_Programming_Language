/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = ~(~0 << n) << (p + 1 - n);

    x = x & ~mask;

    unsigned extractedBits = (y >> (p + 1 - n)) & ~(~0 << n);

    x = x | (extractedBits << (p + 1 - n));

    return x;
}

int main() {
    unsigned x = 0b10111010;
    unsigned y = 0b00101101;
    int p = 4;
    int n = 3;

    unsigned result = setbits(x, p, n, y);

    printf("Original x: %08x\n", x);
    printf("Modified x: %08x\n", result);

    return 0;
}
