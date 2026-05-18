#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    const int n = 3;
    double a[n][n + 1];

    cout << "Enter the coefficients and constants of the " << n << " equations (x y z constant):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    // Gaussian Elimination with Partial Pivoting
    for (int i = 0; i < n - 1; i++)
    {
        // Partial Pivoting: find the max element in column i
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (abs(a[k][i]) > abs(a[maxRow][i]))
            {
                maxRow = k;
            }
        }

        // Check if matrix is singular
        if (abs(a[maxRow][i]) < 1e-9)
        {
            cout << "Error: Singular Matrix! No unique solution." << endl;
            return 1;
        }

        // Swap current row with maxRow
        if (maxRow != i)
        {
            for (int j = 0; j <= n; j++)
            {
                swap(a[i][j], a[maxRow][j]);
            }
            cout << "\nSwapped row " << i + 1 << " with row " << maxRow + 1 << endl;
        }

        // Elimination process
        for (int j = i + 1; j < n; j++)
        {
            double ratio = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++)
            {
                a[j][k] -= ratio * a[i][k];
            }
        }

        // Display intermediate matrix (optional)
        cout << "\nAfter elimination stage " << i + 1 << ":\n";
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c <= n; c++)
            {
                cout << setw(10) << a[r][c];
            }
            cout << endl;
        }
    }

    // Back Substitution
    double x[n];
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Display Solution
    cout << fixed << setprecision(2);
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}