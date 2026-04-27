#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double coeff[] = {1, -5, 10, -8};
    double root = 2;
    double a, b, c; 
    double remainder;
    a = coeff[0]; // a = 1
    b = coeff[1] + root * a; // -5 + 2*1 = -3
    c = coeff[2] + root * b; // 10 + 2*(-3) = 4
    remainder = coeff[3] + root * c; // -8 + 2*4 = 0

    cout << "Original: p(x) = x³ - 5x² + 10x - 8" << endl;
    cout << "Root at x = " << root << endl
         << endl;
    cout << "Quotient polynomial q(x) = ";
    
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
