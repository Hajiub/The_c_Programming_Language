#include <stdio.h>

#define TAB_WIDTH 4  

int main()
{
    int c;
    int charCount = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            int spacesToNextTabStop = TAB_WIDTH - (charCount % TAB_WIDTH);
            for (int i = 0; i < spacesToNextTabStop; i++)
            {
                putchar(' ');
                charCount++;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
            charCount = 0;  
        }
        else
        {
            putchar(c);
            charCount++;
        }
    }

    return 0;
}
