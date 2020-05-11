#include <iostream>

using namespace std;

class Person {
	string first_name, last_name, dob;
	int how_much_i_like_cake;
public:
	Person() : how_much_i_like_cake(100) {} // default empty constructor
	// string is an object, so not required to explicitly initalize
	// strings are implicitly initialized as "" via their default constructor
	
	Person(string new_fname, string new_lname, string new_dob) : // parametric constructor
		first_name(new_fname), last_name(new_lname), dob(new_dob),
		how_much_i_like_cake(100) {} // initialization list; using implicit setters	
		
	void print() {
		cout << first_name << " " << last_name << ", " << dob << ", " 
			<< how_much_i_like_cake << endl;
	}
};

int main() {
	Person p("Igor", "Smith", "Jun 15th 1983");
	Person x; // invokes base/empty constructor
	Person q = p; // operator=; shallow copy: copies objects and primitive values
	Person z(p);  // copy constructor; also, shallow copy
	z.print();
}

