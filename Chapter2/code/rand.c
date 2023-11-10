#include <stdio.h>

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0...32767 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
    next = seed;
}

int main() {
    int seed = 42;  // You can change the seed value as desired

    srand(seed);  // Set the seed for the random number generator

    // Generate and print 10 random numbers
    for (int i = 0; i < 10; i++) {
        int random_num = rand();
        printf("Random Number %d: %d\n", i + 1, random_num);
    }

    return 0;
}
