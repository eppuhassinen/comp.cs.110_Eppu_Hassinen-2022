#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>

class Player
{
public:
    Player(std::string);

    // Returns player name
    std::string get_name() const;

    // Returns player points
    int get_points() const;

    // Adds points to the player
    // If points go over 50 score is 25
    void add_points(int);

    // Returns true if player has won
    // In other words has exactly 50 points
    bool has_won();

private:
    // store player points and name
    int points_;
    std::string name_;
};

#endif // PLAYER_HH
