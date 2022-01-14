#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a positive number: ";
    int number = 1;
    cin >> number;

    if ( number <= 0 )
    {
        cout << "Only positive numbers accepted" << endl;
        return 0;
    }

    int factor_1 = 1;
    int factor_2 = number;
    for ( int i = 2; i <= number / 2; ++i )
    {
        if ( number % i == 0 )
        {
            if ( abs((number / i) - i) < abs(factor_1 - factor_2) )
            {
                factor_1 = number / i;
                factor_2 = i;
            }
        }
    }
    cout << number << " = " << factor_2 << " * " << factor_1 << endl;

    return 0;
}

int abs( int number )
{
    if ( number < 0 )
        return -number;
    return number;
}
