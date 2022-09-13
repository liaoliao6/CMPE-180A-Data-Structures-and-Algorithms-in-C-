#include "Coordinate.h"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

/***** Complete this class. *****/

istream& operator >> (istream& ins, Coordinate& coordinate)
{
    string latitude;
    string longitude;
    getline(ins, latitude, ','); //read latitude
    getline (ins, longitude); //read longitude
    coordinate.latitude = stod(latitude); //convert string to double
    coordinate.longitude = stod(longitude);
    return ins;
}

double Coordinate :: get_latitude() const
{
    return latitude;
}

double Coordinate :: get_longitude() const
{
    return longitude;
}
