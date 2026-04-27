#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double bankersRound(double x, int n)
{
    if (x == 0.0)
        return 0.0;

    const double EPS = 1e-12;

    int d = (int)floor(log10(fabs(x))) + 1;
    double scale = pow(10.0, n - d);
    double scaled = x * scale;

    double intPart;
    double frac = modf(scaled, &intPart);

    double rounded;

    if (fabs(frac) < 0.5 - EPS)
    {
        rounded = intPart;
    }
    else if (fabs(frac) > 0.5 + EPS)
    {
        rounded = intPart + (scaled > 0 ? 1 : -1);
    }
    else
    {
        // Half case → round to even
        if (fmod(fabs(intPart), 2.0) == 0.0)
            rounded = intPart;
        else
            rounded = intPart + (scaled > 0 ? 1 : -1);
    }

    return rounded / scale;
}

int main()
{
    cout << fixed << setprecision(6);

    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        double num;
        int n;

        cout << "\nEnter number: ";
        cin >> num;

        cout << "Enter significant figures: ";
        cin >> n;

        if (n <= 0)
        {
            cout << "Error: Significant figures must be >= 1\n";
        }
        else
        {
            double result = bankersRound(num, n);
            cout << "Rounded result: " << result << endl;
        }

        cout << "Try again? (y/n): ";
        cin >> again;
    }

    cout << "\nProgram ended.\n";
    return 0;
}