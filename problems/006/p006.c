
#include <stdio.h>

int resolve(int factor)
{
	int sumSquare = 1;
	int sum = 1;

	for (int i = 2; i <= factor; i++) {
		sumSquare += i * i;
		sum += i;
	}

	int squareSum = sum * sum;

	return squareSum - sumSquare;
}

int main()
{

	int result = resolve(100);

	printf("Result=%d\n", result);

	return 0;
}