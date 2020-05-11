#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

enum class TEST_OPTION {SEL_SORT, BUBBLE_SORT, ALGO_SORT};
const int TEST_RANGE = 10000;

// PURPOSE: Swaps two integer values using extra memory space
void swap(int& target1, int& target2) {
	int temp = target1;
	target1 = target2;
	target2 = temp;	
}

// PURPOSE: Implements a version of bubble sort
void bubble_sort(vector<int>& data) {
	bool swapped = true;

	for (int index = 0; index < data.size() && swapped; ++index) {
		swapped = false;
		
		for (int index2 = 0; index2 < data.size() - 1 - index; ++index2 ) {
			// comparison and swapping inside the loop; lots of swapping
			if (data[index2] > data[index2 + 1]) {
				swap(data[index2], data[index2 + 1]);
				swapped = true;
			}
		}
	}
}

// PURPOSE: Implements a version of selection sort
void selection_sort(vector<int>& data) {
	int min_index = 0;
	
	for (int index = 0; index < data.size(); ++index) {
		min_index = index;

		for (int index2 = index + 1; index2 < data.size(); ++index2) {
			// only compare inside the loop
			if (data[index2] < data[min_index])
				min_index = index2;
		}

		// swap if there was a change
		if (min_index != index)		
			swap(data[min_index], data[index]);
	}
}

// PURPOSE: Runs and times the selected sorting function
void test_sorting(vector<int> data, TEST_OPTION test_option, bool print_results) {	
	auto start_time = chrono::steady_clock::now();		
	switch(test_option) {
		case TEST_OPTION::SEL_SORT:
			selection_sort(data);
			break;

		case TEST_OPTION::BUBBLE_SORT:
			bubble_sort(data);
			break;
			
		case TEST_OPTION::ALGO_SORT:
			sort(data.begin(), data.end());
			break;
	}
	auto end_time = chrono::steady_clock::now();

	cout << chrono::duration_cast<chrono::microseconds>
			(end_time - start_time).count() << " microseconds" << endl;
	
	if (print_results) { // print results for verifcation
		for (int element : data) 
			cout << element << endl;
	}
}

void run_tests() {
	srand(time(0)); // set randomization seed
	vector<int> test; // create the test vector
		
	for (int index = 0; index < TEST_RANGE; ++index) // generate test vector
		test.push_back(rand() % TEST_RANGE);

	cout << "TESTING BUBBLE SORT" << endl;
	test_sorting(test, TEST_OPTION::BUBBLE_SORT, false);

	cout << "\nTESTING SELECTION SORT" << endl;
	test_sorting(test, TEST_OPTION::SEL_SORT, false);

	cout << "\nTESTING std::sort" << endl;
	test_sorting(test, TEST_OPTION::ALGO_SORT, false);
}

int main() {
	run_tests();
	
	return 0;
}

