#include <math.h>
#include "Node.h"

/***** Complete this class. *****/
//Getter function to access data in node
string Node::get_name() const{
	return name;
}
string Node::get_state() const{
	return state;
}
int Node::get_row() const{
	return row;
}
int Node::get_col() const{
	return col;
}
//Node Constructor
Node::Node(const Coordinate& coordinate):next(nullptr), name(""), state("")
{
	convert_coordinate(coordinate);
}

Node::Node(const City& city):next(nullptr)
{
	convert_coordinate(city.get_coordinate());
	name=city.get_name();
	state=city.get_state();
}
//Coordinates are converted to row and column
void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}
// '>' operator is overloaded to compare row and column
bool Node::operator >(const Node& other)
{
	bool a=false;
	if (row>other.row){

		a=true;

	}else if((row==other.row)&&(col>other.col)){

		a=true;
	}

	return a;
}
//'<<' operator overloaded to print boundary and city
ostream& operator <<(ostream& outs, const Node& node){
    City p;
    string n,s;
if(node.state=="" && node.name=="")
{
		outs<<"#";
}
	 else if(node.state!="" && node.name!="")
	 {
	 	outs<<"*"<<node.name<<" "<<node.state;
	  // n=node.name;
	  // s=node.state;
   //     p.set_name(n);
   //     p.set_name(s);
   //  //  outs<<p;
	 
	 }


	return outs;

}