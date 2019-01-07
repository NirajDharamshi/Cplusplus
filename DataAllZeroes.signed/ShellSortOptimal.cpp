#include "ShellSortOptimal.h"

https://www.geeksforgeeks.org/

ShellSortOptimal::ShellSortOptimal() :VectorSorter("Shellsort optimal") {}

/***** Complete this file. *****/
ShellSortOptimal::~ShellSortOptimal()
{}
void ShellSortOptimal::run_sort_algorithm() {
	/***** Complete this member function. *****/
	int interval = 0;
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0) {
		for (int i = interval; i < size; i++) {
			Element temp = data[i];
			int j;
			for (j = i; j >= interval; j -= interval) {
				//compare_count++;
				if (data[j - interval] > temp) {
					data[j] = data[j - interval];
				//	move_count++;
				} else
					break;
			}
			data[j] = temp;

		}

		interval = (interval - 1) / 3;
	}

}
