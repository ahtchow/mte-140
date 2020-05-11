#include <iostream>
#include <vector>

using namespace std;

/** Classes
 *  can be used inter changably with Structs
 *  members in structs are accessible by default -> Public
 *  members in classes are private and not directly accessibble by default -> Private
*/

/** STRUCTS vs CLASSES
 *  use classes as means of modeling conceptual and real-world entities
 *  structs will be availiable for modeling simple with no member functions
 *  syntax should be the same, except can not publicly access classes
 * */

/** CLASS
 *  a template for creating instances of a specific type with own data items and functions
 *  template for modeling real-world entities/ concepts
 * */

/** OBJECT
 *  A variable that has its own member variables/ attributes
 *  also has its own member functions/ methods
 *  Each object is an INSTANCE of a specific CLASS
 * */

/** Why are class members private?
 *  Information Hiding - user of a class should not depend on its internal structure
 *  Should only rely on class interface, i.e Publuc Functions
 * */

/**  CLASS CONSTRUCTOR
 *  special member function/ method
 *  used to allocate space & initialize class variables
 *  Constructor exists by default to take no parameters
 *  If an explicit constructor is declared it replaces default
 * */

/** HOW TO ACCESS PRIVATE CLASS ATTRIBUTES
 *  via public methods that provide specific service 
 *  ie. change value of member or print stuff , etc...
 *  member attributes can also be made availible via specific getter and setter functions
 *  However, unrestricted and direct access to member attributes may lead to problems
 * */

/** ACCESSORS and MUTATORS (Public Methods)
 *  Acessors -> ' Get Value '  (Getter)
 *  Mutators -> ' Set Value '   (Setter)
 * */

/** MORE ON CLASS CONSTRUCTORS
 * Default/empty constructor should also be provided if explocit constructor is declared
 * Implicit setters may be used to set attributes for parametric constructors
 * Fress up the constructor body to perform other functions
 * */

/** ABSTRACT DATA TYPE (ADT)
 *  collection of data items made up of:
 *  1. A name
 *  2. A purspose 
 *  3. Set of functions (interface) that operate on data items
 *  (Only inteface is exposed externally and data organization is hidden)
 * 
 *  ADTS are often language independant
 *  we will implement ADTs in C++ as classes
 *  Not every C++ class is ADT, specific constraints must be met
 * 
 * */

/** INFORMATION HIDING (Design Pricple)
 *  details of how data is stored and manipulated within class is unknown to users
 *  only class Interface is exposed
 * */

/** ADT Interface:
 *  Includes:
 *  - public member functions 
 *  - document on how to use functions
 * 
 * ADT Implementation:
 *  Represents the realization of the ADT interface
 *  Include private attributes and private and public methods within a class
 * 
 * Attributes in a class should almost always be designated as private
 *  - to uphold the information hiding principle
 *  - private attributes preserve internal object state
 *  - allows data change only via public methods
 * */

/** Constructors.. continued
 *  class constructor can be called again after object has been initialized
 * */

/** Destructor (~)
 * Deinitalizes the object that was initalized using constructor
 * Each class only has one destructor method
 * Invoked when object scope is closed to deallocate memory
 * E.g ~DollarsAndCents();
 * Happens automatically dont need to call
 * */

/** Copy Constructor
 * availible by default and used to copy objects
 * */

/** Member Attributes/Methods: 
 *  Classes can include other objects also arrays as member attributes
 *  Member methods can be declared insid ethe class anad then implemented elsewhere
 *  this allows the class to set the method signature and then allow implementation to be changed (e.g different platform)
 *  SYNTAX : <return-type> <class-identifier> ::<method-name> (<input-parameter>){<method-body>}
 * */

/** HOW TO DIFFERENTIATE CLASS DECLARATION AND CLASS DEFINITION
 *  As ADTs, classesare meant to provide interface for access to specific functionality
 *  How implementaion of functionality is seperate for declaration
 *  Classes can be seperated into class declarations (attributes & method declaration) 
 *  into .hpp or .h files and class definitions - cpp files (method definition)
 *  .cpp files will contain the actual class implementation and then #include .hpp file
 * */

class VIP {
    string firstname;
    string lastname;
    string DOB;

public:

    VIP() 
    {
        // Does nothing, except initalize - default constructor
    }

    VIP( string fname, string lname , string dateBirth)
    {
        firstname = fname; // Do not reinitialize
        lastname = lname;
        DOB = dateBirth;
        // Parametetric constructor
    }

    void printElements()
    {
        cout << firstname << endl;
        cout << lastname << endl;
        cout << DOB << endl;
    }

    //Accessors
    string get_firstname() 
    {
        return firstname;
    }
    string get_lastname()
    {
        return lastname;
    }

    string get_DOB()
    {
        return DOB;
    }
    //Mutators

    void change_lastname(string lname)
    {
        lastname = lname;
    }

    void change_firstname(string fname)
    {
        firstname = fname;
    }
    void change_DOB(string DoBirth)
    {
        DOB = DoBirth;
    }
};

class DollarandCents {
    int dollar;
    int cent;

public:
    DollarandCents()
    {
        dollar = 0;
        cent = 0;
    }

    DollarandCents(int D , int C) : dollar(D), cent(C) {} 
    //Implicit Setter Method

    void increment_value( int add_dollar, int add_cent){
        int new_cents_value = (dollar + add_dollar)*100 + (cent + add_cent);
        dollar = new_cents_value / 100;
        cent = new_cents_value % 100;
    }

    void increment_value( DollarandCents class1){
        increment_value(class1.dollar,class1.cent);
        // can access private attribute if passed in as a class method
    }

    void decrement_value( int sub_dollar, int sub_cent){
        increment_value( - sub_dollar , -sub_cent);
    }

    void decrement_value ( DollarandCents class2)
    {
        increment_value( - class2.dollar , - class2.cent);
    }

    void output_value(){
        cout << "$ " << dollar << "." << cent << endl;
    }

};
// Member Attributes/Methods

class Family{
    vector<string> members; //vector as attribute
    DollarandCents piggybank; // another object as member 
    string height[10]; // array as member
};

class House{
    Family Chow;

public: 
    bool is_really_awsome();

};

bool is_really_awsome(){
    if (42)
        return true;
    return false;
}

int main()
{
    /* 1. Privatization

    VIP p;
    p.firstname = "John";   // Will not compile since private member of VIP
    cout << p.firstname << endl;   
    */

    // 2. Constructors

    VIP vip1; // calls default constructor, not VIP vip1();
    VIP vip2( "Adrian", "Chow" , "04/24/2000"); // Parametric Constructor
    vip2.printElements();

    vip2.change_firstname("Haochen"); // Mutator
    string testFirstname = vip2.get_firstname(); // Accessor
    cout << testFirstname << endl;
    

    DollarandCents bank1(4, 175);
    DollarandCents bank2(6 , 75);
    DollarandCents bank3(5,0);

    bank1.increment_value( 0 , 0 );
    bank1.output_value();

    bank1.increment_value(bank2);
    bank1.output_value();
    bank1.decrement_value(bank3);
    bank1.output_value();

    //Class Constructor can be called again after object has been initalized
    DollarandCents bank4; // Default Constructor
    bank4 = DollarandCents(3,70); //Parametric Constructor
    bank4.output_value();

    /** How to declare an array of objects?
     *  syntax is same as for datatypes covered so far 
     *  can use <Vector> library if needed
     *  SYNTAX RULES :
     *  <class-identifier> <object-identifier>[<size>];  //Array
     *  vector<<class-identifier>><local-identifier>;    //Vector
     * */

    DollarandCents bank_array[3]; // declares an array of 5 objects
    bank_array[2].output_value(); // Should return default

    //Using ADT Interface
    bank_array[0] = DollarandCents(5, 75);
    bank_array[1] = DollarandCents(6, 75);
    bank_array[2] = DollarandCents(5, 0);

    bank_array[0].increment_value(bank_array[1]);
    bank_array[0].output_value();
    bank_array[0].decrement_value(bank_array[1]);
    bank_array[0].output_value();

    vector<DollarandCents> bank_vector;
    bank_vector.push_back(DollarandCents(5,75));
    bank_vector[0].output_value();
    bank_vector.push_back(DollarandCents(6,75));
    bank_vector[0].increment_value(bank_vector[1]);
    bank_vector[0].output_value();
    bank_vector.push_back(DollarandCents(5,0));
    bank_vector[0].decrement_value(bank_vector[2]);
    bank_vector[0].output_value();

    //3. Copy constructor
    DollarandCents copy_cheque(4,50);
    DollarandCents copy_cheque2(copy_cheque);
    copy_cheque2.output_value();



    return 0;


}