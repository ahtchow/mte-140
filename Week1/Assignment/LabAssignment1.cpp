#include "LabAssignment1.hpp"

Polynomial::Polynomial() {
    data_size = (rand() % 1001) + 1;  // Polynomial size is (data_size - 1) polynomial 
    data = new int[data_size];
    for(int i = 0; i < data_size; i++){
        data[i] = (rand() % 2001) - 1000; 
    }
}

Polynomial::Polynomial (int A[], int size){
    if(size <= 0 || A == NULL){
    cout << "Error: Can not construct, returned NULL/ SIZE 0" << endl;
    data_size = 0;
    data = NULL;
    }

    else{
        data = new int[size];
        data_size = size;
        for( int i = 0; i < size; i ++){
            data[i] = A[i];
        }
    }
}

Polynomial::Polynomial(string fileName){
    ifstream file(fileName);
    int errorCheck;
    int count = 0;
    string line;
    bool Read = false;

    while(file.is_open()){
        for(string line; getline(file,line);){
            // If first line read into data_size / Do not allow negative numberss
            if(count == 0){
                errorCheck = stoi(line);
                int negativeString = line.length();
                Read = true;
                if(errorCheck <= 0 || negativeString == errorCheck + 1){ 
                    data = NULL;
                    data_size = 0;
                    cout<< "Error: Can not have negative degree polynomial, returned NULL/ SIZE 0" << endl;
                    break;
                }
                else{
                    data_size = errorCheck;
                    data_size ++;
                    data = new int[data_size];
                    count++;
                }
            }
            // If empty set index as 0 , else read number into the array
            else if (data_size - count >= 0){
                line.empty() ? data[data_size - count] = 0 : data[data_size - count] = stoi(line);
                count ++;
            }
        }
        break;
    }

    if(!Read){
        cout<< "Error: File can not be read" << endl;
        data = NULL;
        data_size = 0;
    }

}

Polynomial::Polynomial(const Polynomial& target){ 
    //Copy Constructor
    data = new int[target.data_size];
    data_size = target.data_size;
    for(int i = 0; i < data_size; i++){
        data[i] = target.data[i];
    }
}

Polynomial::~Polynomial(){
    delete [] data;
    data = NULL;
    data_size = 0;
}

void Polynomial::operator=(const Polynomial& target){
    delete[] data;
    if(target.data_size <= 0 || target.data == NULL){
        data_size = 0;
        data = NULL;
    }
    else{
        data_size = target.data_size;
        data = new int[data_size];
        for(int i = 0; i < data_size; i++){
            data[i] = target.data[i];
        }
    }
} 

bool Polynomial::operator==(const Polynomial& target){
    if((data == NULL && target.data == NULL) && (data_size == target.data_size)){
        return true;
    }

    // Consider Zero Polynomials with different Sizes
    else if((data_size != target.data_size) || 
        (data == NULL && target.data != NULL) ||
        (data != NULL && target.data == NULL))
    {
        bool AllZeros = false;

        for(int i = 0; i < data_size; i++){
            if(data[i] != 0){
                cout << "Error: data = Null or data_size != input.data_size" << endl;
                return AllZeros;
            }
        }

        for(int j = 0; j < target.data_size; j++){
            if(target.data[j] != 0){
                cout << "Error: data = Null or data_size != input.data_size" << endl;
                return AllZeros;
            }
        }     
        AllZeros = true;   
        return AllZeros;
    }

    for(int i=0; i< target.data_size; i++){
        if(data[i] != target.data[i]){
            return false;
        }
    }

    return true;
} 

void Polynomial::print(){
    if(data_size <= 0 || data == NULL){
        cout << "Can not Print: Polynomial has no coefficients" << endl;
    }

    else{
        //Make sure first number is non-zero
        bool firstNumberPrinted = false;

        for(int i = data_size - 1; i > 0; i--){
            if(data[i] != 0){
                firstNumberPrinted = true;
            }
            
            if(firstNumberPrinted == true){
            cout << data[i] << "x^" << i << " + ";
            }
        }
        cout << data[0] << "x^0"<< endl;
    }
}

Polynomial Polynomial::operator+(const Polynomial& target) {

    if(data_size <= 0 && target.data_size <= 0){
        cout << "Error: Polynomial has no coefficients" << endl;
        Polynomial error(NULL,0);
        return error;
    }

    // Error + A = A
    else if(data_size <= 0){
        cout << "Error: Polynomial has no coefficients" << endl;
        Polynomial error(target.data,target.data_size);
        return error;
    }

    // B + Error = B
    else if(target.data_size <= 0){
        cout << "Error: Polynomial has no coefficients" << endl;
        Polynomial error(data,data_size);
        return error;
    }

    int i = 0; 
    
    if(data_size >= target.data_size){
        int coefficient[data_size];
  
        while(i < target.data_size){
            coefficient[i] = data[i] + target.data[i];            
            i++;
        }

        while(i < data_size){
            
            coefficient[i] = data[i];
            i++;
        }

        Polynomial sum(coefficient, data_size);
        return sum;
    }

    else{
        int coefficient[target.data_size];
  
        while(i < data_size){
            coefficient[i] = target.data[i] + data[i];
            i++;            

        }

        while(i < target.data_size){
            coefficient[i] = target.data[i];
            i++;
        }

        Polynomial sum(coefficient, target.data_size);
        return sum;
    }
}

Polynomial Polynomial::operator-(const Polynomial& target){
    if(data_size <= 0 && target.data_size <= 0){
        cout << "Error: Polynomial has no coefficients" << endl;
        Polynomial error(NULL,0);
        return error;
    }

    else if(data_size <= 0){
        cout << "Error: Polynomial has no coefficients" << endl;
        for(int i = 0; i < target.data_size; i++){
            target.data[i] = -target.data[i];
        }
        Polynomial error(target.data,target.data_size);
        return error;
    }

    else if(target.data_size <= 0){
        cout << "Error: Polynomial has no coefficients" << endl;
        Polynomial error(data,data_size);
        return error;
    }

     int i = 0;
    
    if(data_size >= target.data_size){
        int coefficient[data_size];
  
        while(i < target.data_size){
            coefficient[i] = data[i] - target.data[i];            
            i++;
        }

        while(i < data_size){
            
            coefficient[i] = data[i];
            i++;
        }

        Polynomial sum(coefficient, data_size);
        return sum;
    }

    else{
        int coefficient[target.data_size];
  
        while(i < data_size){
            coefficient[i] = data[i] - target.data[i];
            i++;            

        }

        while(i < target.data_size){
            coefficient[i] = target.data[i];
            i++;
        }

        Polynomial sum(coefficient, target.data_size);
        return sum;
    }
}

Polynomial Polynomial::operator*(const Polynomial& target){
    if(data_size <= 0 || target.data_size <= 0){
        cout << "Error: Polynomial has no coefficients" << endl;
        Polynomial error(NULL,0);
        return error;
    }

    int* coefficients;
    int productPolynomialDegree = (data_size-1)+(target.data_size-1)+1;
    coefficients = new int[productPolynomialDegree]();
    
    Polynomial product(coefficients,productPolynomialDegree); // Empty Copy

    int degree;
    int multiplier;
    for(int i = 0; i < data_size; i++){
        for(int j = 0; j < target.data_size; j++){
            multiplier = data[i]*target.data[j];
            degree = i+j;
            product.data[degree] += multiplier;
        }
    }
    
    return product;
}

Polynomial Polynomial::derivative(){
    if(data_size <= 0 || data == NULL){
        cout << "Error: Polynomial has no coefficients" << endl;
        Polynomial error(NULL,0);
        return error;
    }

    int* coefficients;
    if (data_size == 1){
        coefficients = new int[data_size]();
        cout << "Derivative of constant is zero" << endl;
        return Polynomial(coefficients,data_size);
    }

    coefficients = new int[data_size - 1]();

    int derivativeCoeff;
    int index;
    for(int i = data_size - 1; i > 0; i--){
        int derivativeCoeff = i*data[i];
        coefficients[i-1] = derivativeCoeff;
    }

    Polynomial dx(coefficients, data_size -1);

    return dx;

}


bool PolynomialTest::testDefaultConstructor(){

    Polynomial test1;
    Polynomial test2;

    ASSERT_TRUE(test1.data_size > 0 && test1.data_size < 1001);
    ASSERT_TRUE(test2.data_size > 0 && test2.data_size < 1001);
    ASSERT_FALSE(test1 == test2);
    


    for(int i = 0; i < test1.data_size; i++){
        ASSERT_FALSE(test1.data[i] > 1000 || test1.data[i] < -1000)
    }
    for(int j = 0; j < test2.data_size; j++){
        ASSERT_FALSE(test2.data[j] > 1000 || test2.data[j] < -1000)
    }

    return true;
}

bool PolynomialTest::testParametricConstructor(){
    int A[4] = {1,2,3,4};
    Polynomial test(A,4);
    Polynomial error(A,-1);
    Polynomial error2(NULL,3);

    ASSERT_TRUE(test.data_size == 4)
    for(int i = 0; i < test.data_size ; i++){
        ASSERT_TRUE(test.data[i] == A[i])
    }

    ASSERT_TRUE(error.data_size == 0)
    ASSERT_TRUE(error.data == NULL)
    ASSERT_TRUE(error2.data_size == 0)
    ASSERT_TRUE(error2.data == NULL)

    return true;
}

bool PolynomialTest::testOperatorEquality(){

    int b[8]= {3,3,0,2,0,3,0,3};
    int c[4]= {4,1,3,4};
    Polynomial A(b,8);
    Polynomial B(b,8);
    Polynomial C(c,4);
    ASSERT_TRUE(A == A)
    ASSERT_TRUE(A == B)
    Polynomial Empty(NULL, 0);
    ASSERT_TRUE(Polynomial(NULL,0) == Empty)
    ASSERT_FALSE(C == A)
    ASSERT_FALSE(C == Empty)
    return true;

}

bool PolynomialTest::testReadFileConstructor(){
    
    Polynomial normalCase("test1.txt");
    int a[6]= {6,5,4,3,2,1};
    Polynomial answer1(a,6);
    ASSERT_TRUE( answer1 == normalCase)

    Polynomial normalCase2("test2.txt");
    int x[11] = {11,10,9,8,7,6,5,4,3,2,1};
    Polynomial answer2(x,11);
    ASSERT_TRUE( answer2 == normalCase2)


    Polynomial Missing("test3.txt");
    int b[8]= {3,3,0,2,0,3,0,3};
    Polynomial answer3(b,8);
    ASSERT_TRUE( answer3 == Missing)
    
    Polynomial NegativeExponents("test4.txt");
    int c[4]= {4,3,2,1};
    Polynomial answer4(c,4);
    ASSERT_TRUE( answer4 == NegativeExponents)

    Polynomial NegativeSize("test5.txt");
    Polynomial answer5(NULL,0);
    ASSERT_TRUE( answer5 == NegativeSize)

    // Negative Exponents = Extra Coefficients in txt file , - Igor
    return true;
}

bool PolynomialTest::testCopyConstructor(){
    Polynomial A;
    Polynomial B(A);
    ASSERT_TRUE(A == B);

    int b[8]= {3,3,0,2,0,3,0,3};
    Polynomial C(b,8);
    Polynomial D(C);
    ASSERT_TRUE(C == D);

    Polynomial F(NULL,0);
    Polynomial G(F);
    ASSERT_TRUE( G  == F)

    return true;
}

bool PolynomialTest::testOperatorMakeEqual(){
    Polynomial A;
    int c[4]= {1,2,3,4};
    Polynomial B(c,4);
    Polynomial Empty(NULL, 0);

    A = B;
    Polynomial ANSWER(c,4);
    ASSERT_TRUE(A == ANSWER)
    A = Empty;
    Polynomial ANSWER2(NULL, 0);
    ASSERT_TRUE(A == ANSWER2);
    B = A;
    ASSERT_TRUE(B == ANSWER2);
    return true;

}

bool PolynomialTest::testPrint(){
    int b[8]= {3,3,0,2,0,3,0,3};
    Polynomial testA(b,8);
    testA.print();

    int c[8]= {3,1,2,4,5,6,0,0};
    Polynomial testB(c,8);
    testB.print();

    Polynomial testC(NULL,0);
    testC.print();

    return true;
}

bool PolynomialTest::testOperatorAdd(){

    int A[8] = {3,5,6,2,8,4,4,5};
    int B[8] = {5,6,3,7,1,7,4,2};
    int C[8] = {8,11,9,9,9,11,8,7};
    Polynomial testA(A,8);
    Polynomial testB(B,8);
    Polynomial testC(C,8);
    Polynomial answer1;
    answer1 = (testA + testB);
    ASSERT_TRUE(testC == answer1)

    int D[8] = {3,5,6,2,8,3,1,2};
    int E[5] = {3,4,2,1,6};
    int F[8] = {6,9,8,3,14,3,1,2};
    Polynomial testD(D,8);
    Polynomial testE(E,5);
    Polynomial testF(F,8);
    Polynomial answer2(testD + testE);
    ASSERT_TRUE(testF == answer2)

    Polynomial Empty(NULL,0);
    Polynomial test;
    test = (testD + Empty);
    ASSERT_TRUE(test == testD)
    test = (Empty + testD);
    ASSERT_TRUE(test == testD)

    int zero[8] = {0,0,0,0,0,0,0,0};
    Polynomial Zeros(zero,8);
    Polynomial test2;
    test2 = Zeros + testD;
    ASSERT_TRUE(test2 == testD)
    ASSERT_TRUE(Zeros == (Zeros + Zeros))

    return true;


}

bool PolynomialTest::testOperatorSubtract(){

    int A[8] = {3,5,6,2,8,4,4,5};
    int B[8] = {5,6,3,7,1,7,4,2};
    int C[8] = {-2,-1,3,-5,7,-3,0,3};
    Polynomial testA(A,8);
    Polynomial testB(B,8);
    Polynomial testC(C,8);
    Polynomial answer1;
    answer1 = (testA - testB);
    ASSERT_TRUE(testC == answer1)

    int D[8] = {3,5,6,2,8,3,1,2};
    int E[5] = {3,4,2,1,6};
    int F[8] = {0,1,4,1,2,3,1,2};
    Polynomial testD(D,8);
    Polynomial testE(E,5);
    Polynomial testF(F,8);
    Polynomial answer2(testD - testE);
    ASSERT_TRUE(testF == answer2)

    Polynomial Empty(NULL,0);
    Polynomial test;
    test = (testD - Empty);
    ASSERT_TRUE(test == testD)
    test = (Empty - testD);
    int G[8] = {-3,-5,-6,-2,-8,-3,-1,-2};
    Polynomial answer3(G,8);
    ASSERT_TRUE(test == answer3)

    int zero[8] = {0,0,0,0,0,0,0,0};
    Polynomial Zeros(zero,8);
    Polynomial test2;
    test2 = Zeros + testD;
    ASSERT_TRUE(test2 == testD)
    ASSERT_TRUE(Zeros == (Zeros + Zeros))

    return true;


}

bool PolynomialTest::testOperatorMultiply(){

    // Multiply Polynomial Same size
    int A[4] = {3,5,6,2};
    int B[4] = {5,6,3,7};
    int C[7] = {15,43,69,82,65,48,14};
    Polynomial testA(A,4);
    Polynomial testB(B,4);
    Polynomial testC(C,7);
    Polynomial answer1;
    answer1 = (testA*testB);
    ASSERT_TRUE(testC == answer1)

    // Multiply Different Size
    int D[4] = {3,5,6,2};
    int E[3] = {5,6,9};
    int F[6] = {15,43,87,91,66,18};
    Polynomial testD(D,4);
    Polynomial testE(E,3);
    Polynomial testF(F,6);
    Polynomial answer2;
    answer2 = (testE*testD);
    ASSERT_TRUE(testF == answer2)

    // Multiply Empty
    Polynomial Empty(NULL,0);
    Polynomial test;
    test = (testD * Empty);
    ASSERT_TRUE(test == Empty)
    ASSERT_TRUE(Empty == Empty*Empty)

    // Multiply Zero
    int zero[8] = {0,0,0,0,0,0,0,0};
    Polynomial Zeros(zero,8);
    Polynomial test0;
    test0 = Zeros * testD;
    ASSERT_TRUE(test0 == Zeros)     // Zero * Polynomial = 0
    ASSERT_TRUE(Zeros == (Zeros * Zeros)) // 0 = 0*0

    return true;

}

bool PolynomialTest::testOperatorDeriver(){
    
    // Derive Polynomial
    int A[4] = {3,5,6,2};
    int Aderived[3] = {5,12,6};
    Polynomial testAnswerA(Aderived,3);
    Polynomial testA(A,4);
    Polynomial testAderived;
    testAderived = testA.derivative();
    ASSERT_TRUE(testAderived == testAnswerA)
    
    // Derive Constant
    int B[1] = {5};
    int Bderived[1] = {0};
    Polynomial testB(B,1);
    Polynomial testAnswerB(Bderived,1);
    Polynomial testBderived;
    testBderived = testB.derivative();
    ASSERT_TRUE(testBderived == testAnswerB)

    // Derive 0
    int C[1] = {0};
    int Cderived[1] = {0};
    Polynomial testC(C,1);
    Polynomial testAnswerC(Cderived,1);
    Polynomial testCderived;
    testCderived = testC.derivative();
    ASSERT_TRUE(testCderived == testAnswerC)

    // Derive Empty
    Polynomial Empty(NULL,0);
    Polynomial test;
    test = Empty.derivative();
    ASSERT_TRUE(test == Empty)

    return true;
}


void PolynomialTest::run(){
    cout << (testDefaultConstructor() ? "Test Increment Scenario1 Passed" : 
        "Test Increment Scenario1 Failed") << endl; 

    cout << (testParametricConstructor() ? "Test Increment Scenario2 Passed" : 
        "Test Increment Scenario2 Failed") << endl; 

    cout << (testOperatorEquality() ? "Test Increment Scenario3 Passed" : 
        "Test Increment Scenario3 Failed") << endl;
    
    cout << (testReadFileConstructor() ? "Test Increment Scenario4 Passed" : 
        "Test Increment Scenario4 Failed") << endl;

    cout << (testCopyConstructor() ? "Test Increment Scenario5 Passed" : 
        "Test Increment Scenario45Failed") << endl;    
        
    cout << (testOperatorMakeEqual() ? "Test Increment Scenario6 Passed" : 
        "Test Increment Scenario6 Failed") << endl;


    testPrint();
    cout << "Answers Test 7:" << endl;
    cout << "3x^7 + 0x^6 + 3x^5 + 0x^4 + 2x^3 + 0x^2 + 3x^1 + 3x^0" << endl;
    cout << "6x^5 + 5x^4 + 4x^3 + 2x^2 + 1x^1 + 3x^0" << endl;
    cout << "Error: Can not construct, returned NULL/ SIZE 0" << endl;
    cout << "Can not Print: Polynomial has no coefficients" << endl << endl;

    cout << (testOperatorAdd() ? "Test Increment Scenario8 Passed" : 
        "Test Increment Scenario8 Failed") << endl;

    cout << (testOperatorSubtract() ? "Test Increment Scenario9 Passed" : 
        "Test Increment Scenario9 Failed") << endl;

    cout << (testOperatorMultiply() ? "Test Increment Scenario10 Passed" : 
        "Test Increment Scenario10 Failed") << endl;

    cout << (testOperatorDeriver() ? "Test Increment Scenario11 Passed" : 
        "Test Increment Scenario11 Failed") << endl;

}

