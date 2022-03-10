/*  COMP.CS.100 Project 2: GAME STATISTICS
 *
 * This is a game statistic program. It saves games players and scores.
 * Scores must be positive integers. Extra parameters in commands will be ignored.
 *
 *  Acts as a game statistics with n commands:
 * ALL_GAMES - Prints all known game names
 * GAME <game name> - Prints all players playing the given game
 * ALL_PLAYERS - Prints all known player names
 * PLAYER <player name> - Prints all games the given player plays
 * ADD_GAME <game name> - Adds a new game
 * ADD_PLAYER <game name> <player name> <score> - Adds a new player with the
 * given score for the given game, or updates the player's score if the player
 * already plays the game
 * REMOVE_PLAYER <player name> - Removes the player from all games
 *
 * command can be lower case or upper case. If a game or player name contains
 * spaces, it must be written: ADD_GAME "Sexy Hiking"
 *
 *  The data file's lines should be in format game_name;player_name;score
 * Otherwise the program execution terminates instantly
 *
 * Eppu Hassinen
 * Student ID: 50044786
 * email: eppu.hassinen@tuni.fi
 * */
#include "game_data.hh"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cstring>


// Casual split func, if delim char is between "'s, ignores it.
std::vector<std::string> split( const std::string& str, char delim = ';' )
{
    std::vector<std::string> result = {""};
    bool inside_quatation = false;
    for ( auto current_char : str )
    {
        if ( current_char == '"' )
        {
            inside_quatation = not inside_quatation;
        }
        else if ( current_char == delim and not inside_quatation )
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if ( result.back() == "" )
    {
        result.pop_back();
    }
    return result;
}

// Opens a text file from applications build directory with user given name
std::ifstream open_file()
{
    std::cout << "Give a name for input file: ";
    std::string file_name; // name of file to be opened
    std::getline(std::cin, file_name);
    std::ifstream data_file(file_name); // opens the file
    return data_file;
}

// Adds a player to the data set
bool add_player(const std::string input_line,
               std::map<std::string, std::map<std::string, int>>& data)
{
    // checks if input line has exactly 3 arguments, returns false if not
    auto line_vector = split(input_line);
    if (line_vector.size() != 3)
        return false;

    // If the game in "line_vector.at(0)" is not already in data set, adds it
    if (data.find(line_vector.at(0)) == data.end())
    {
        std::pair<std::string, int> pair (line_vector.at(1), std::stoi(line_vector.at(2)));
        data.insert({line_vector.at(0), {pair}});
        return true;
    }

    // If game was already in the map, adds players to it
    data.at(line_vector.at(0)).insert({line_vector.at(1), std::stoi(line_vector.at(2))});
    return true;
}

void user_interface(Game_data& data)
{
    while (true)
    {
        // users input in format "<command> <parameter> <parameter>" etc.
        std::string input = "";
        std::cout << "games> ";
        std::getline(std::cin, input);

        if (input == "")
        {
            std::cout << "Error: Invalid input." << std::endl;
            continue;
        }

        // command is a vector<str> = {command, parameter 1, param 2, etc.}
        auto command = split(input, ' ');

        for (auto& n : command.at(0)) // Makes the command uppercase
        {
            n = toupper(n);
        }

        if (command.at(0) == "QUIT")
        {
            return;
        }

        // Prints all games in ASCII order
        if (command.at(0) == "ALL_GAMES")
        {
            data.print_games();
            continue;
        }

        // Prints scores and players of a given game
        if (command.at(0) == "GAME" && command.size() > 1)
        {
            data.print_game(command.at(1));
            continue;
        }

        // Prints all players in ASCII order
        if (command.at(0) == "ALL_PLAYERS")
        {
            data.print_players();
            continue;
        }

        // Prints all games a player has played
        if (command.at(0) == "PLAYER" && command.size() > 1)
        {
            data.player(command.at(1));
            continue;
        }

        // Adds a game
        if (command.at(0) == "ADD_GAME" && command.size() > 1)
        {
            // Method returns false if game already exists
            if (not data.add_game(command.at(1)))
            {
                std::cout << "Error: Already exists." << std::endl;
                continue;
            }

            std::cout << "Game was added." << std::endl;
            continue;
        }

        // Adds a player and a score to a game
        if (command.at(0) == "ADD_PLAYER" && command.size() > 3)
        {
            // Stops this command if game is not found
            if (not data.has_game(command.at(1)))
            {
                std::cout << "Error: Game could not be found." << std::endl;
                continue;
            }

            // Adds a player and a score. If player already has a score, updates it
            // Method returns true if adding was successful
            if (data.add_player({command.at(1), command.at(2), command.at(3)}))
            {
                std::cout << "Player was added." << std::endl;
                continue;
            }

            std::cout << "Player could not be added." << std::endl;
            continue;
        }

        // Removes a players data from all games
        if (command.at(0) == "REMOVE" && command.size() > 1)
        {
            // Method returns false if player was not found
            if (not data.remove(command.at(1)))
            {
                std::cout << "Error: Player could not be found." << std::endl;
                continue;
            }
            std::cout << "Player was removed from all games." << std::endl;
            continue;
        }

        // If none of the commands worked, input was invalid
        std::cout << "Error: Invalid input." << std::endl;


    }
}

int main()
{
    // Data structure to save games, players and scores
    Game_data data;
    // Opens a text file
    auto file = open_file(); // returns false if the file couldn't be opened
    if (not file)
    {
        std::cout << "Error: File could not be read." << std::endl;
        return EXIT_FAILURE;
    }
    // Goes through line by line and saves the information to "data"
    std::string row;
    while (getline(file, row))
    {

        if (!data.add_player(split(row)))
        {
            std::cout << "Error: Invalid format in file." << std::endl;
            return EXIT_FAILURE;
        }
    }

    file.close();

    // This is where the magic happens
    user_interface(data);

    return EXIT_SUCCESS;
}
