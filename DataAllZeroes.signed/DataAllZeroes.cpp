#include "DataAllZeros.h"

DataAllZeros::DataAllZeros() : DataGenerator("All zeroes") {}

DataAllZeros::~DataAllZeros(){
   
}

/***** Complete this file. *****/

void DataAllZeros::generate_data(vector<Element>& data, const int size)
{
   for(int i=0;i<size;i++)
   {
      data.push_back(0);
   }
}
