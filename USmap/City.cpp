/* Author: Jingjing Bu */

#include "City.h"

istream& operator >>(istream& ins, City& city)
{
    getline (ins, city.name, ','); //get city name
    getline (ins, city.state, ','); //get city state
    ins >> city.coordinate;
    return ins;
}

ostream& operator <<(ostream& outs, const City& city)
{
    outs << city.name << " " << city.state << " ";
    return outs;
}

Coordinate City :: get_coordinate()
{
    return coordinate;
}

string City :: get_name()
{
    return name;
}

string City :: get_state()
{
    return state;
}