#include <stdio.h>
int (*f[2])(int, int);
int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int main(void)
{
    f[0] = add;
    f[1] = sub;

    printf("1 + 1 = %i\n", (*f[0])(1, 1));
    printf("1 - 1 = %i\n", (*f[1])(1, 1));
    return 0;
}
