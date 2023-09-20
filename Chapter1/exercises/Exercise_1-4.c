// Write a program to print the corresponding Celsius to Fahrenheit table.
#include <stdio.h>


int main(void)
{
    int fahr, celsius;
    int upper, lower, step;
    
    upper = 40;
    lower = -20;
    step = 5;
    printf("\nTable\t\tCelsius\tFahrenheit\n");
    for (celsius = lower; celsius <= upper; celsius += step)
    {
         printf("\t\t%3d\t%6.1f\n", celsius, celsius * (5.0/9.0) + 32);
    }

}
