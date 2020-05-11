#include <iostream>
#include "dollars_and_cents.hpp" // must include

using namespace std; 

/* Class Declaration not required simply reference namespace in method definition

class DollarandCents {
    int dollar;
    int cent;
*/ 

DollarandCents:: DollarandCents()
{
    dollar = 0;
    cent = 0;
}

DollarandCents::DollarandCents(int D , int C) : dollar(D), cent(C) {} 
//Implicit Setter Method

void DollarandCents::increment_value( int add_dollar, int add_cent){
    int new_cents_value = (dollar + add_dollar)*100 + (cent + add_cent);
    dollar = new_cents_value / 100;
    cent = new_cents_value % 100;
}

void DollarandCents::increment_value( DollarandCents class1){
    increment_value(class1.dollar,class1.cent);
    // can access private attribute if passed in as a class method
}

void DollarandCents::decrement_value( int sub_dollar, int sub_cent){
    increment_value( - sub_dollar , -sub_cent);
}

void DollarandCents::decrement_value ( DollarandCents class2)
{
    increment_value( - class2.dollar , - class2.cent);
}

void DollarandCents::output_value(){
    cout << "$ " << dollar << "." << cent << endl;
}