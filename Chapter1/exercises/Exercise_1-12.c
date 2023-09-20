// Write a program that prints its input one word per line.
#include <stdio.h>
#include <stdbool.h>

int main() {
    int c;
    bool inWord = false; 

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (inWord)
            {
                putchar('\n'); 
                inWord = false;
            }
        } 
        else
        {
            putchar(c);
            inWord = true;
        }
    }

    return 0;
}
