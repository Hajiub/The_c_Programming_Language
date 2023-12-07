/*
  Exercise 5-2. Write getfloat, the floating-point analog of getint. 
  What type does getfloat return as its function value?

  The getfloat function returns an int as its function value, indicating either EOF or 0.
*/

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 10
#define SIZE 100

int buffer[BUFSIZE];
int bfp = 0;

int getch(void);
void ungetch(int);

int getfloat(float *pn);

int main(void)
{
  int n;
  float  array[SIZE];
  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;
  for (size_t i = 0; i < n; i++)
  {
    printf("%.3f\n", array[i]);
  }
}

int getfloat(float *pn)
{
  int sign, c;
  
  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '-' || c == '+')
    c = getch();

  for (*pn = 0.0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c - '0');

  float power = 1.0;
  
  if (c == '.')
    c = getch();

  for (; isdigit(c); c = getch())
  {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }

  *pn = (*pn * sign) / power;

  return c;
}

int getch(void)
{
  return (bfp > 0) ? buffer[--bfp] : getchar();
}

void ungetch(int c)
{
  if (bfp < BUFSIZE)
    buffer[bfp++] = c;
  else
    printf("ungetch: too many characters\n");
}
