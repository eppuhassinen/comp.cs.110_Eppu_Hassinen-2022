/*  COMP.CS.100 Project 2: GAME STATISTICS
 * ===============================
 * EXAMPLE SOLUTION
 * ===============================
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
 *  The data file's lines should be in format game_name;player_name;score
 * Otherwise the program execution terminates instantly (but still gracefully).
 *
 * */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>


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

int main()
{
    // Data structure to save games, players and scores
    std::map<std::string, std::map<std::string, int>> data;
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
        if (!add_player(row, data))
        {
            std::cout << "Error: Invalid format in file." << std::endl;
            return EXIT_FAILURE;
        }
    }

    // for testing
    for (auto& game : data)
    {

        for (auto& row : game.second)
        {
            std::cout << game.first << " : " << row.first << " : " << row.second << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
