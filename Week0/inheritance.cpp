#include <iostream>

using namespace std;

/** INHERITANCE
* another capability of C++ classes where the design can be structured int a hierachy
 *  The base class can be defined (e.g Person)
 *  then specialized versions can be created that inherit properties of the base (e.g Student)
 *  The "specialized class" inherit all of the properities of the base, which can be further derived
 *  e.g class Person{...};
 *      class Student : public Person { ... }
 *      // Public members of Person are public in student 
 *      class Undergraduate : public Student {...}
 * 
 *  The derived class includes a copy of the base class as part of its structure
 *  To create an instance of derived class:
 *      -  implicitly or explicitly call one of the base class constructors
*/

/** Public, Private & Protected Visibility:
 *  Everything that is PUBLIC inside base class is accessible to derived class
 *  Everything that is PROTECTED inside the base is directly accessible within the derived classes
 *  Everything that is PRIVATE inside base class is NOT accessible to derived class
 *  
 *  Base class methods that need to be accessed by derived class must be public or protected
 *  only class-specific helper methods should be declared as private 
 *  private member attributes can be accesse directly via constructors or getters/setters
  
 * */

/** Method Redefining:
 *  The same method from the base class can be redefined inside dervied classes
 *  the base class method can still be invoked using the "<base-type>::<method>" syntax  
 * */

/** ABSTRACT CLASS
 *  special type of a class that represents base behaviour for a class hierachy
 *  contains at least one pure virtual method, such as "virtual void print() = 0;"
 *  Due to the pure virtual method, it cannot be instantiated but can be derived
 *  Its derived classes must implement all pure virtual methods or they will remain abstract
 *  Abstract classes are used when defining behaviour shared among derived classes but the base class is not used on its own
 *  
 *  E.g Pet
 *      /  \
 *   Dog    Cat
 *   /
 * BorderCollie
 * 
 * **/

/** Virtual Methods
 * As inheritance hierachy grows new derived classes may be added iteratively
 * Previously methods still need to keep functioning
 * E.g Derived dog class can be extended with BordieCollie class
 * 
 * POLYMORPHISM (Many Shapes)
 * At runtime the function will decide what is the exact object type
 * then invoke corresponding virtual function for that object
 * 
 * */

/**  UPCASTING/DOWNCASTING
 *  Is every bordercollie a dog? Yes
 *  Is every dog a bordercollie? No
 *  UPCASTING : Treat a derived class as an instance of a base class, VALID
 *  DOWNCASTING : Treat a base class as an instance of a derived class, TYPICALLY INVALID
 *  i.e a DOG class pointer pointing to a BorderCollie : VALID
 *  i.e a BORDERCOLLIR pointer pointing to a DOG : INVALID
 * */

/** DELEGATION vs INHERITANCE SUMMARY
 *  Delegation: Class A uses an instance of Class B to perform specific function 
 *  (i.e Library uses Book to store Book Info)
 *  Inheritance: Class A extends Class B and gains access to entire B's interface
 *  (i.e Libray extends Book, can store Book info, but can also add other functions)
 *  
 *  Replace Delegation with Inheritance:
 *  If the user class needs acces to most or all of the delegate functionality
 *  
 *  Replace Inheritance with Delegation 
 *  If the derived class relies only on a subset of the base class functionality.
 * 
 * */

class Person{

    string firstname , lastname , DOB;

public:

    Person() {} // Empty Constructor for Later
    Person(string new_fname, string new_lname, string new_dob): 
        firstname(new_fname), 
        lastname(new_lname), 
        DOB(new_dob) {}

    void print()  {
        cout << firstname << endl;
        cout << lastname << endl;
        cout << DOB << endl;
    } 

};

class Student : public Person { // Creating an instance
    string studentID, faculty, major;
public:
    Student () {} //Implicitly calls Person's empty constructor
    Student(Person person1, string new_ID, string new_faculty, string new_major): Person(person1) , studentID(new_ID), faculty(new_faculty), major(new_major){}
    // Explicit call
    void print(){
        Person:: print();
        cout << studentID << endl;
        cout << faculty << endl;
        cout << major << endl;
    }
};
//4.

/**
 * Virtual functions cannot be static and also cannot be a friend function of another class.
 * Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
 * The prototype of virtual functions should be same in base as well as derived class.
 * They are always defined in base class and overridden in derived class. It is not mandatory for derived class to override (or re-define the virtual function), in that case base class version of function is used.
 * */

class Pet {
    string name;
public:
    Pet(string new_name) : name(new_name) {}
    
    string getName() {
        return name;
    }
    virtual void print() = 0; // pure virtual method - for base class

};

class Dog: public Pet { // inherits abstrt class

public:
    Dog(string new_name) : Pet(new_name) {} // Constructor based on abstract class

    virtual void print(){
        cout << "My dog's name is" << getName() << endl;
    }
    
};

class Cat: public Pet { //inherits the abstract class

public:
    Cat(string new_name): Pet(new_name) {}

    virtual void print(){
        cout << "My cat's name is " << getName() << endl; // Must be different
    }
};

class BorderCollie : public Dog {
public:
    BorderCollie(string new_name): Dog(new_name){}
    
    virtual void print(){
        cout << "My dog's name is " << getName() << endl;
    }


};

void getDogInfo(Dog& d){
    d.print(); 
}

// POINTERS AND VIRTUAL FUNCTIONS

class Phone {
    string name;

public:
    Phone(string new_name) : name(new_name) {}

    string getName()
    {
        return name;
    }

    virtual void print(){
        cout << name << endl;
    }
};

class Smartphone : public Phone {

public:
    Smartphone(string new_name) : Phone(new_name){}

    void print() {
        cout << "SmartPhone is " << getName() << endl;
    }

};

int main()
{
    Person pers1("Adrian", "Chow", "04/24/2000");
    Student stud1(pers1, "12345678","Engineering", "Mechanical"); // Must pass person1 in as well
    stud1.print();
    stud1.Person::print();
    

    //4. Inhertiance - Abstract Class
    Dog boss("Boss");
    getDogInfo(boss);
    BorderCollie karen("Karen");
    getDogInfo(karen);

    //5. Pointers and Virtual Functions
    Phone* p = new Smartphone("iPhone XS"); // Pointer can point to an derived class
    p->print();
    
    Phone* p2 = new Phone("iPhone XS");
    p2->print();

    // Cant Downcast
    // Smartphone* p3 = new Phone("iPhoneXS") // can not make a pointer to point at base class

     return 0;


}
