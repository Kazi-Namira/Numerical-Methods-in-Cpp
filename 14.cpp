#include <iostream>
using namespace std;

int main()
{
    double years[] = {2008, 2010, 2012, 2016, 2020, 2022};
    double population[] = {40, 43, 48, 52, 58, 63};
    double targetYear = 2018;
    double resultPopulation = 0;

    for (int i = 0; i < 6; i++)
    {
        double term = population[i];
        for (int j = 0; j < 6; j++)
        {
            if (j != i)
            {
                term = term * (targetYear - years[j]) / (years[i] - years[j]);
            }
        }
        resultPopulation = resultPopulation + term;
    }

    cout << "In year " << targetYear << ", population = " << resultPopulation << " million" << endl;

    return 0;
}