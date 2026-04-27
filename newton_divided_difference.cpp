#include <iostream>
using namespace std;

int main()
{
    double x[6] = {2008, 2010, 2012, 2016, 2020, 2022};
    double y[6] = {40, 43, 48, 52, 58, 63};

    // Divided difference table
    double dd[6][6];
    for (int i = 0; i < 6; i++)
        dd[i][0] = y[i];

    for (int j = 1; j < 6; j++)
    {
        for (int i = 0; i < 6 - j; i++)
        {
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    double target = 2011;
    double result = dd[0][0];
    double term = 1;

    for (int i = 1; i < 6; i++)
    {
        term = term * (target - x[i - 1]);
        result = result + term * dd[0][i];
    }

    cout << "At x = " << target << ", y = " << result << endl;

    return 0;
}
