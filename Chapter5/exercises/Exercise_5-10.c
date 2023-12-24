/*
  Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
   command line, where each operator or operand is a separate argument. For example,
	expr 2 3 4 + *
	evaluates 2 * (3+4). 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
double stack[MAX_SIZE];
int sp = 0;

void push(double x);
double pop(void);

int main(int argc, char **argv)
{
    double x;
    char *program = *argv++;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <1 1 +>\n", program);
        exit(1);
    }
	int c;
    while (--argc > 0)
    {
        char *arg = *argv++;
        while ((c = *arg++))
        {
			
            switch (c)
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                push(atof(arg - 1));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                x = pop();
                push(pop() - x);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                x = pop();
                if (x != 0.0)
                    push(pop() / x);
                else
                {
                    fprintf(stderr, "Error: zero divisor\n");
                    exit(1);
                }
                break;
            default:
                fprintf(stderr, "Invalid command!\n");
                exit(1);
                break;
            }
        }
    }

    if (sp > 0)
        printf("Result: %g\n", pop());
    else
    {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(1);
    }

    return 0;
}

void push(double x)
{
    if (sp < MAX_SIZE)
        stack[sp++] = x;
    else
    {
        fprintf(stderr, "Error: Stack is full!\n");
        exit(1);
    }
}

double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else
    {
        fprintf(stderr, "Error: Stack is Empty!\n");
        exit(1);
    }
}
