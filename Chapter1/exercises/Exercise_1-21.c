/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
               number of tabs and blanks to achieve the same spacing.
*/
#include <stdio.h>

#define TAB_WIDTH 4 

int main()
{
    int c;
    int charCount = 0; 
    int spaceCount = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            spaceCount++;
        }
        else
        {
            if (spaceCount > 0)
            {
                int tabs = spaceCount / TAB_WIDTH;
                int spaces = spaceCount % TAB_WIDTH;
                
                // Replace spaces with tabs
                for (int i = 0; i < tabs; i++)
                {
                    putchar('\t');
                }
                
                for (int i = 0; i < spaces; i++)
                {
                    putchar(' ');
                }
                
                spaceCount = 0; // Reset space count
            }
            
            putchar(c);
            charCount++;
            
            if (c == '\t')
            {
                int spacesToNextTabStop = TAB_WIDTH - (charCount % TAB_WIDTH);
                charCount += spacesToNextTabStop - 1; 
            }
        }
    }

    return 0;
}
