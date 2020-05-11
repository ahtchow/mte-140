#ifndef DOLLARS_AND_CENTS // compiler directive that ensures that
#define DOLLARS_AND_CENTS // this file is compiled only once

//Purpose: Models CDN and USD currency

class DollarandCents { //Private Attributes
    int dollar;
    int cent;

public: //Start of public methods
    //CONSTRUCTORS
    DollarandCents();
    DollarandCents(int D , int C);

    //SERVICE FUNCTIONS
    void increment_value( int add_dollar, int add_cent);
    void increment_value( DollarandCents class1);
    void decrement_value( int sub_dollar, int sub_cent);
    void decrement_value ( DollarandCents class2);
    void output_value();

};

#endif // must include this to complete the compiler directive