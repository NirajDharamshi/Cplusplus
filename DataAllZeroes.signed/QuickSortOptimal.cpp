#include "QuickSortOptimal.h"

https://www.geeksforgeeks.org/

QuickSortOptimal::QuickSortOptimal() : QuickSorter("Quicksort optimal") {}
QuickSortOptimal::~QuickSortOptimal()
{}
/***** Complete this file. *****/
Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    /***** Complete this member function. *****/
	int middle=(left+right)/2;
		if((data[left].get_value()<=data[middle].get_value() && data[middle].get_value()<=data[right].get_value()) || (data[right].get_value()<=data[middle].get_value() && data[middle].get_value()<=data[left].get_value()))
		{
			//compare_count+=4;
			swap(middle,left);
		}
		else if((data[left].get_value()<=data[right].get_value() && data[right].get_value()<=data[middle].get_value()) || (data[middle].get_value()<=data[right].get_value() && data[right].get_value()<=data[left].get_value())){
			//compare_count+=4;
			swap(right,left);
		}


		return data[left];
}

