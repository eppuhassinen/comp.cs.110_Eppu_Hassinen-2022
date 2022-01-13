#include <iostream>


int main()
{
    std::cout << "How many numbers would you like to have? ";
    int amount = 1;
    std::cin >> amount;

    for ( int i = 1; i <= amount; ++i )
    {
        if (i % 3 == 0)
        {
            std::cout << "zip" << std::endl;
        }
        else
        {
            std::cout << i << std::endl;
        }

    }

    return 0;
}
