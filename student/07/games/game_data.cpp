/*
 * Eppu Hassinen
 * Student ID: 50044786
 * email: eppu.hassinen@tuni.fi
 */
#include "game_data.hh"

Game_data::Game_data()
{

}

// Adds a player to the data set
bool Game_data::add_player(std::vector<std::string> line_vector)
{
    {
        // checks if input line has exactly 3 arguments, returns false if not
        if (line_vector.size() != 3)
            return false;
        int score = 0;

        // Returns false if score can't be made int
        try {
            score = std::stoi(line_vector.at(2));
        }  catch (std::exception& e) {
            return false;
        }

        // Takes inputs to easier understood strings
        std::string game = line_vector.at(0), player = line_vector.at(1);

        // Adds player to player list
        players_.insert(player);

        // If the game is not already in data set, adds it
        if (data_.find(game) == data_.end())
        {
            std::pair<int, std::set<std::string>> pair (score, {player});
            data_.insert({game, {pair}});
            return true;
        }

        // If player has an old score, removes the player
        int current_score = has_a_score(game, player);
        if (current_score != -1)
        {
            data_.at(game).at(current_score).erase(player);

            // If the score was left with no players, removes the score
            if (data_.at(game).at(current_score).size() == 0)
                data_.at(game).erase(current_score);
        }

        // If game does not have the current score, adds it
        if (data_.at(game).find(score) == data_.at(game).end())
        {
            data_.at(game).insert({score, {player}});
            return true;
        }

        // If game has already the score, adds players to it
        data_.at(game).at(score).insert(player);
        return true;
    }
}

// Prints all games in ASCII order
void Game_data::print_games()
{
    std::cout << "All games in alphabetical order:" << std::endl;
    for (const auto& pair : data_)
    {
        std::cout << pair.first << std::endl;
    }
}

// Prints all scores and players of a given game
void Game_data::print_game(std::string game_name)
{
    // Checks if game is in data_
    if (data_.find(game_name) == data_.end())
    {
        std::cout << "Error: Game could not be found." << std::endl;
        return;
    }

    std::cout << "Game " << game_name <<  " has these scores and players,"
                " listed in ascending order:" << std::endl;

    // Goes through all scores in a game
    for (const auto& pair : data_.at(game_name))
    {
        std::cout << pair.first << " : "; // prints the score

        for (const auto& name : pair.second) // Loops through players
        {
            // checks if player is the first player
            if (pair.second.find(name) != pair.second.begin())
            {
                std::cout << ", ";
            }
            std::cout << name;
        }
        std::cout << std::endl;
    }
}

// prints all players in ASCII order
void Game_data::print_players()
{
    std::cout << "All players in alphabetical order:" << std::endl;
    for (const auto& player : players_)
    {
        std::cout << player << std::endl;
    }
}

// Prints all the games a given player has played
void Game_data::player(std::string player_name)
{

    // Checks if the player is in the data set, if not returns
    if (players_.find(player_name) == players_.end())
    {
        std::cout << "Error: Player could not be found." << std::endl;
        return;
    }

    std::cout << "Player " << player_name << " playes the following games:" <<
                 std::endl;

    // Loops through all games and checks if the player has a score
    for (const auto& pair : data_)
    {
        if (has_a_score(pair.first, player_name) == -1)
        {
            // continues if the player has no score in the game
            continue;
        }
        std::cout << pair.first << std::endl;
    }
}

// Checks if a game is already in the data
// Returns true if data has the game
bool Game_data::has_game(std::string game_name)
{
    if (data_.find(game_name) == data_.end())
    {
        return false;
    }
    return true;
}

// Adds a new empty game to the data
bool Game_data::add_game(std::string game_name)
{
    if (has_game(game_name))
    {
        // Returns false if the game is in data_
        return false;
    }


    data_.insert({game_name, {}});
    return true;
}

// Removes a player from all games
bool Game_data::remove(std::string player_name)
{
    // Returns false if the player is not in players_
    if (players_.find(player_name) == players_.end())
    {
        return false;
    }

    players_.erase(player_name); // erases player from players_

    // Loops through all games
    for (auto& pair : data_)
    {
        // checks if a player has a score the current game
        int score = has_a_score(pair.first, player_name);
        if (score == -1) // If not continues
        {
            continue;
        }
        // removes the score and player
        pair.second.at(score).erase(player_name);
        if (pair.second.at(score).size() == 0)
        {
            pair.second.erase(score);
        }

    }

    return true;
}

// Checks if player has a score in a game. Returns the score
// If player does not have a score,  returns -1
int Game_data::has_a_score(std::string game, std::string player)
{
    for (const auto& pair : data_.at(game))
    {
        for (const auto& players : pair.second)
        {
            if (players == player)
                return pair.first;
        }
    }
    return -1;
}
