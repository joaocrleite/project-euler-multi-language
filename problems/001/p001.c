#include <stdio.h>

int resolve(int n1, int n2, int max)
{

    int sum = 0;

    for (int i = 1; i < max; i++)
    {

        if (i % n1 == 0)
        {
            sum += i;
        }
        else if (i % n2 == 0)
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{

    int result = resolve(3, 5, 1000);

    printf("Result=%d\n", result);

    return 0;
}
