#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    float a[3][4] = {
        {1, 2, 1, 8},
        {2, 3, 4, 20},
        {4, 3, 2, 16}};

    for (int i = 0; i < 3; i++)
    {

        float pivot = a[i][i];

        for (int j = 0; j < 4; j++)
        {
            a[i][j] /= pivot;
        }

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

    cout << fixed << setprecision(2);

    cout << "x = " << a[0][3] << endl;
    cout << "y = " << a[1][3] << endl;
    cout << "z = " << a[2][3] << endl;

    return 0;
}