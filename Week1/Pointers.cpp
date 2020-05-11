#include <iostream>
using namespace std;

int main()
{

int i = 5;
int* i_ptr = &i; //stack pointer example
// delete i_ptr; 

//deleting stack ptr is not allowed and also not needed.

/**
 * NEW OPERATOR
 *  Dynamically aloocates space and creates variable
 **/

cout << "Initializing i_ptr2" << endl;
int* i_ptr2 = new int(10); // heap pointer example
cout << "The value of *i_ptr2 is: " << *i_ptr2 << endl;
cout <<  "The value of i_ptr2 is: " << i_ptr2 << endl;
// *i_ptr2 stores the value located at the address
// i_ptr2 stores the location in dynamic memory

/**
 * DELETE OPERATOR
 *  frees up dynamic memory
 *  returns it to free memory.
 **/

cout<< "Deleting i_ptr2 \n";
delete i_ptr2; // deleting heap pointer, returns it to free memory
cout<< "*i_ptr2 value is: " << *i_ptr2 << " \n";
cout<< "i_ptr2 value is: " << i_ptr2 << " \n\n";


/**
 * DANGLING POINTER
 *  freed up dynamic memory, but ptr still points to location
 *  must set pointer to NULL (ptr = NULL) 
 **/


cout << "Setting i_ptr2 to NULL to remove as dangling pointer" << endl;
i_ptr2 = NULL; // ensuring that there is no dangling pointer
cout<< "i_ptr2 value is:" << i_ptr2 << " \n";

}