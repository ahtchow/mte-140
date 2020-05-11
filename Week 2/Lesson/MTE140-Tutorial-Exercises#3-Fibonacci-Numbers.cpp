#include <iostream>
#include <chrono>

using namespace std;

// PURPOSE: Compares Fibonacci numbers implemented using
//          recursion, recursion with memoization, and dynamic programming
class FibonacciTester {
	// maximum fibonacci number that can be used for testing
	const int MAX_FIB_NUMBER = 1000;
	// selected test value
	const int TEST_VALUE = 42;
	// enumeration of different test cases
	enum class TEST_OPTION {REC, REC_WITH_MEMO, DP};
	
	// distinct cache storage for memoization and dynamic programming
	int* fib_cache_memo;
	int* fib_cache_dp;

public:	
	// CONSTRUCTOR
	FibonacciTester() {
		fib_cache_memo = new int[MAX_FIB_NUMBER + 1]();
		fib_cache_dp = new int[MAX_FIB_NUMBER + 1]();
	}
	
	// DESTRUCTOR	
	~FibonacciTester() {
		delete [] fib_cache_memo;
		delete [] fib_cache_dp;	
	}
	
	// PURPOSE: Recursive implementation of Fibonacci numbers
	int fib_rec(int n) {
		if (n <= 0 || n > MAX_FIB_NUMBER) 
			return 0;
		else if (n == 1)
			return 1;
		else 
			return fib_rec(n - 1) + fib_rec(n - 2);
	}
	
	// PURPOSE: Recursive implementation with memoization of Fibonacci numbers
	int fib_memo(int n, int* fib_cache) {
		if (n <= 0 || n > MAX_FIB_NUMBER) 
			return 0;
		else if (n == 1)
			return 1;
		else if (fib_cache[n] > 0)
			return fib_cache[n];
		else 
			return fib_cache[n] = fib_memo(n - 1, fib_cache) + fib_memo(n - 2, fib_cache);
	}
	
	// PURPOSE: Dynamic programming implementation of Fibonacci numbers	
	int fib_dp(int n, int* fib_cache) {
		if (n <= 0 || n > MAX_FIB_NUMBER) 
			return 0;
		else if (n == 1)
			return 1;
		else {
			fib_cache[1] = 1;
			for (int index = 2; index <= n; ++index) {
				if (!fib_cache[index])
					fib_cache[index] = fib_cache[index - 1] + fib_cache[index - 2];
			}
			return fib_cache[n];
		}
	}
	
	// PURPOSE: Runs and times the selected Fibonacci function	
	void test_fib_impl(TEST_OPTION test_option) {	
		auto start_time = chrono::steady_clock::now();		
		switch(test_option) {
			case TEST_OPTION::REC:
				cout << fib_rec(TEST_VALUE) << endl;
				break;
			case TEST_OPTION::REC_WITH_MEMO:
				cout << fib_memo(TEST_VALUE, fib_cache_memo) << endl;
				break;
			case TEST_OPTION::DP:
				cout << fib_dp(TEST_VALUE, fib_cache_dp) << endl;
				break;				
		}
		auto end_time = chrono::steady_clock::now();
		cout << chrono::duration_cast<chrono::microseconds>
				(end_time - start_time).count() << " microseconds" << endl;
	}
	
	// PURPOSE: Runs all three tests
	void run_tests() {
		test_fib_impl(TEST_OPTION::REC);
		test_fib_impl(TEST_OPTION::REC_WITH_MEMO);
		test_fib_impl(TEST_OPTION::DP);		
	}
};

int main() {
	// test driver
	FibonacciTester ft;
	ft.run_tests();
}
