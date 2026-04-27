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

double df(double x)
{
    return 3 * x * x - 6;
}

double newtonMethod(double x0, double tolerance, int &iterations)
{
    int maxIterations = 100;
    iterations = 0;

    for (int i = 0; i < maxIterations; i++)
    {
        double fx = f(x0);
        double dfx = df(x0);

        if (dfx == 0)
            return NAN;

        double x1 = x0 - fx / dfx;
        iterations++;

        if (fabs(x1 - x0) < tolerance)
            return x1;

        x0 = x1;
    }

    return NAN;
}

void solveQuadratic(double a, double b, double c, vector<double> &roots)
{
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0)
    {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        roots.push_back(root1);
        roots.push_back(root2);
    }
}

int main()
{
    double tolerance = 0.0005; // For 3 decimal places
    vector<double> roots;
    vector<int> iterations;

    cout << "Finding all roots of x^3 - 6x + 4 = 0" << endl;
    cout << "Using Newton-Raphson Method with Deflation" << endl;
    cout << "Correct to 3 decimal places" << endl
         << endl;

    double x0 = 1.5;
    int iter1;
    double root1 = newtonMethod(x0, tolerance, iter1);

    if (!isnan(root1))
    {
        roots.push_back(root1);
        iterations.push_back(iter1);
        cout << "First root found: " << fixed << setprecision(6)
             << root1 << " (after " << iter1 << " iterations)" << endl;

        double a3 = 1, a2 = 0, a1 = -6, a0 = 4;

        // Synthetic division with root1
        double b = a3;
        double c = a2 + root1 * b;
        double d = a1 + root1 * c;
        double remainder = a0 + root1 * d;

        cout << "After deflation: Quadratic coefficients: " << b << ", " << c << ", " << d << endl;
        cout << "Remainder: " << remainder << " (should be ~0)" << endl
             << endl;

        vector<double> remainingRoots;
        solveQuadratic(b, c, d, remainingRoots);

        for (double root : remainingRoots)
        {
            roots.push_back(root);
            iterations.push_back(0); // Quadratic formula gives exact roots
        }
    }

    sort(roots.begin(), roots.end());

    cout << "\nAll roots (sorted):" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < roots.size(); i++)
    {
        cout << "Root " << i + 1 << ": " << fixed << setprecision(3)
             << roots[i];
        if (iterations[i] > 0)
            cout << " (found by Newton-Raphson)" << endl;
        else
            cout << " (found by quadratic formula)" << endl;
    }

    cout << "\nVerification (plugging back into original equation):" << endl;
    for (int i = 0; i < roots.size(); i++)
    {
        double value = f(roots[i]);
        cout << "f(" << fixed << setprecision(3) << roots[i] << ") = "
             << scientific << value << endl;
    }

    return 0;
}
