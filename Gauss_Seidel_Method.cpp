#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    float x1 = 0, x2 = 0, x3 = 0;

    int iteration = 10;

    for (int i = 1; i <= iteration; i++)
    {

        x1 = (12 - x2 - x3) / 10;

        x2 = (13 - 2 * x1 - x3) / 10;

        x3 = (14 - 2 * x1 - 2 * x2) / 10;
    }

    cout << fixed << setprecision(4);

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;

    return 0;
}