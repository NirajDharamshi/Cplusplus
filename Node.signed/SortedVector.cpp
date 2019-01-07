#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    Node n(value);
    data.insert(data.begin(),n);
}

void SortedVector::append(const long value)
{
    Node n(value);
    data.push_back(n);
}

void SortedVector::remove(const int index)
{
    data.erase(data.begin()+index);
}

void SortedVector::insert(const long value)
{
    vector<Node>::iterator it = data.begin();
    while((it != data.end()) && (it->get_value()< value))
    {
        it++;
    }
    Node node(value);
    data.insert(it,node);

}
 vector<Node> SortedVector::j()
 {
    return data;
 }

Node SortedVector::at(const int index) const
{
    return data.at(index);
}

/*bool SortedVector::check_reversed() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}*/
