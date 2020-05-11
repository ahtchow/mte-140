#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// TODO: Implement the Selection Sort algorithm from Lecture Notes #1

// By completing this code exercise on your own, you should be able to:
// (1) Implement the selection sort algorithm
// (2) Pass vectors by reference into functions
// (3) Use functions as parameter values in software design

// PURPOSE: Swap two elements in a vector that is passed by reference
void swap_vector_data(vector<int>& data, unsigned int val1, unsigned int val2) {
	int temp = data[val1];
	data[val1] = data[val2];
	data[val2] = temp;		
}

// PURPOSE: Sort the given vector of integers based on specified order
//     INPUTS: data - vector reference that contains unsorted elements
//             compare - function comparator that specifies sorting order
void selection_sort(vector<int>& data, function<bool(int,int)> compare) {
	// iterate from first to second-last element
	for (unsigned int current = 0; current < data.size() - 1; ++current) {
		// store current index as temporary extreme value
		unsigned int extreme_index = current;
		// iterate from the current to last element
		for (unsigned int index = current; index < data.size(); ++index) {
			// update extreme_index if new local extreme value is found
			if (compare(data[extreme_index], data[index])) 
				extreme_index = index;
		}
		// swap the current and extreme_index values if needed
		if (current != extreme_index)
			swap_vector_data(data, current, extreme_index);
	}
}

// PURPOSE: Comparator for ascending sort order
bool compare_asc(int val1, int val2) {
	// if true, the values are not in order
	return val1 > val2; 
}

// PURPOSE: Comparator for descending sort order
bool compare_desc(int val1, int val2) {
	// if true, the values are not in order
	return val1 < val2;
}

// PURPOSE: Run sanity tests for selection_sort()
void test_selection_sort() {
	// initialize vector data
	vector<int> data;
	data.push_back(42);
	data.push_back(3);
	data.push_back(4);
	data.push_back(15);
	data.push_back(2);
	data.push_back(7);

	// run the selection sort ascending
	selection_sort(data, compare_asc);

	// print results for verification	
	cout << "Selection Sort Test: Ascending Order" << endl;
	for (auto element : data) {
		cout << element << endl;
	}	
	
	// run the selection sort descending
	selection_sort(data, compare_desc);

	// print results for verification	
	cout << endl << endl << "Selection Sort Test: Descending Order" << endl;
	for (auto element : data) {
		cout << element << endl;
	}	
}

int main() {
	test_selection_sort();

	return 0;
}
