/*
    Goal:
        1. Create the program text somewhere.
        2. Compile it successfully.
        3. Load it.
        4. Run it.
        5. Find out where your output went.
*/

// Include information about standard I/O library
#include <stdio.h>

// Define a function called main that received two arguments
int main(int argc, char **argv)
{
    // main calls library function printf to print this sequence of characters.
    // \n represents the newline character.
    printf("Hello, world\n");
    // Return 0 to indicate successful program execution.
    return 0;
}