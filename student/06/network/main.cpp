/*
 * Program to help sort networks of people or items
 * Each person has to have its unique name / ID (string)
 *
 * Eppu Hassinen
 * 17.2.2022
 * Student ID: 50044786
 * eppu.hassinen@tuni.fi
 *
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

// prints the network from the starting id
// recursive function
void print_network(const std::string& id,const std::map<std::string,
                   std::vector<std::string>>& network,unsigned int i=0)
{
    // prints the correct amount of dots
    for (unsigned int n = 0; n < i; ++n)
    {
        std::cout << "..";
    }
    // prints the current id
    std::cout << id << std::endl;

    // if the current id has no one below returns
    if (network.find(id) == network.end())
        return;

    // checks if the id's under current id has their own networks
    for (auto& sub_id : network.at(id))
    {
        print_network(sub_id, network, i + 1);
    }
}

// returns amount of ids in the network below start id
// ignores the start id
int calculate_network(const std::string& id,const std::map<std::string,
                   std::vector<std::string>>& network, int sum=-1)
{
    sum++; // adds one to the calculator

    // if the current id has no one below returns
    if (network.find(id) == network.end())
    {
        return sum;
    }
    // goes through the network below id
    for (auto& sub_id : network.at(id))
    {
        sum = calculate_network(sub_id, network, sum);
    }

    return sum;
}

// returns depth of the longest path in the network
unsigned int network_depth(const std::string& id, const std::map<std::string,
                           std::vector<std::string>>& network, unsigned int sum = 1)
{
    // if the id has no networks below returns sum
    if (network.find(id) == network.end())
    {
        return sum;
    }
    // tests which depth below is longest
    unsigned int test_sum = 0, biggest_sum = 0;
    for (auto& sub_id : network.at(id))
    {
        test_sum = network_depth(sub_id, network, sum + 1);
        if (test_sum > biggest_sum)
        {
            biggest_sum = test_sum;
        }
    }

    return biggest_sum;

}

int main()
{
    std::map<std::string, std::vector<std::string>> network;


    while(true)
    {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        std::string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            if (network.find(id1) == network.end())
            {
                network.insert({id1, {id2}});
            }
            else
            {
                network.at(id1).push_back(id2);
            }

        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            print_network(id, network);

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            std::cout << calculate_network(id, network) << std::endl;

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            std::cout << network_depth(id, network) << std::endl;
        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
