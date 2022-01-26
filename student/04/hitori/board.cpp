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


    for (unsigned int j = 0; j < board_side_; ++j)
    {
        game_board_.push_back(vector<int>(board_side_));
        for (unsigned int i = 0; i < board_side_; ++i)
        {
            game_board_.at(j).at(i) = distr(gen);
        }
    }

}

Board::Board(const std::vector<int> &numbers, unsigned int board_side)
{
    board_side_ = board_side;

    for (unsigned int j = 0; j < board_side_; ++j)
    {
        game_board_.push_back(vector<int>(board_side_));
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
