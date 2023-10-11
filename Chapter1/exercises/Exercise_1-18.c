#include <stdio.h>

int main() 
{
    int c, lastChar;

    lastChar = EOF; 

    while ((c = getchar()) != EOF) 
    {
        if (c == ' ' || c == '\t') 
        {
            if (lastChar != ' ' && lastChar != '\t' && lastChar != '\n') 
            {
                putchar(c); 
            }
        } 
        else if (c == '\n') 
        {
            
            if (lastChar != '\n') 
            {
                putchar(c);
            }
        } 
        else 
        {
            putchar(c); 
        }

        lastChar = c;
    }

    return 0;
}
