#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    float x = 0, y = 0, z = 0;
    float x1, y1, z1;

    int iteration = 10;

    for (int i = 1; i <= iteration; i++)
    {

        x1 = (95 - 11 * y + 4 * z) / 83;

        y1 = (71 - 3 * x - 29 * z) / 8;

        z1 = (104 - 7 * x - 52 * y) / 13;

        x = x1;
        y = y1;
        z = z1;

        cout << "Iteration " << i << ": ";
        cout << "x = " << x
             << ", y = " << y
             << ", z = " << z << endl;
    }

    return 0;
}