#include "orienteeringmap.hh"
#include <memory>

OrienteeringMap::OrienteeringMap()
{

}

OrienteeringMap::~OrienteeringMap()
{

}

void OrienteeringMap::set_map_size(int width, int height)
{
    std::vector<std::shared_ptr<Point>> column(width, nullptr);
    std::vector<std::vector<std::shared_ptr<Point>>> map(height, column);

    map_ = map;
    width_ = width;
    height_ = height;

}

void OrienteeringMap::add_point(std::string name, int x, int y, int height,
                                char marker)
{
    if (all_points_.find(name) == all_points_.end())
    {
        std::shared_ptr new_point =
                std::make_shared<Point>(marker, height, x, y, name);
        all_points_.insert({name, new_point});

        map_.at(y-1).at(x-1) = new_point;
    }

}

bool OrienteeringMap::connect_route(std::string from, std::string to,
                                    std::string route_name)
{
    // checks if the data has the given points
    if (all_points_.find(from) == all_points_.end() &&
        all_points_.find(to) == all_points_.end())
    {
        return false;
    }


    // makes a new route if the route name is not found
    if (routes_first_point_.find(route_name) == routes_first_point_.end())
    {
        std::shared_ptr<route_point_> new_point =
                std::make_shared<route_point_>(route_point_{all_points_.at(from),
                std::make_shared<route_point_>(route_point_{all_points_.at(to),
                                                            nullptr})});

        routes_first_point_.insert({route_name, new_point});
        return true;

    }

    // Adds new connection in the middle or at the end of the given route
    std::shared_ptr<route_point_> temp =
            routes_first_point_.at(route_name);

    while (temp->point != all_points_.at(from))
    {
        temp = temp->next;
    }

    std::shared_ptr<route_point_> new_point =
            std::make_shared<route_point_>
            (route_point_{all_points_.at(to), temp->next});
    temp->next = new_point;

    return true;

}

void OrienteeringMap::print_map() const
{
    std::cout << " ";
    for (int i = 1; i <= width_; ++i) // printing the first row of numbers
    {
        if (i < 10)
        {
            std::cout << "  ";
        }
        else if (i < 100)
        {
            std::cout << " ";
        }
        std::cout << i;
    }

    std::cout << std::endl;
    char current_marker = '.';
    for (int i = 1; i <= height_; ++i)
    {
        if (i < 10)
        {
            std::cout << " ";
        }
        std::cout << i;
        for (auto point : map_.at(i-1))
        {
            if (point == nullptr)
            {
                current_marker = '.';
            } else {
                current_marker = point->get_marker();
            }
            std::cout << "  " << current_marker;
        }
        std::cout << std::endl;
    }
}

void OrienteeringMap::print_routes() const
{
    std::cout << "Routes:" << std::endl;
    for (auto& routes : routes_first_point_)
    {
        std::cout << " - " << routes.first << std::endl;
    }
}

void OrienteeringMap::print_points() const
{
    return;
}

void OrienteeringMap::print_route(const std::string &name) const
{
    return;
}

void OrienteeringMap::route_length(const std::string &name) const
{
    return;
}

void OrienteeringMap::greatest_rise(const std::string &point_name) const
{
    return;
}
