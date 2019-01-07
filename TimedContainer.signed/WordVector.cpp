#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;

WordVector::WordVector() {}

WordVector::~WordVector() {}

int WordVector::get_count(const string text) const
{
    int index = find(text, 0, data.size()-1);
    return index >= 0 ? data[index].get_count() : -1;
}

void WordVector::insert(const string text)
{


// Start the timer.
	steady_clock::time_point start_time = steady_clock::now();

	// First insertion?
	if (data.size() == 0)
	{
		data.push_back(Word(text));
	}

	// Insert a new word or increment the count of an existing word.
	else
	{
		// Look for the word in the vector.
		int index = find(text, 0, data.size()-1);

		// Not already in the vector: Scan the vector to insert the new word
		// at the appropriate position to keep the vector sorted.
		if (index < 0)
		{
			vector<Word>::iterator it = data.begin();
			while ((it != data.end()) && (text > it->get_text())) it++;
			it = data.insert(it, Word(text));
		}

		// Already in the vector: Increment the word's count.
		else
		{
			data[index].increment_count();
		}
	}

	// Compute the elapsed time in microseconds
	// and increment the total elapsed time.
	steady_clock::time_point end_time = steady_clock::now();

	increment_elapsed_time( start_time, end_time);



}




vector<Word>::iterator WordVector::search(const string text)
{

    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the vector.
    int index = find(text, 0, data.size()-1);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time( start_time, end_time);

	// Return the iterator.
	return index >= 0 ? data.begin() + index : data.end();
}




Word &WordVector::operator [] (int index)
{
	return data[index];
}

int WordVector::find(const string text, int low, int high) const
{
    while (low <= high) {
        int mid = (low + high)/2;

        if (text == data[mid].get_text()) {
            return mid;
        }
        else if (text < data[mid].get_text()) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    return -1;
}

int WordVector::size() const
{
 return data.size();
}