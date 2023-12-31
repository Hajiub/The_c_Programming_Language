#include <stdio.h>

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellSort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /=2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

int main()
{
    int v[] = {8,7,9,6,5,2,99,455,8778,7897897,55};
    int n = sizeof(v) / sizeof(v[0]);
    shellSort(v, n);
    
    for (int i = 0; v[i]; i++)
    {
        printf("%i ", v[i]);
    }
    putchar('\n');
}