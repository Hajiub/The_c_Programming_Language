#include <stdio.h>

// return_type (*pointer_name)(parameter_types);
int add(int a, int b)
{
	return a + b;
}

int operate (int (*operation)(int, int ), int x, int y)
{
	return operation(x, y);
}

int main(void)
{
	int result = operate(add, 5, 6);
	printf("%i\n", result);
	return 0;
}
