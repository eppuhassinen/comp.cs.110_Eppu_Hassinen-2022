/*
 * Orienteering
 *
 * Desc:
 * This is a program for saving points on a map and routes made of the points.
 * Each point can be on multiple routes. One point can't be more than once
 * in each route.
 * Program needs a text file for input. The data can't be changed after starting.
 *
 * Text file format needs to be formatted:
 *
 * 'Map width';'Map height'
 * 'Point name';'x coordinate';'y coordinate';'point height';'point marker char'
 * 'Second point name';'x coordinate'; etc.
 * ROUTES
 * 'Route name';'Point name';'Point name'; etc.
 * 'Second route name';'Point name'; etc.
 *
EXAMPLE INPUT FILE:

15;10
Tree;1;1;200;T
Landing;4;7;700;L
Stump;7;8;700;S
Rock;2;3;500;R
Boulder;5;5;650;B
Pond;4;1;340;P
Distant hut;13;9;800;D
ROUTES
Shorter;Tree;Rock;Boulder
Longer;Rock;Distant hut;Pond;Tree
Longest;Rock;Landing;Stump;Distant hut;Pond;Tree

 *
 * Commands:
 * -MAP,KARTTA prints the map with the markers as points
 * -POINTS,PISTEET prints all points in alphabetical order
 * -ROUTES,REITIT prints all routes in alphabetical order
 * -ROUTE,REITTI <Route name> prints all points in a route
 * -LENGTH,PITUUS <Route name> prints the length of the route
 * -RISE,NOUSU <Point name> prints the greatest rise from
 *  the given point and all the routes which have the rise
 * -QUIT,Q,EXIT,LOPETA quits the program
 *
 * All commands can be written in upper case or lower case
 * or a combination of the two. For example command eXiT works.
 *
 *
 *
 * Name: Eppu Hassinen
 * Student ID: 50044786
 * email: eppu.hassinen@tuni.fi
 * */

#include "orienteeringmap.hh"
#include "parser.hh"
#include "cli.hh"
#include <iostream>

int main()
{
    std::shared_ptr<OrienteeringMap> routes(new OrienteeringMap);
    std::cout << "Input> ";
    std::string input;
    getline(std::cin, input);
    if( not read_input_from_file(input, routes) )
    {
        return EXIT_FAILURE;
    }
    Cli cli(routes);
    while( cli.exec_prompt() ){ }
    return EXIT_SUCCESS;
}


