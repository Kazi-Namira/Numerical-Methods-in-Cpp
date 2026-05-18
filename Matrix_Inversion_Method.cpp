#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n = 3;
    double A[3][3] = {{1, 1, 1},
                      {1, 2, 3},
                      {1, 3, 4}};
    double B[3] = {1, 6, 6};
    double det;
    cout << "Coefficient Matrix A:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << A[i][j];
        }
        cout << endl;
    }
    det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    cout << "\nDeterminant = " << det << endl;
    if (det == 0)
    {
        cout << "Inverse does not exist (Singular Matrix)" << endl;
        return 0;
    }
    double cof[3][3];
    cof[0][0] = (A[1][1] * A[2][2] - A[1][2] * A[2][1]);
    cof[0][1] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]);
    cof[0][2] = (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    cof[1][0] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]);
    cof[1][1] = (A[0][0] * A[2][2] - A[0][2] * A[2][0]);
    cof[1][2] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]);

    cof[2][0] = (A[0][1] * A[1][2] - A[0][2] * A[1][1]);
    cof[2][1] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]);
    cof[2][2] = (A[0][0] * A[1][1] - A[0][1] * A[1][0]);

    double inv[3][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inv[j][i] = cof[i][j] / det;
        }
    }

    cout << "\nInverse Matrix :\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << fixed << setprecision(2) << setw(8) << inv[i][j];
        }
        cout << endl;
    }

    double X[3];
    for (int i = 0; i < n; i++)
    {
        X[i] = 0;
        for (int j = 0; j < n; j++)
        {
            X[i] += inv[i][j] * B[j];
        }
    }
    cout << "\nSolution:\n";
    cout << "x = " << X[0] << endl;
    cout << "y = " << X[1] << endl;
    cout << "z = " << X[2] << endl;
    return 0;
}
