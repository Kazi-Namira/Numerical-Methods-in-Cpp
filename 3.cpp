#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double hornerRule(double coeff[], int degree, double x)
{
    double result = coeff[0];

    for (int i = 1; i <= degree; i++)
    {
        result = result * x + coeff[i];
    }
    return result;
}

int main()
{
    cout << fixed << setprecision(4);
    int degree = 3;
    double coeff[4] = {1, -2, 5, 10};
    double x = 5.0;
    cout << "========================================" << endl;
    cout << "Polynomial Evaluation Using Horner's Rule" << endl;
    cout << "========================================" << endl;
    cout << "Polynomial: f(x) = x³ - 2x² + 5x + 10" << endl;
    cout << "Value of x: " << x << endl;
    cout << "----------------------------------------" << endl;
    double result = hornerRule(coeff, degree, x);
    cout << "\nStep-by-step calculation using Horner's rule:" << endl;
    cout << "----------------------------------------" << endl;
    double step = coeff[0];
    cout << "Step 1: p3 = a3 = " << coeff[0] << endl;
    for (int i = 1; i <= degree; i++)
    {
        cout << "Step " << i + 1 << ": p" << degree - i << " = " << step << " * " << x
             << " + " << coeff[i] << " = ";
        step = step * x + coeff[i];
        cout << step << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << "\nFinal Result:" << endl;
    cout << "f(" << x << ") = " << result << endl;
    double direct = pow(x, 3) - 2 * pow(x, 2) + 5 * x + 10;
    cout << "\nVerification (Direct Calculation):" << endl;
    cout << "f(" << x << ") = " << x << "³ - 2(" << x << "²) + 5(" << x << ") + 10" << endl;
    cout << "           = " << pow(x, 3) << " - " << 2 * pow(x, 2) << " + " << 5 * x << " + 10" << endl;
    cout << "           = " << direct << endl;
    cout << "\n========================================" << endl;
    cout << "Program executed successfully!" << endl;
    cout << "========================================" << endl;
    return 0;
}