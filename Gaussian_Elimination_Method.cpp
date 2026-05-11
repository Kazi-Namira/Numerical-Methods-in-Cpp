#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    float a[3][4] = {
        {2, 1, 1, 10},
        {1, 4, 9, 16},
        {3, 2, 3, 18}};

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

    float z = a[2][3] / a[2][2];

    float y = (a[1][3] - a[1][2] * z) / a[1][1];

    float x = (a[0][3] - a[0][1] * y - a[0][2] * z) / a[0][0];

    cout << fixed << setprecision(2);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}