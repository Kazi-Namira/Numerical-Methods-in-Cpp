#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a[3][4]; // 3x3 coefficients + 1 column for constants

    // Taking input from the user
    cout << "Enter the coefficients and constants of the 3 equations (x y z constant):\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }

    // Gauss-Jordan Elimination
    for (int i = 0; i < 3; i++)
    {
        // Make the pivot 1
        float pivot = a[i][i];
        for (int j = 0; j < 4; j++)
        {
            a[i][j] /= pivot;
        }

        // Make other elements in pivot column 0
        for (int k = 0; k < 3; k++)
        {
            if (k != i)
            {
                float factor = a[k][i];
                for (int j = 0; j < 4; j++)
                {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

    // Display solution
    cout << fixed << setprecision(2);
    cout << "\nSolution:\n";
    cout << "x = " << a[0][3] << endl;
    cout << "y = " << a[1][3] << endl;
    cout << "z = " << a[2][3] << endl;

    return 0;
}
