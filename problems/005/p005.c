
#include <stdio.h>

int resolve(int factor)
{

	int smallest_multiple = 0;
	int num = factor * factor;
	while (smallest_multiple == 0)
	{

		int match = 1;
		for (int i = 2; i <= factor; i++)
		{

			if (num % i !=0)
			{
				match = 0;
				break;
			}
		}

		if (match)
		{
			smallest_multiple = num;
		}

		num++;
	}

	return smallest_multiple;
}

int main()
{

	int result = resolve(20);

	printf("Result=%d\n", result);

	return 0;
}