#include <iostream>
using namespace std;

float determinant(float a[3][3])
{

    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

int main()
{

    float A[3][3] = {
        {27, 6, -1},
        {6, 15, 2},
        {1, 1, 54}};

    float B[3] = {85, 72, 110};

    float D = determinant(A);

    float Dx[3][3] = {
        {85, 6, -1},
        {72, 15, 2},
        {110, 1, 54}};

    float Dy[3][3] = {
        {27, 85, -1},
        {6, 72, 2},
        {1, 110, 54}};

    float Dz[3][3] = {
        {27, 6, 85},
        {6, 15, 72},
        {1, 1, 110}};

    float x = determinant(Dx) / D;
    float y = determinant(Dy) / D;
    float z = determinant(Dz) / D;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}