#include "player.hh"
#include <iostream>

Player::Player(std::string name)
{
    name_ = name;
    points_ = 0;
}

std::string Player::get_name() const
{
    return name_;
}

int Player::get_points() const
{
    return points_;
}

void Player::add_points(int points_to_add)
{
    if (points_to_add <= 0)
        return;
    points_ += points_to_add;

    if (points_ > 50)
    {
        points_ = 25;
        std::cout << name_ << " gets penalty points!" << std::endl;
    }
}

bool Player::has_won()
{
    if (points_ == 50)
        return true;
    return false;
}
