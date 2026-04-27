#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

double f(double x)
{
    return x * x * x - 6 * x + 4;
}

double bisection(double a, double b, double tolerance, int &iterations)
{
    double c;
    iterations = 0;

    if (f(a) * f(b) > 0)
        return NAN;

    while ((b - a) / 2 > tolerance)
    {
        c = (a + b) / 2;
        iterations++;

        if (f(c) == 0)
            return c;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    return (a + b) / 2;
}

int main()
{
    vector<pair<double, double>> intervals = {{-3, -2}, {0, 1}, {1, 2}};
    double tolerance = 0.0005; // For 3 decimal places
    vector<double> roots;
    vector<int> iterations;

    cout << "Finding all roots of x^3 - 6x + 4 = 0" << endl;
    cout << "Using Bisection Method" << endl;
    cout << "Correct to 3 decimal places" << endl
         << endl;

    for (auto &interval : intervals)
    {
        int iter;
        double root = bisection(interval.first, interval.second, tolerance, iter);

        if (!isnan(root))
        {
            roots.push_back(root);
            iterations.push_back(iter);
        }
    }

    sort(roots.begin(), roots.end());

    cout << "Roots found:" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < roots.size(); i++)
    {
        cout << "Root " << i + 1 << ": " << fixed << setprecision(3)
             << roots[i] << " (achieved in " << iterations[i] << " iterations)" << endl;
    }

    // Verification
    cout << "\nVerification:" << endl;
    for (int i = 0; i < roots.size(); i++)
    {
        cout << "f(" << fixed << setprecision(3) << roots[i] << ") = "
             << f(roots[i]) << endl;
    }

    return 0;
}
