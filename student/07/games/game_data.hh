/*
 * game_data class to store players games and scores
 * Handles printing different things and adding players and games.
 *
 * Eppu Hassinen
 * Student ID: 50044786
 * email: eppu.hassinen@tuni.fi
 */
#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

class Game_data
{
public:
    Game_data();
    // Adds a player.
    // Parameter vector must be "vector<string> = {game, player, score}
    // Returns true if adding was successful, else returns false
    bool add_player(std::vector<std::string> line_vector);
    // Prints all games from data_
    void print_games();
    // Prints scores and players of a given game
    void print_game(std::string game_name);
    // Prints all players
    void print_players();
    // Prints all games a given player has played
    void player(std::string player_name);

    // Returns true if given game exists
    bool has_game(std::string game_name);
    // Adds a game with no players or scores
    // Returns true if adding was successful
    bool add_game(std::string game_name);
    // Removes a player from all games
    // Returns true if removing was successful
    bool remove(std::string player_name);
private:
    // map to store player data. set<struct> would would maybe be better
    // format map<string game, map<int score, string player>>
    std::map<std::string, std::map<int, std::set<std::string>>> data_ = {};
    // set to store all players for easy printing
    std::set<std::string> players_ = {};
    // returns true if player has a score in game
    int has_a_score(std::string game, std::string player);
};

#endif // GAME_DATA_H
