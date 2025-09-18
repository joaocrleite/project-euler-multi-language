#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
	if (n < 2)
	{
		return 0;
	}

	if (n == 2 || n == 3)
	{
		return 1;
	}

	if (n % 2 == 0 || n % 3 == 0)
	{
		return 0;
	}

	for (int i = 5; i <= sqrt(n); i += 6)
	{
		if (n % i == 0)
		{
			return 0;
		}
		else if (n % (i + 2) == 0)
		{
			return 0;
		}
	}

	return 1;
}

int resolve(int factor)
{
	int last_prime = 0;
	int prime_count = 0;
	int num = 2;

	while (prime_count < factor)
	{

		int is_prime = isPrime(num);

		if (is_prime)
		{
			last_prime = num;
			prime_count++;
		}

		num++;
	}

	return last_prime;
}

int main()
{

	int result = resolve(10001);

	printf("Result=%d\n", result);

	return 0;
}