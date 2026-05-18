#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a[3][4]; // 3x3 coefficients + 1 column for constants

    // Step 1: Take input from user
    cout << "Enter the coefficients and constants of the 3 equations (x y z constant):\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }

    // Step 2: Forward elimination
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            float ratio = a[j][i] / a[i][i];
            for (int k = 0; k < 4; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Step 3: Back substitution
    float z = a[2][3] / a[2][2];
    float y = (a[1][3] - a[1][2] * z) / a[1][1];
    float x = (a[0][3] - a[0][1] * y - a[0][2] * z) / a[0][0];

    // Step 4: Display the result
    cout << fixed << setprecision(2);
    cout << "\nSolution:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}
