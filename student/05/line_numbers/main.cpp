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

    fstream input_file(input_file_name);
    fstream output_file(output_file_name);

    if (not input_file)
    {
        cout << "Error! The file " << input_file_name
             << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }

    if (not output_file)
    {
        cout << "Error! The file " << output_file_name
             << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }
    string row;
    int row_num = 1;

    while(getline(input_file, row))
    {
        output_file << row_num << " " << row << endl;
        ++row_num;
    }

    input_file.close();
    output_file.close();
    return EXIT_SUCCESS;
}
