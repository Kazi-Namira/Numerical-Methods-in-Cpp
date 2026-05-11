#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    float A[3][3] = {
        {1, 1, 1},
        {1, 2, 3},
        {1, 3, 4}};

    float B[3] = {1, 6, 6};

    float det;

    // Determinant
    det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    if (det == 0)
    {
        cout << "Inverse does not exist";
        return 0;
    }

    float inv[3][3];

    // Inverse matrix
    inv[0][0] = (A[1][1] * A[2][2] - A[1][2] * A[2][1]) / det;
    inv[0][1] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]) / det;
    inv[0][2] = (A[0][1] * A[1][2] - A[0][2] * A[1][1]) / det;

    inv[1][0] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]) / det;
    inv[1][1] = (A[0][0] * A[2][2] - A[0][2] * A[2][0]) / det;
    inv[1][2] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]) / det;

    inv[2][0] = (A[1][0] * A[2][1] - A[1][1] * A[2][0]) / det;
    inv[2][1] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]) / det;
    inv[2][2] = (A[0][0] * A[1][1] - A[0][1] * A[1][0]) / det;

    float X[3];

    // X = A^-1 * B
    for (int i = 0; i < 3; i++)
    {

        X[i] = 0;

        for (int j = 0; j < 3; j++)
        {
            X[i] += inv[i][j] * B[j];
        }
    }

    cout << fixed << setprecision(2);

    cout << "x = " << X[0] << endl;
    cout << "y = " << X[1] << endl;
    cout << "z = " << X[2] << endl;

    return 0;
}