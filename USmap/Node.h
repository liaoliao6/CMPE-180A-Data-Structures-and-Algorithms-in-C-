#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A node of a linked list.
 */
class Node
{
public:

    Node();

    Node(Coordinate &coordinate);

    Node(City &city);

    Node *next;  // pointer to the next node in the list

    double latitude;

    double longitude;

    /**
     * Overloaded > operator to compare two nodes.
     */
    bool operator > (const Node& other);

    bool operator == (const Node& other);

    /**
     * Overloaded stream output insertion operator
     * to output a node to the output stream.
     * @param outs the output stream.
     * @param node the node to output.
     * @return the output stream.
     */
    friend ostream& operator <<(ostream& outs, const Node& node);

    int get_row();

    int get_col();

    string get_name();  //get city name

    string get_state(); //get state name

    void set_name(string newName);  //change node city name

    void set_state(string newState);    //change node state name

private:
    string name;   // city name,  or the empty string for a border location
    string state;  // city state, or the empty string for a border location
    int row;       // print row
    int col;       // print column

    /**
     * Convert a coordinate to a row and a column.
     * @param coordinate the coordinate to convert.
     */
    void convert_coordinate(const Coordinate& coordinate);
};

#endif /* NODE_H_ */