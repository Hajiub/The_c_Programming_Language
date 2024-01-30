#include <stdio.h>

void swap(int *array, int i, int j);
int partition (int *array, int left, int right);
void qsort(int *array, int left, int right);
void displayArray(const int *array, const size_t size, const char *message);
void reverse(int *array, int len);

int main (void)
{
	int array[] = {5, 9, 34, 0, 2, 4, 3, 1};
	size_t size = sizeof(array)/sizeof(array[0]);
	displayArray(array, size, "Orginal Array: ");
	qsort(array, 0, size - 1);
	displayArray(array, size, "Sorted Array: ");
	return 0;
}

void swap(int *array, int i, int j)
{
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int partition(int *array, int left, int right)
{
    int pivot = array[right];
    int i, j;

    for (i = left - 1, j = left; j < right; j++) 
    {
        if (array[j] < pivot)
            swap(array, ++i, j);
    }

    swap(array, ++i, right);
    return i;
}


void qsort(int *array, int left, int right)
{
	if (left >= right)
		return;
	int piv = partition(array, left, right);

	qsort(array, left, piv - 1);
	qsort(array, piv + 1, right);
}

void displayArray(const int *array, const size_t size, const char *message)
{
	printf("%s ", message);
	putchar('[');
	for (int i = 0; i < size; i++)
		printf("%i%s",  array[i], (i + 1 < size) ? ", ":"");
	printf("]\n");
}

