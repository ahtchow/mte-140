//
// Created by Adrian Chow on 2020-01-08.
//

#include "structs.h"
#include <iostream>

using namespace std;


/** Structures (STRUCTS) - used to group related sdata items under appr. name
 *  Instead of declaring or redeclaring data items, hold them all at once
 *  Creates Data Items
*/

/** HOW DO WE USE STRUCTS
 * precursor to classes 
 * member variables are accessed with dot (.) operator
 * Declaration Syntax: struct <Struct Name> {...};
 * Initialization Syntax: <Struct Name> <Struct_Identifier>
 * Usage: <Struct_Identifier>.<Struct_Member_Name>
 * Assignment <strut_identifier1> = <struct_identifier2>;
*/


struct Person{
    string firstname; //Public memeber variable
    string lastname;  //Public memeber variable
    string DoBirth;   //Public memeber variable
};

/**  FUNCTIONS
 * structs can be created inside functions and returned as function arguments
 *both pass by value and pass by reference are availible as methods of access
*/

Person initialize_person(string Firstname, string Lastname , string doBirth) {
    Person new_person;
    new_person.firstname = Firstname;
    new_person.lastname = Lastname;
    new_person.DoBirth = doBirth;
    return new_person; // pass back by value
}

/**  FUNCTIONS
 * structs can also be used as function parameters
 *
*/

struct Date{
    int day, month, year;
};

void print_date( const Date& new_date) {
    cout << "Day: " << new_date.day << endl;
    cout << "Month: " << new_date.month << endl;
    cout << "Year: " << new_date.year << endl;

}



int main()
{
    Person Adrian;
    Adrian.firstname = "Adrian";
    Adrian.lastname = "Chow";
    Adrian.DoBirth = "04/24/2000";

    cout << Adrian.firstname << endl;
    cout << Adrian.lastname << endl;
    cout << Adrian.DoBirth << endl;

    Person Karen = initialize_person("1","2","3");
    
    cout << Karen.firstname << endl;
    cout << Karen.lastname << endl;
    cout << Karen.DoBirth << endl;

    Date d;
    d.day = 6;
    d.month = 11;
    d.year = 2018;
    print_date(d);

    return 0;
}