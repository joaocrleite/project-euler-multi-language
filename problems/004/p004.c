
#include <stdio.h>
#include <string.h>

int resolve(int digits)
{

	int largestPalindrome = 9009;
	char numberStr[100];

	int top = 1;

	for (int i = 0; i < digits; i++)
	{
		top *= 10;
	}
	int min = top / 10;
	top -= 1;

	for (int x = top; x > min; x--)
	{
		for (int y = top; y > min; y--)
		{

			int product = x * y;

			if (largestPalindrome < product)
			{

				sprintf(numberStr, "%d", product);

				int start = 0;
				int end = strlen(numberStr) - 1;
				int isPalindrome = 1;

				while (start < end)
				{
					if (numberStr[start] != numberStr[end])
					{
						isPalindrome = 0;
						break;
					}

					start++;
					end--;

					if (end == start && numberStr[start] != numberStr[end])
					{
						isPalindrome = 0;
						break;
					}
				}

				if (isPalindrome)
				{
					largestPalindrome = product;
				}
			}
		}
	}

	return largestPalindrome;
}

int main()
{

	int result = resolve(3);

	printf("Result=%d\n", result);

	return 0;
}