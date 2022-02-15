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
    string row, name;
    int new_points;
    string::size_type splitter;
    while (getline(input_file, row))
    {
        splitter = row.find(':');
        name = row.substr(0, splitter);
        new_points = stoi(row.substr(splitter + 1));

        if (points.find(name) == points.end())
        {
            points.insert({name, new_points});
        }
        else
        {
            points.at(name) += new_points;
        }
    }
    input_file.close();
    cout << "Final scores:" << endl;
    for (const auto& i : points)
    {
        cout << i.first << ": " << i.second << endl;
    }


    return EXIT_SUCCESS;
}
