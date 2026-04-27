#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x)
{
    return x * x * x - 5 * x * x - 29;
}

int main()
{
    double x0, x1, x2;
    double tol = 0.001;

    cout << "Enter two initial guesses: ";
    cin >> x0 >> x1;

    do
    {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        x0 = x1;
        x1 = x2;

    } while (fabs(x1 - x0) > tol);

    cout << fixed << setprecision(3);
    cout << "Root = " << x2 << endl;

    return 0;
}