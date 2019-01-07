#include "ShellSortSuboptimal.h"
https://www.geeksforgeeks.org/
ShellSortSuboptimal::ShellSortSuboptimal() : VectorSorter("Shellsort suboptimal") {}
ShellSortSuboptimal::~ShellSortSuboptimal()
{}
/***** Complete this file. *****/

void ShellSortSuboptimal::run_sort_algorithm() {
	/***** Complete this member function. *****/
	// Start with a big gap, then reduce the gap
	for (int gap = size / 2; gap > 0; gap /= 2) {
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted
		for (int i = gap; i < size; i += 1) {
			// add data[i] to the elements that have been gap sorted
			// save data[i] in temp and make a hole at position i
			Element temp = data[i];

			// shift earlier gap-sorted elements up until the correct
			// location for data[i] is found
			int j;
			for (j = i; j >= gap; j -= gap) {
				//compare_count++;
				if (data[j - gap] > temp) {
					data[j] = data[j - gap];
					//move_count++;
				} else
					break;
			}

			//  put temp (the original a[i]) in its correct location
			data[j] = temp;

		}
	}

}
