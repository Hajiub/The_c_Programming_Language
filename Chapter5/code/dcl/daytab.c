#include <stdio.h>

int array[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
// pointer to array[13] of int
int (*daytab)[13];
int main(void)
{
    daytab = &array;
    int i;
    printf("daytab: [");
    for (i = 0; i < 13; i++)
        printf("%i%s", (*daytab)[i], (i + 1 < 13) ? ", " : "");
    printf("]\n");
    return 0;
}
