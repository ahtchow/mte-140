#ifndef LABASSIGNMENT1_H
#define LABASSIGNMENT1_H

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime> 
#include <string>

using namespace std;

/**
 * @brief class that will store coefficients of a polynomail expersiion in an array.
 * @param data, array storing coefficients of the polynomaial
 * */

class Polynomial{

    int* data;
    int data_size;
    friend class PolynomialTest;

public:

    /**
     * @brief Class Constructor - Takes no inputs and generates random polynomial w/ random size
     * Creates amtching Polynomial instance
     * random data_size - 0 to 1000
     * coefficient range -1000 to 1000
     * 
     * */

    Polynomial();

    /**
     * @brief Class Constructor - Poopulates member variables with existing data
     * @param - int A[], array of coefficients
     * @param - int size, number of coefficients (n-1 polynomial)
     * */

    Polynomial(int A[], int size);

    /**
     * @brief Class Constructor - Poopulates member variables using file with data
     * @param - fileName, file 
     * */

    Polynomial(string fileName);
    
    /**
     * @brief Copy Constructor 
     * @param - Polynomial
     * */

    Polynomial(const Polynomial& target);


    /**
     * @brief Class Destructor, deallocates memory for data member variable
     * */

    ~Polynomial();

    /**
     * @brief Equality Operator
     * @returns true if equal
     * */

    void operator=(const Polynomial& target); 

    /**
     * @brief Equality Operator
     * @returns true if equal
     * */

    bool operator==(const Polynomial& target); 

    /**
     * @brief Print function - print polynomials
     * */

    void print();

    /**
     * @brief Adding Operator
     * @returns Sum of two Polynomial
     * */

    Polynomial operator+(const Polynomial& target); 

    /**
     * @brief Subtracting Operator
     * @returns Difference of two Polynomial
     * */

    Polynomial operator-(const Polynomial& target); 
    
    /**
     * @brief Multiplying Operator
     * @returns Difference of two Polynomial
     * */

    Polynomial operator*(const Polynomial& target); 

    /**
     * @brief Calculates derivative of polynomial
     * @return Polynomial 
     */
    
    Polynomial derivative();

};

class PolynomialTest{

public:

    bool testDefaultConstructor();

    bool testParametricConstructor();

    bool testReadFileConstructor();

    bool testCopyConstructor();

    bool testOperatorMakeEqual();

    bool testOperatorEquality();

    bool testPrint();

    bool testOperatorAdd();

    bool testOperatorSubtract();

    bool testOperatorMultiply();

    bool testOperatorDeriver();

    void run();

};


#endif 