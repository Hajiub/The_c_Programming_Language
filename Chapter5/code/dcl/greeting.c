#include <stdio.h>

void (*pf)();
void greeting(void)
{
    printf("Hello, world\n");
    return;
}

int main(void)
{
    pf = greeting;
    (*pf)();
    return 0;
}
