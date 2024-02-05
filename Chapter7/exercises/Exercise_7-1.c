/*
Write a program that converts upper case to lower or lower case to upper,
depending on the name it is invoked with, as found in argv[0].
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int ac, char **av) 
{
   int (*func_ptr)(int); 
   printf("%s\n", av[0]);
   if (strcmp(av[0], "./upper") == 0) 
        func_ptr = toupper;
    else
        func_ptr = tolower;
    
    int c;
    while ((c = getchar()) != EOF)
        putchar(func_ptr(c));

    return 0;
}
