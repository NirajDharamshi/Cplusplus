#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"

using namespace std;
using namespace std::chrono;

WordMap::WordMap() {}

WordMap::~WordMap() {}

int WordMap::get_count(const string text) const
{


    map<string, Word>::const_iterator it = data.find(text);
    if(it != data.end())
     return (it->second).get_count();
     else
     return false;
}


void WordMap::insert(const string text)
{

    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the map.
    map<string, Word>::iterator it = data.find(text);

    // Not already in the map: Enter the new word.
    if (it == data.end())
    {
        data[text] = Word(text);
    }

    // Already in the map: Increment the word's count.
    else
    {
        (it->second).increment_count();
    }

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();

    increment_elapsed_time( start_time, end_time);



}



map<string, Word>::iterator WordMap::search(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the map.
    map<string, Word>::iterator it = data.find(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();

	increment_elapsed_time( start_time, end_time);

	return it;

}

int WordMap::size() const
{
	return data.size();
}
