
#include <stdio.h>

long int resolve(long int max)
{
	long int num = max;
	long int largest_prime = 0;

	while (num > 2)
	{
		for (long int prime = 2; prime <= num; prime++)
		{
			if (num % prime == 0)
			{
				if (largest_prime < prime)
				{
					largest_prime = prime;
				}

				num = num / prime;
				break;
			}
		}
	}

	return largest_prime;
}

int main()
{

	long int result = resolve(600851475143);

	printf("Result=%ld\n", result);

	return 0;
}