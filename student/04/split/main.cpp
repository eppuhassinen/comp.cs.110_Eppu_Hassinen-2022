#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> split(const std::string& input,
                               char splitter, bool include_blanks=false)
{
    std::vector<std::string> splitted;
    std::string::size_type current_position = 0;

    for ( ;; )
    {
        current_position = input.find(splitter);
        if (current_position == std::string::npos)
        {
            splitted.push_back(input);
            return splitted;
        }
        if ( current_position > 0 )
        {
            splitted.push_back(input.substr(0, current_position));
            input.erase(0, current_position);
        } else
        {
            if (!include_blanks)
                splitted.push_back("");
            input.erase(0, 1);
        }

    }
}
// Do not change main function


int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
