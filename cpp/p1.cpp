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

int example()
{
    return resolve(3, 5, 10);
}

int problem()
{
    return resolve(3, 5, 1000);
}

int main()
{

    int example_result = example();

    printf("Example=%d\n", example_result);

    int problem_result = problem();

    printf("Result=%d\n", problem_result);

    return 0;
}
