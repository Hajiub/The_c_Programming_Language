/* 
    Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
    occurrence of t in s, or -1 if there is none. 
*/

#include <stdio.h>
#include <string.h>

int strindex(char s[], char t)
{
    int i, c;
    c = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == t)
        {
            c = i;
        }
    }
    return c;
}

int main()
{
  char s[] = "hello, world";
  char t = 'o';
  int exp = 8;
  int result = strindex(s, t);
  if (exp == result)
  {
    printf("char %c is found at the right most index %i of %s\n", t, result, s);
  }
  else
  {
    printf("This shit isn't working!\n");
  }
  return 0;
}
