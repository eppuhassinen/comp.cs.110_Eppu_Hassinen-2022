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

int Point::get_x()
{
    return x_coor_;
}

int Point::get_y()
{
    return y_coor_;
}

int Point::get_height(int height)
{
    return height_ - height;
}
