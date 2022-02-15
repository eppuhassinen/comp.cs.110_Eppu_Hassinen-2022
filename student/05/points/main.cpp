#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    cout << "Input file: ";
    string file_name;
    getline(cin, file_name);

    ifstream input_file(file_name);

    if (not input_file)
    {
        cout << "Error! The file " << file_name << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }

    map<string, int> points;
    string row;
    while (getline(input_file, row))
    {
        cout << row << endl;
    }


    return EXIT_SUCCESS;
}
