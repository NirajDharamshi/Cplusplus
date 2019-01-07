#include <string>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

void vector_prepends(SortedVector& sv, const int size)
{
    /***** Complete this function. *****/
    for(int i = size;i>0;i--){
        sv.prepend(i);
    }
}

void list_prepends(SortedList& sl, const int size)
{
    /***** Complete this function. *****/
    for(int i = size;i>0;i--)
        sl.prepend(i);

}

void vector_appends(SortedVector& sv, const int size)
{
    /***** Complete this function. *****/
    for(int i = 0;i<size;i++)
        sv.append(i);
}

void list_appends(SortedList& sl, const int size)
{
    /***** Complete this function. *****/
    for(int i = 0;i<size;i++)
        sl.append(i);
}

void vector_gets(SortedVector& sv, const int size) throw (string)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()% size;
        long value = sv.at(index).get_value();

        /***** Complete this function. *****/

        // Make sure we got the correct node.
        if (index != value) throw string("Vector data mismatch!");
    }
}

void list_gets(SortedList& sl, const int size) throw (string)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()%size ;
        long value = sl.at(index).get_value();
        // long value = sl.at(i);

        /***** Complete this function. *****/

        // Make sure we got the correct node.
        if (index != value) throw string("List data mismatch!");
    }
}

void vector_removes(SortedVector& sv, const int size)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to remove a node at a random position
    // one at a time until the nodes are all gone.
    while (sv.size() > 0)
    {
        int index = rand()%sv.size();
        sv.remove(index);

        /***** Complete this function. *****/
    }
}

void list_removes(SortedList& sl, const int size)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    while (sl.size() > 0)
    {
        int index = rand()%sl.size();
        sl.remove(index);

    }
}

void vector_inserts(SortedVector& sv, const int size)
{
    while(sv.size()< size)
    {
        long int temp = rand();
        sv.insert(temp);
    }
}

void list_inserts(SortedList& sl, const int size)
{
    while(sl.size()< size)
    {
        long int  temp = rand();
        sl.insert(temp);
    }
}
void vector_reverse(SortedVector& sv, const int size)
{
   
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();
    
  //  Node *ptr=sv.j();
 vector<Node> x = sv.j();
    /***** Complete this function. *****/
   int i=1; 
 vector<Node>::iterator it=x.begin();
 it++;
 
 while(i<size)
 {
    int v = sv.at(i).get_value();
    sv.prepend(v);
    it++;
    sv.remove(i);
    i++;
    
 }
    
  /* if (!sv.check_reversed()) throw("Vector reverse sort error!");*/
}
void list_reverse(SortedList& sl, const int size)
{
     // First fill the list data.
    list_appends(sl, size);
    Node::reset();
 list<Node> x = sl.j();
    /***** Complete this function. *****/
       int i=1; 
 list<Node>::iterator it=x.begin();
 it++;
 
 while(i<size)
 {
    int v = sl.at(i).get_value();
    sl.prepend(v);
    it++;
    sl.remove(i);
    i++;
    
 }
    
  
}