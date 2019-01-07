#include "Coordinate.h"
#include <string>

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

/***** Complete this class. *****/
 //Input operator overloading for reading input file containg data of boundary
istream& operator >>(istream& ins, Coordinate& coordinate){

	string a,b;

	getline(ins,a,',');
	coordinate.latitude=stod(a);
	getline(ins,b,'\n');
	coordinate.longitude=stod(b);

	return ins;

}
//Setter function to assign values of latitude and longitude
void Coordinate::set_latitude(double lat){
   latitude=lat;
}

void Coordinate::set_longitude(double lon){
   longitude=lon;
}
//Getter function to get value of latitude and longitude
double Coordinate::get_latitude() const{

return latitude;
}


double Coordinate::get_longitude() const{

return longitude;
}