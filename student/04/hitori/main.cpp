/* Hitori
 *
 * Desc:
 *   This program implements a Hitori game with the game board of
 *   size 5 x 5. Each square in the game board has a number from 1-5.
 *   At first, each horizontal and vertical row can have several identical
 *   numbers, but the purpose is to remove numbers such that each horizontal
 *   and vertical row has no duplicate numbers. However, it is not possible
 *   to remove numbers in adjacent squares, and none of the remaining numbers
 *   (squares) can be isolated from the other ones, i.e. it is not possible
 *   to remove all numbers around it (from strictly above, below, left, right).
 *
 *   At first, the user is asked, if the game board will be filled with
 *   randomly drawn numbers 1-5, or with user given 25 numbers. In the first
 *   option, a seed value for the random number generator will be asked next.
 *   In the latter option, the user is asked to input 25 numbers.
 *
 *   On each round, the user is asked for coordinates, i.e. two numbers.
 *   The player wins if each horizontal and vertical row has at most one
 *   instance of each number 1-5. The player loses if they remove  a number,
 *   the adjacent number of which has already been removed or if a number
 *   becomes isolated.
 *
 *   The program checks the user-given coordinates. They must be inside the
 *   game board, and the square indicated by them must have a number, i.e.
 *   a number cannot be removed again.
 *
 *   When the game ends, the program tells if the player lost or won.
 *
 *   Program author
 *   Name: Eppu Hassinen
 *   Student number: 50044786
 *   UserID: xrepha
 *   E-Mail: eppu.hassinen@tuni.fi
 *
 *   */
#include "board.hh"
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

const std::vector<int> TEST_INPUT = {2, 5, 5, 3, 2, 3, 4, 2, 5, 3, 1, 2, 2,
                                     1, 4, 2, 1, 5, 2, 3, 1, 2, 4, 2, 4};

// Converts the given numeric string to the corresponding integer
// (by calling stoi).
// If the given string is not numeric, returns zero.
unsigned int stoi_with_check(const string& str)
{
    bool is_numeric = true;
    for(unsigned int i = 0; i < str.length(); ++i)
    {
        if(not isdigit(str.at(i)))
        {
            is_numeric = false;
            break;
        }
    }
    if(is_numeric)
    {
        return stoi(str);
    }
    else
    {
        return 0;
    }
}

// checks if string is 1 character long and makes it lower case
char one_char_input(string& input)
{
    if (input.length() != 1)
        return '0';
    return tolower(input.at(0));
}

// Asks the user for input and makes the board so the game can start
Board start_game()
{
    // stores the user input
    string input;
    // stores the command character from user input
    char command;
    // stores values: seed or numbers to board
    int value;

    // loops through until user gives command r or i (R or I too)
    for ( ;; )
    {
        cout << "Select start (R for random, I for input): ";

        cin >> input;
        command = one_char_input(input);

        if (command == 'r' or command == 'i')
            break;
    }

    // random board generation loop
    // asks for seeds
    if (command == 'r')
    {
        cout << "Enter seed value: ";
        for ( ;; )
        {
            cin >> input;
            // returns 0 if input is incorrect (not an int)
            value = stoi_with_check(input);
            if (value != 0)
                return Board(value);
            cout << "Seed value must be a positive number: ";

        }
    }

    // board generation with users numbers

    // vector to store the numbers
    vector<int> board_values;
    cout << "Input: ";

    // loops until the vector has 25 correct numbers
    for ( ;; )
    {
        cin >> input;
        // makes values numbers if possible
        value = stoi_with_check(input);
        // checks if numbers are from 1-5
        if (value > 0 && value < 6)
        {
            board_values.push_back(value);
            if (board_values.size() == 25)
                return Board(board_values);
            continue;
        }
        cout << "All values must be from 1-5" << endl;

    }

}



int main()
{
    int x, y;
    string input;

    Board board = start_game();
    board.print_board();
    // loop for playing the game
    for ( ;; )
    {

        cout << "Enter removable element (x, y): ";

        cin >> input;
        if (one_char_input(input) == 'q')
        {
            cout << "Quitting" << endl;
            break;
        }
        x = stoi_with_check(input);
        cin >> input;
        y = stoi_with_check(input);

        if (board.delete_square(x, y))
            board.print_board();

    }
    return 0;
}
