// Modify the temperature conversion program to print a heading above the table.
#include <stdio.h>


int main(void)
{
    int lower, step, upper;
    int fahr, celsius;

    lower = 0;
    upper =  300;
    step = 20;

    printf("\nTable\t\tFahrenheit\tCelsius\n");
    for (fahr = 0; fahr <= upper; fahr += step)
    {
        printf("\t\t%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
        
    }
    return 0;
}