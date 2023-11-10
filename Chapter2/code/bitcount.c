#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;
	// x  >>= 1 eq x = x >> 1
	for (b = 0; x != 0; x >>= 1)
	{
		if (x & 01)
		{
			b++;
		}
	}
	return b;
}

int main()
{
	unsigned x = 0b11010111;
	printf("%i\n", bitcount(x));
	return 0;
}