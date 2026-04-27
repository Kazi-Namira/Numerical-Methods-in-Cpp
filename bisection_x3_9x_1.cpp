#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x)
{
    return pow(x, 3) - 9 * x + 1;
}
int main()
{
    double a, b, c;
    int iteration = 0;

    cout << "Enter initial interval [a, b]: ";
    cin >> a >> b;
    if (f(a) * f(b) >= 0)
    {
        cout << "Error: No root exists in the given interval!" << endl;
        return 1;
    }
    cout << "\nIteration\t a\t\t b\t\t mid\t\t f(mid)" << endl;
    while ((b - a) >= 0.0005)
    {
        c = (a + b) / 2;
        iteration++;
        cout << iteration << "\t\t " << fixed << setprecision(4) << a
             << "\t\t " << b << "\t\t " << c << "\t\t " << f(c) << endl;
        if (f(c) == 0.0)
        {
            break;
        }
        else if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    c = (a + b) / 2;
    cout << "Root (correct to 3 decimal places) = " << fixed << setprecision(3) << c << endl;
    cout << "Number of iterations = " << iteration << endl;
    return 0;
}
