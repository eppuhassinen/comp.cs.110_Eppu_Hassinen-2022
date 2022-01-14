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
    cout << "Enter the total amount of lottery balls: ";
    unsigned long int total = 1;
    cin >> total;

    cout << "Enter the number of drawn balls: ";
    unsigned long int drawn = 1;
    cin >> drawn;

    if ( total <= 0 or drawn <= 0 )
    {
        cout << "The amount of balls must be a positive number." << endl;
        return 0;
    }

    cout << "The probability of guessing all " << drawn <<
            " balls correct is 1/" << chances(total, drawn) << endl;


    return 0;
}
