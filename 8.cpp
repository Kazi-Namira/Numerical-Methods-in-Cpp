#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Polynomial: x³ - 5x² + 10x - 8
    // We know x = 2 is a root (plugging in gives 0)

    // Coefficients: for x³, x², x, constant term
    double coeff[] = {1, -5, 10, -8};
    double root = 2;

    // Result will be quadratic: ax² + bx + c
    double a, b, c; // coefficients of quotient
    double remainder;

    // Synthetic division (simple process):
    // 1. Bring down first coefficient
    a = coeff[0]; // a = 1

    // 2. Multiply by root and add to next coefficient
    b = coeff[1] + root * a; // -5 + 2*1 = -3

    // 3. Repeat
    c = coeff[2] + root * b; // 10 + 2*(-3) = 4

    // 4. Get remainder
    remainder = coeff[3] + root * c; // -8 + 2*4 = 0

    cout << "Original: p(x) = x³ - 5x² + 10x - 8" << endl;
    cout << "Root at x = " << root << endl
         << endl;

    cout << "Quotient polynomial q(x) = ";

    // Display q(x) = ax² + bx + c
    if (a == 1)
        cout << "x²";
    else if (a == -1)
        cout << "-x²";
    else
        cout << a << "x²";

    if (b > 0)
        cout << " + " << b << "x";
    else if (b < 0)
        cout << " - " << -b << "x";

    if (c > 0)
        cout << " + " << c;
    else if (c < 0)
        cout << " - " << -c;

    cout << endl;
    cout << "Remainder: " << remainder << " (should be 0)" << endl;
    cout << "\nTherefore: p(x) = (x - 2)(";
    if (a == 1)
        cout << "x²";
    else
        cout << a << "x²";
    if (b > 0)
        cout << " + " << b << "x";
    else if (b < 0)
        cout << " - " << -b << "x";
    if (c > 0)
        cout << " + " << c;
    else if (c < 0)
        cout << " - " << -c;
    cout << ")" << endl;

    return 0;
}