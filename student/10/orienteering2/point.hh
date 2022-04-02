#ifndef POINT_HH
#define POINT_HH

#include <iostream>

class Point
{
public:
    // constructor needs all the necessary inputs to make a point
    Point(char marker, int height, int x, int y, std::string name);

    // returns the name of the point
    std::string get_name();

    // returns the marker of the point
    char get_marker();

    // returns x and y coordinates
    // (used for calculation of distance from point to another)
    int get_x();
    int get_y();

private:

    char marker_;
    std::string name_;
    int height_;
    int x_coor_;
    int y_coor_;


};

#endif // POINT_HH
