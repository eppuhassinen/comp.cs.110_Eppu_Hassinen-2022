#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    int number = 1;
    cin >> number;

    int cube = 1;
    cube = number * number * number;

    if ( cube / number / number == number )
    {
        cout << "The cube of " << number << " is " <<
                cube << "." << endl;
    } else
    {
        cout << "Error! The cube of " << number << " is not " <<
                        cube << "." << endl;
    }
    return 0;
}
