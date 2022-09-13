#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>

#include "Coordinate.h"

using namespace std;

/**
 * City data.
 */
class City
{
public:

    /***** Complete this class. *****/

    /**
     * Overloaded input stream operator to read a city
     * from an input stream.
     * @param ins the input stream.
     * @param city the city to read.
     * @return the input stream.
     */
    friend istream& operator >>(istream& ins, City& city);

    /**
     * Overloaded output stream operator to output a city
     * to an output stream.
     * @param outs the output stream.
     * @param city the city to output.
     * @return the output stream.
     */
    friend ostream& operator <<(ostream& outs, const City& city);

    Coordinate get_coordinate();  //get city's coordinate

    string get_name();  //get city's name

    string get_state(); //get state

private:
    string name;
    string state;
    Coordinate coordinate;
};

#endif /* CITY_H_ */