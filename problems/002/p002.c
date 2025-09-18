#include <stdio.h>

int resolve(int max)
{
	int x = 1;
	int y = 2;
	int sum = y;
	int temp;

	while (y < max)
	{
		temp = y;
		y = x + y;
		x = temp;

		if (y % 2 == 0)
		{
			sum = sum + y;
		}
	}
	return sum;
}

int main()
{

	int result = resolve(4000000);

	printf("Result=%d\n", result);

	return 0;
}
