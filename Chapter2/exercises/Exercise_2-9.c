/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.
*/

/* 
    `x = x & (x - 1)` removes the rightmost 1-bit in the binary representation of x.
    This operation works because subtracting 1 from x flips the rightmost 1-bit to 0
    and changes all the bits to the right of it to 1. Performing the bitwise AND with
    x then clears the rightmost 1-bit.
*/

#include <stdio.h>


int bitcount(unsigned x)
{
    int count;
    for (count = 0; x != 0; x &= (x - 1))
    {
        count++;
    }
    return count;
}

int main()
{
    unsigned x = 0b11010111;
    printf("%i\n", bitcount(x));
    return 0;
}
