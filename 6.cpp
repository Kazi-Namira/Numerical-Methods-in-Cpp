#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x)
{
    return x * x * x - x + 2;
}

int main()
{
    double a = -2, b = -1;
    double c;
    double tolerance = 0.0005; // For 3 decimal places

    cout << "False Position Method for x^3 - x + 2 = 0" << endl;
    cout << "Correct to 3 decimal places" << endl
         << endl;

    if (f(a) * f(b) > 0)
    {
        cout << "No root in the given interval" << endl;
        return 1;
    }

    cout << "Iteration\ta\t\tb\t\tc\t\tf(c)" << endl;
    cout << "------------------------------------------------" << endl;

    for (int i = 0; i < 100; i++)
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << i << "\t\t" << fixed << setprecision(6) << a
             << "\t" << b << "\t" << c << "\t" << f(c) << endl;

        if (fabs(f(c)) < tolerance)
        {
            cout << "\nRoot: " << fixed << setprecision(3) << c << endl;
            cout << "Iterations: " << i + 1 << endl;
            return 0;
        }

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "Maximum iterations reached" << endl;
    return 0;
}