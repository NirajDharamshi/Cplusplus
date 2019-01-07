#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
    Node n(value);
    data.push_front(n);
}

void SortedList::append(const long value)
{
    Node n(value);
    data.push_back(n);
}

void SortedList::remove(const int index)
{
    list<Node>::iterator it = data.begin();
    for(int i = 0;i < index;i++)
        it++;
    data.erase(it);
}

void SortedList::insert(const long value)
{
    list<Node>::iterator it = data.begin();
    while((it != data.end()) && (it->get_value()< value))
    {
        it++;
    }
    Node node(value);
    data.insert(it,node);
}

 list<Node> SortedList::j()
 {
    return data;
 }

Node SortedList::at(const int index)
{
    list<Node>::iterator it = data.begin();
    for(int i=0;i<index;i++)
        it++;
    return *it;
}

/*bool SortedList::check_reversed() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = data.begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != data.end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}*/