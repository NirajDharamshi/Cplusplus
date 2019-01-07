#include <string>
#include <vector>
#include "DataGenerator.h"

/***** Complete this file. *****/
DataGenerator::DataGenerator(string name)
{
   name=name;
}

DataGenerator::~DataGenerator()
{
   
}

string DataGenerator::get_name()
{
   return name;
}

void DataGenerator::generate_data(vector<Element>& data, const int size)
{
   
}
