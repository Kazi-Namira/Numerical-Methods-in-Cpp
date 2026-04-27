#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int countSignificantDigits(string numStr)
{
    int count = 0;
    bool decimalPoint = false;
    bool significantStarted = false;
    int length = numStr.length();

    size_t ePos = numStr.find('e');
    if (ePos == string::npos)
    {
        ePos = numStr.find('E');
    }

    if (ePos != string::npos)
    {
        string coefficient = numStr.substr(0, ePos);
        string exponent = numStr.substr(ePos + 1);

        int coeffCount = 0;
        bool coeffDecimal = false;
        bool coeffSignificantStarted = false;

        for (int i = 0; i < coefficient.length(); i++)
        {
            char ch = coefficient[i];

            if (ch == '+' || ch == '-')
            {
                continue;
            }
            else if (ch == '.')
            {
                coeffDecimal = true;
                continue;
            }
            else if (isdigit(ch))
            {
                if (ch != '0')
                {
                    coeffSignificantStarted = true;
                }

                if (coeffSignificantStarted)
                {
                    coeffCount++;
                }
                else if (ch == '0' && coeffDecimal)
                {
                    continue;
                }
            }
        }

        int expCount = 0;
        for (int i = 0; i < exponent.length(); i++)
        {
            if (isdigit(exponent[i]) && exponent[i] != '0')
            {
                expCount++;
            }
        }

        return coeffCount;
    }

    for (int i = 0; i < length; i++)
    {
        char ch = numStr[i];

        if (ch == '+' || ch == '-')
        {
            continue;
        }
        else if (ch == '.')
        {
            decimalPoint = true;
            continue;
        }
        else if (isdigit(ch))
        {
            if (ch != '0')
            {
                significantStarted = true;
            }

            if (!significantStarted && ch == '0')
            {
                continue;
            }

            count++;
        }
    }

    if (decimalPoint && numStr[length - 1] == '.')
    {
    }

    return count;
}

bool isValidNumber(const string &str)
{
    bool hasDigit = false;
    bool hasDecimal = false;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (i == 0 && (ch == '+' || ch == '-'))
        {
            continue;
        }
        else if (ch == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (isdigit(ch))
        {
            hasDigit = true;
        }
        else if (ch == 'e' || ch == 'E')
        {
            if (i == 0 || i == str.length() - 1)
                return false;

            bool hasExpDigit = false;
            for (int j = i + 1; j < str.length(); j++)
            {
                char expCh = str[j];
                if (j == i + 1 && (expCh == '+' || expCh == '-'))
                {
                    continue;
                }
                else if (!isdigit(expCh))
                {
                    return false;
                }
                else
                {
                    hasExpDigit = true;
                }
            }
            return hasExpDigit;
        }
        else
        {
            return false;
        }
    }

    return hasDigit;
}

int main()
{
    string number;
    char choice;

    do
    {
        cout << "\nEnter a number: ";
        cin >> number;

        if (!isValidNumber(number))
        {
            cout << "Error: Invalid number format! Please try again." << endl;
            continue;
        }

        int sigDigits = countSignificantDigits(number);
        cout << "Significant digits: " << sigDigits << endl;

        cout << "\nDo you want to check another number? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the Significant Digits Counter!" << endl;

    return 0;
}