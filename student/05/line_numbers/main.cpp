#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    string input_file_name, output_file_name;
    cout << "Input file: ";
    getline(cin, input_file_name);

    cout << "Output file: ";
    getline(cin, output_file_name);

    ifstream input_file(input_file_name);
    ifstream output_file(output_file_name);

    if (not input_file)
    {
        cout << "Error! The file " << input_file_name
             << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }
    string row;
    while(getline(input_file, row))
    {
        cout << row << endl;
    }

    input_file.close();
    return EXIT_SUCCESS;
}
