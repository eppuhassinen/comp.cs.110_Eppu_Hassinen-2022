/*
 *   Program author
 *   Name: Eppu Hassinen
 *   Student number: 50044786
 *   UserID: xrepha
 *   E-Mail: eppu.hassinen@tuni.fi
 *
 *   */

#include "board.hh"
#include <random>

using namespace std;

Board::Board(int random_seed, unsigned int board_side)
{
    board_side_ = board_side;
    default_random_engine gen(random_seed);
    uniform_int_distribution<int> distr(1, board_side_);

    // generates board vector<vector<int>> with random numbers
    for (unsigned int j = 0; j < board_side_; ++j)
    {
        game_board_.push_back(vector<int>(board_side_));
        reversed_game_board_.push_back(vector<int>(board_side_));
        for (unsigned int i = 0; i < board_side_; ++i)
        {
            game_board_.at(j).at(i) = distr(gen);
        }
    }

}

Board::Board(const std::vector<int> &numbers, unsigned int board_side)
{
    board_side_ = board_side;

    // generates board vector<vector<int>> with given numbers
    for (unsigned int j = 0; j < board_side_; ++j)
    {
        game_board_.push_back(vector<int>(board_side_));
        reversed_game_board_.push_back(vector<int>(board_side_));
        for (unsigned int i = 0; i < board_side_; ++i)
        {
            game_board_.at(j).at(i) = numbers.at(board_side_ * j + i);
        }
    }
}

void Board::print_board() const
{
    cout << "=================" << endl;
    cout << "|   | 1 2 3 4 5 |" << endl;
    cout << "-----------------" << endl;
    for (unsigned int j = 0; j < board_side_; ++j)
    {
        cout << "| " << j + 1 << " |";

        for (unsigned int i = 0; i < board_side_; ++i)
        {
            if (game_board_.at(j).at(i) == 0)
            {
                cout << "  ";
            } else
            {
                cout << " " << game_board_.at(j).at(i);
            }
        }
        cout << " |" << endl;
    }
    cout << "=================" << endl;


}

bool Board::delete_square(int i, int j)
{
    --i; --j;
    if (i < 0 or i > 4 or j < 0 or j > 4)
    {
        cout << "Out of board" << endl;
        return false;
    }
    if (game_board_.at(j).at(i) == 0)
    {
        cout << "Already removed" << endl;
        return false;
    }
    game_board_.at(j).at(i) = 0;
    return true;
}

bool Board::status()
{
    // first checks if lost
    if (alone_squares() or adjacent_empties())
        return true;
    // update reversed board to more easily access the vertical rows
    for (unsigned int i = 0; i < board_side_ ; ++i)
    {
        for (unsigned int j = 0; j < board_side_ ; ++j)
        {
            reversed_game_board_.at(i).at(j) = game_board_.at(j).at(i);
        }
    }
    // check if game is won
    if (!unique_vectors(game_board_))
        return false;
    if (!unique_vectors(reversed_game_board_))
        return false;

    // if we got here, the game is won
    cout << "You won" << endl;
    return true;
}

bool Board::adjacent_empties()
{
    for (unsigned int j = 0; j < board_side_; ++j)
    {

        for (unsigned int i = 0; i < board_side_ - 1; ++i)
        {
            // checks if two empty squares are adjacent
            // Loses*
            if (game_board_.at(j).at(i) + game_board_.at(j).at(i + 1) == 0)
            {
                cout << "You lost" << endl;
                return true;
            }
            if (j + 1 < board_side_ &&
                    game_board_.at(j).at(i) + game_board_.at(j + 1).at(i) == 0)
            {
                cout << "You lost" << endl;
                return true;
            }




        }

    }
    return false;
}

bool Board::alone_squares()
{
    int current_square;

    for (unsigned int j = 0; j < board_side_; ++j)
    {


        for (unsigned int i = 0; i < board_side_; ++i)
        {
            current_square = 0;
            // checks if a square isnt by any other squares
            // Checks one by one all adjacent squares from a square which
            // isn't zero
            if (game_board_.at(j).at(i) == 0)
                continue;
            if (i + 1 < board_side_) // check for vector sizes
                current_square += game_board_.at(j).at(i + 1);
            if (j + 1 < board_side_) // check for vector sizes
                current_square += game_board_.at(j + 1).at(i);
            if (i - 1 < board_side_) // check for vector sizes
                current_square += game_board_.at(j).at(i - 1);
            if (j - 1 < board_side_) // check for vector sizes
                current_square += game_board_.at(j - 1).at(i);

            if (current_square == 0)
            {
                cout << "You lost" << endl;
                return true;
            }


        }


    }

    return false;
}

bool Board::unique_vectors(std::vector<std::vector<int>>& rows)
{
    vector<int> calculator(6, 0);
    // calculates duplicates
    for (vector<int>& row : rows)
    {
        for (int number : row)
        {
            if (number != 0)
                ++calculator.at(number);
        }
        for (int& number : calculator)
        {
            if (number > 1)
                return false;
            number = 0;
        }
    }
    return true;
}
