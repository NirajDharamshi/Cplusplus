#include "DataSorted.h"

DataSorted::DataSorted() : DataGenerator("Already sorted") {}

DataSorted::~DataSorted()
{
   
}

/***** Complete this file. *****/
void DataSorted::generate_data(vector<Element>& data, const int size)
{
    Element temp;
int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
          if (data[j] < data[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
       
        temp=data[min_idx];
        data[min_idx]=data[i];
        data[i]=temp;
    }
   
}
