/* Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 10
char buf[BUFSIZE];
int bufp = 0;
int sp = 0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void swap();
void printTopElementsofStack(void);
void clearStack(void);
void duplicateStackTopElement(void);
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while( (type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int) pop() % (int) op2);
                else
                    printf("error: modulo by zero");
                break;
            
            case 'p':
                /* print the top elements of the stack */
                printTopElementsofStack();
                break;
            case 's':
                /* swap the top two elements */
                swap();
                break;
            case 'c':
                /* clear the stack */
                clearStack();
                break;
            case 'd':
                /* duplicate the stack elements */
                duplicateStackTopElement();
                break;
            case '^':
                /* Power */
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '#':
                /* sin */
                push(sin(pop()));
                break;
            case 'e':
                /* exp */
                push(exp(pop()));
                break;
            case '\n':
                if (sp)
                    printf("result: %.8g\n", pop());
                break;
            case 'q':
                exit(EXIT_FAILURE);
                break;
            default:
                printf("Error: unkown command %s\n", s);
                break;
                
        }
    }
    printf("%g %g\n", val[0], val[1]);
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");
        return 0.0;

}
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')  /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;

}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many charactes\n");
    else
        buf[bufp++] = c;
}

void swap(void)
{
  double tmp1 = pop();
  double tmp2 = pop();
  push(tmp1);
  push(tmp2);
}
void printTopElementsofStack(void)
{
    if(sp)
    {
        printf("stack top elements: ");
        for (int i = 0; i < sp; i++)
        {
            printf("%g ", val[i]);
        }
        putchar('\n');
    }
    else
    {
        printf("Error: Stack is empty!.\n");
    }
}

void clearStack(void)
{
    do
    {
        val[--sp] = 0.0;
    } while(sp);
}


void duplicateStackTopElement(void)
{
    if (sp < MAXVAL)
    {
        double tmp = pop();
        push(tmp);
        push(tmp);
    }
    else
    {
        printf("error: not enough space to duplicate stack elements\n");
    }
}
