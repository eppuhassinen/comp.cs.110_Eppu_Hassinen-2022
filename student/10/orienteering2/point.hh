#ifndef POINT_HH
#define POINT_HH

#include <iostream>

class Point
{
public:
    Point(char marker, int height, int x, int y, std::string name);

    std::string get_name();

    char get_marker();
private:

    char marker_;
    std::string name_;
    int height_;
    int x_coor_;
    int y_coor_;


};

#endif // POINT_HH
