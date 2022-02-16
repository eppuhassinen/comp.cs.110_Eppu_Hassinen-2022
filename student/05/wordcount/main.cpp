/*
 * This program takes a text file as input. Goes through it and calculates
 * each words appearance in different rows.
 * Then it prints out in alphabetical order:
 *
 * word1 <Amount of rows where the word was>: <first row where the word was>,
 *      <second row where the word was>, <third>, etc. \n
 * word2 <Amount of rows where the word was>: <first row where the word was>,
 *      <second row where the word was>, <third>, etc. \n
 * word3 etc.
 *
 * Eppu Hassinen
 * 16.2.2022
 * eppu.hassinen@tuni.fi
 * Student ID: 50044786
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

char DELIMITOR = ' '; // the character which is used in splitting lines to words

int main()
{
    // asking for a file name
    cout << "Input file: ";

    string file_name; // string to  store the file name
    getline(cin, file_name);

    ifstream file(file_name); // opening the file


    if (not file) // testing if file opening was successfull
    {
        cout << "Error! The file " << file_name <<
                " cannot be opened." << endl;
        // ends program if file opening was not successful
        return EXIT_FAILURE;
    }

    string row, word; // strings to store different rows and words
    int row_indicator = 1; // int to check in which row a word was

    // map where the final calculation of words in rows is stored
    // {string word, vector<int>{word_in_row, word_in_row...}
    map<string, vector<int>> words_map;
    // set of words in row to easily ignore duplicates
    set<string> words_set;

    while(getline(file, row)) // loops through each row in the file
    {
        words_set.clear(); // clears any old words from the set
        stringstream ss(row); // stringstream to use in splitting the row
        while (getline(ss, word, DELIMITOR)) // loops through each word in row
        {
            // adds words of row to set
            // Ignores duplicates
            words_set.insert(word);
        }

        // Loops through words in words_set
        for (auto& unique_word : words_set)
        {
            // checks if word was in the map
            if (words_map.find(unique_word) == words_map.end())
            {
                // adds the word as a key in the map
                // Vector shows row number in the index 0
                words_map.insert({unique_word, vector<int>({row_indicator})});
            } else
            {
                // If the word was already a key in words_map

                // adds new index with int (row indicator) in the vector<int>
                words_map.at(unique_word).push_back(row_indicator);
            }
        }

        row_indicator++; // moving to the next row
    }

    file.close(); // closing the file


    // now all the words are in the map
    for (auto& word : words_map) // loops through the map
    {

        // prints the word and amount of the words
        cout << word.first << " " << size(word.second) << ":";

        // loops until the second last index of the vector
        for (vector<int>::size_type i = 0; i < size(word.second) - 1; i++)
        {
            // prints the row where word was
            cout << " " << word.second.at(i) << ",";
        }
        // prints the last row with \n
        cout << " " << word.second.back() << endl;
    }

    return EXIT_SUCCESS;
}
