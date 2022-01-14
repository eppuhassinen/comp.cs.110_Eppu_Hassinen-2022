#include <iostream>

using namespace std;


unsigned long int factorial(unsigned long int value)
{
    unsigned long int factorial = 1;
    for (unsigned long int i = 1; i <= value; ++i)
    {
        factorial *= i;
    }
    return factorial;
}

unsigned long int chances(unsigned long int total, unsigned long int drawn)
{
    return factorial(total) /
            (factorial(total - drawn) * factorial(drawn));
}

int main()
{
    cout << "Enter the total number of lottery balls: ";
    int total = 1;
    cin >> total;

    cout << "Enter the number of drawn balls: ";
    int drawn = 1;
    cin >> drawn;

    if ( total <= 0 or drawn <= 0 )
    {
        cout << "The number of balls must be a positive number." << endl;
        return 0;
    }

    if ( drawn > total )
    {
        cout << "The maximum number of drawn balls is the total amount of balls." <<
                endl;
    }

    cout << "The probability of guessing all " << drawn <<
            " balls correctly is 1/" << chances(total, drawn) << endl;


    return 0;
}
