#include <stdlib.h>
#include <time.h>
#include "DataRandom.h"
#include "Element.h"

DataRandom::DataRandom() : DataGenerator("Unsorted random") {}

DataRandom::~DataRandom()
{
   
}

/***** Complete this file. *****/

void DataRandom::generate_data(vector<Element>& data, const int size)
{
    srand (time(NULL));
    long i=0;
    for(int j=0;j<size;j++)
    {
      i = rand();
      data.push_back(i);
    }
}
