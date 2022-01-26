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
    Board(int random_seed, unsigned int board_side);

    // Makes board with defined numbers
    Board(const std::vector<int>& numbers, unsigned int b);

    // Prints the board
    void print_board() const;

private:
    std::vector<std::vector<int>> game_board_;
    unsigned int board_side_;
};

#endif // BOARD_HH
