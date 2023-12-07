#include <stdio.h>

void swap(int *x, int *y);
int main(void)
{
    int x = 3;
    int y = 5;
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


