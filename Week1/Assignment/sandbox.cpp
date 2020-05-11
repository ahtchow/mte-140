
#include "LabAssignment1.hpp"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;



int main(){
    srand(time(0));

    // Polynomial Sd("test5.txt");
    // Sd.print();

    // int D[8] = {3,5,6,2,8,3,1,2};
    // int E[5] = {3,4,2,1,6};
    // int F[8] = {6,9,8,3,14,3,1,2};
    // Polynomial testD(D,8);
    // Polynomial testE(E,5);
    // Polynomial testF(F,8);
    // Polynomial answer2(testD + testE);
    // answer2.print();


    PolynomialTest test;
    test.run();

}
