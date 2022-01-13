#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a temperature: ";

    double deg = 0;

    cin >> deg;

    cout << deg << " degrees Celsius is " << deg * 1.8 + 32 <<
            " degrees Fahrenheit" << endl;
    cout << deg << " degrees Fahrenheit is " << (deg - 32) / 1.8 <<
            " degrees Celsius" << endl;

    return 0;
}
