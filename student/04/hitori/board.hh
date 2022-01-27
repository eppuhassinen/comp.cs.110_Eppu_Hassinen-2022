/*
 *   Program author
 *   Name: Eppu Hassinen
 *   Student number: 50044786
 *   UserID: xrepha
 *   E-Mail: eppu.hassinen@tuni.fi
 *
 *   Class Board:
 *   This class contains the board and methods for different turns
 *   needed in the game.
 *
 *   Class needs 2 parameters:
 *   First an int as a random number seed, or a vector<int> that holds 25
 *   integers from 1-5
 *   */

#ifndef BOARD_HH
#define BOARD_HH
#include <vector>
#include <string>
#include <iostream>


class Board
{
public:
    // Makes board with random numbers
    Board(int random_seed, unsigned int board_side = 5);

    // Makes board with defined numbers
    Board(const std::vector<int>& numbers, unsigned int board_side = 5);

    // Prints the board
    void print_board() const;

    // Deletes a square
    // Returns false if square is out of board or already empty
    bool delete_square(int i, int j);

    // Analyze board
    // analyzes for winning and losing

    // Returns true if game ends and prints "You lost" or "You won"
    bool status();

private:
    std::vector<std::vector<int>> game_board_, reversed_game_board_;
    unsigned int board_side_;

    // returns true if there is adjacent empty squares
    bool adjacent_empties();

    // returns true if there is alone aquares with numbers
    bool alone_squares();

    // returns true if any of the vectors doesn't contain any duplicates
    // ignores zeros
    bool unique_vectors(std::vector<std::vector<int>>& rows);
};

#endif // BOARD_HH
