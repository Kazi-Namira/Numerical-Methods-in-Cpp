#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    double x[] = {1, 2, 3, 4, 5};
    double y[5][5];

    double values[] = {1, 8, 27, 64, 125};

    // Initialize y
    for (int i = 0; i < n; i++)
    {
        y[i][0] = values[i];
    }

    // Forward difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    double xp = 1.7;
    double h = x[1] - x[0];
    double u = (xp - x[0]) / h;

    double result = y[0][0];
    double u_term = 1;

    for (int i = 1; i < n; i++)
    {
        u_term = u_term * (u - (i - 1)) / i;
        result += u_term * y[0][i];
    }

    cout << "Value at x = " << xp << " is: " << result << endl;

    return 0;
}