#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n = 5;
    double x[] = {1, 2, 3, 4, 5};
    double y[5][5];

    double values[] = {1, 8, 27, 64, 125};

    // Initialize first column
    for (int i = 0; i < n; i++)
    {
        y[i][0] = values[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    cout << "Difference Table:\n";
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << x[i];
        for (int j = 0; j < n - i; j++)
        {
            cout << setw(8) << y[i][j];
        }
        cout << endl;
    }

    return 0;
}