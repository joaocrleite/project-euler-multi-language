#include <iostream>

using namespace std;

int resolve(int n1, int n2, int limit)
{
    int sum = 0;
    for (int i = n1; i < limit; i++)
    {

        if (i % n1 == 0 || i % n2 == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{

    int result = resolve(3, 5, 1000);

    cout << "Result=" << result << endl;

    return 0;
}

