#if !defined(STD)
#define STD <stdio.h>
#endif

#include STD

#define PI 3.14159
#define SQUARE(x) ((x) * (x))

int main(void)
{
    double radius = 5.0;
    double area = PI * SQUARE(radius);

    printf("Area of a circle with radius %.2f is %.2f\n", radius, area);

    return 0;
}
