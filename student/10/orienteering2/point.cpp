#include "point.hh"

Point::Point(char marker, int height, int x, int y, std::string name)
{
    marker_ = marker;
    height_ = height;
    x_coor_ = x;
    y_coor_ = y;
    name_ = name;
}

std::string Point::get_name()
{
    return name_;
}

char Point::get_marker()
{
    return marker_;
}
