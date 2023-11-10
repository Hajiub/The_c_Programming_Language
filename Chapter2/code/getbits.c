#include <stdio.h>


unsigned getbits(unsigned x, int p, int n);

int main() {
    unsigned x = 0b11011010;
    int p = 4;
    int n = 3;
    
    unsigned result = getbits(x, p, n);
    
    printf("Original number (x): 0x%02X\n", x);
    printf("Position (p): %d\n", p);
    printf("Number of bits (n): %d\n", n);
    printf("Extracted bits: 0x%02X\n", result);
    
    return 0;
}

/* getbits: get n bits from position p */
