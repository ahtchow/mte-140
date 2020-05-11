#include <iostream>

using namespace std;

// PURPOSE: Models a data item in a container
class Node{
	int data;
	Node* next;
	
public:
	// CONSTRUCTORS
	Node() : data(0), next(NULL) {}
	Node(int new_data) : data(new_data), next(NULL) {}
	
	// PURPOSE: Simple getters and setters
	Node* get_next() {
		return next;
	}		
	void set_next(Node* new_next) {
		next = new_next;
	}	
	int get_data() {
		return data;
	}	
	void set_data(int new_data) {
		data = new_data;
	}
};

// PURPOSE: Models a linked list container
class LinkedList{
	Node* first;
	int size;
	
public:
	// CONSTRUCTORS
	LinkedList() : first(NULL), size(0) {}

	// PURPOSE: Simple getters and setters	
	int get_size() {
		return size;
	}
	// PURPOSE: Inserts a data value at the end of the linked list
	bool push_back(int data);
	
	// PURPOSE: Removes the last item from a linked list
	bool pop_back();
	
	// PURPOSE: Prints linked list contents
	void print();
	
	// PURPOSE: Checks if a specified data value is in the list
	bool find(int value);
};

bool LinkedList::push_back(int data)  {	
	if (!first) { // base case: empty list
		first = new Node(data); // set first to 						
								// point to the new node
								// set next = NULL 
								// in the constructor

	} else { // general case: non-empty list
		Node* end = first; // init end ptr
		while (end->get_next()) // iterate until NULL
			end = end->get_next();
		end->set_next(new Node(data)); // insert at the end
									   // set next = NULL 
									   // in the constructor
	}

    ++size; // update size
    return true; // return true
}

bool LinkedList::pop_back() {
	if (!first) { // base case: empty list
		return false; // nothing to do
		
	} else if (!first->get_next()) { // base case: list with one node
		delete first;
		first = NULL;
				
	} else { // general case: a list with more than one node
		Node* end = first; // init end pointer
		while (end->get_next()->get_next()) // iterate until the second last node
			end = end->get_next();
		delete end->get_next(); // free memory for the last node
		end->set_next(NULL);	// set the second-last to point to NULL	 
	}
	
	--size; // update size
	return true; // return true
}

void LinkedList::print() {
	cout << "("; // print the header data
	Node* end = first; // initialize end pointer
	while (end) { // iterate until NULL
		cout << "[" << end->get_data() << "]"; // print node
		end = end->get_next();
		if (end) // print -> symbol between nodes
			cout << "->";
	}	
	cout << ")\n"; // print the footer data
}

bool LinkedList::find(int value) {	
	Node* end = first; // initialize end pointer
	while (end) { // iterate until NULL
		if (end->get_data() == value) // return true if the value is found
			return true;		
		end = end->get_next();
	}	
	return false; // return false if the value is not found
}

int main() {
	// driver code to test LinkedList and Node classes
	LinkedList list; // create a new list
	
	// test push_back() and print()
	list.push_back(5);
	list.push_back(7);
	list.push_back(3);
	list.push_back(1);
	list.push_back(14);
	list.print();
	cout << "The number of inserted nodes in the list: " << list.get_size() << endl;

	// test find()
	cout << "The value 11 is inside the list: " << (list.find(11) ? "Yes" : "No") << endl;
	cout << "The value 3 is inside the list: " << (list.find(3) ? "Yes" : "No") << endl;
	
	// test pop_back() and print()
	list.pop_back(); // delete the last node
	list.pop_back(); // delete the last node
	list.pop_back(); // delete the last node
	list.pop_back(); // delete the last node
	list.pop_back(); // delete the last node
	list.pop_back(); // delete the last node; try one extra
	list.print();
	cout << "The number of inserted nodes in the list: " << list.get_size() << endl;
	
	return 0;
}

