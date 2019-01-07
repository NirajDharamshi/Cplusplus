#include <iostream>
#include "Node.h"

using namespace std;

long Node::constructor_count = 0;
long Node::copy_count = 0;
long Node::destructor_count = 0;
long Node::assign_count=0;
/***** Complete this file. *****/
long Node::get_destructor_count()
{
    return destructor_count;
}
long Node::get_copy_count()
{
    return copy_count;
}
long Node::get_constructor_count()
{
    return constructor_count;
}
Node& Node::operator =(const Node& rhs)
{
   value = rhs.value;
   assign_count++;
   return *this;
}


long Node::get_assign_count()
{
   return assign_count;
}
Node::Node(const long the_value)
{
    value = the_value;
    constructor_count++;
}
Node::Node(const Node& other)
{
    this->value = other.value;
    copy_count++;
}
void Node::reset()
{
    constructor_count=0;
    copy_count=0;
    destructor_count=0;
    assign_count=0;
}
bool Node::operator ==(const Node& other) const
{
    if(value == other.value)
        return true;
    else
        return false;
}
bool Node::operator  >(const Node& other) const
{
    if(value > other.value)
        return true;
    else
        return false;
}
long Node::get_value() const
{
    return value;
}

Node::~Node()
{
    destructor_count++;
}