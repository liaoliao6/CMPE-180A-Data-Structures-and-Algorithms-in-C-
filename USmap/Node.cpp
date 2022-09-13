#include <math.h>
#include "Node.h"

Node :: Node()
{

}

Node :: Node(Coordinate &coordinate)
{
    convert_coordinate(coordinate);
    name = "";
    state = "";     //if this node belong to the boundary.
    longitude = coordinate.get_latitude();  //get node latitude
    latitude = coordinate.get_longitude();  //get node longitude
}

Node :: Node(City &city)
{
    convert_coordinate(city.get_coordinate());
    name = city.get_name(); //get city name
    state = city.get_state();   //get city state
    longitude = city.get_coordinate().get_latitude();
    latitude = city.get_coordinate().get_longitude();
}


bool Node :: operator > (const Node& other) //compare two nodes
{
    if (row > other.row)
        return true;
    else if ((row == other.row) && (col >= other.col))
        return true;
    else
        return false;
}
bool Node :: operator == (const Node& other)    //Check if two nodes are at the same place
{
    if ((row == other.row) && (col == other.col))
        return true;
    else return false;
}

ostream& operator << (ostream& outs, const Node& node)  //output city nodes
{
    outs << "*" << node.name << " " << node.state;
    return outs;
}


void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

int Node :: get_row()   //get node's row
{
    return row;
}

int Node :: get_col()   //get node's col
{
    return col;
}

string Node :: get_name()   //get node's name
{
    return name;
}

string Node :: get_state()  //get node's state
{
    return state;
}

void Node :: set_name(string newName)   //set node name
{
    name = newName;
}

void Node :: set_state(string newState) //set node state
{
    state = newState;
}