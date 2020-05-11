#include <iostream>
#include <cmath>
using namespace std;

//Recursive function that takes a single integer and prints in reverse

void printReverseInteger(int num){
    if(num %10 == 0)
        return;
    else if(num < 0){
        cout << "-";
        printReverseInteger(-1*num);
    }
    else{
        cout << num % 10;
        printReverseInteger(num/10);
    }
}

// Function that takes integer and then prints the digits on seperate lines

void printDigitPerLine(int num){
    if(num < 10){
        cout << num << endl;
        return;
    }
    else if(num < 0){
        cout << "-" << endl;
        printDigitPerLine(-1*num);
    }
    else{
        printDigitPerLine(num/10);
        cout << num % 10<< endl;
    }
}

// Function to calculate the series

int calculateSeries(unsigned int n){
    if( n <= 1)
        return 1;
    else
        return n + calculateSeries(n-1);
}

// Function calculate series of squares

void squareSeries(unsigned int n){
    if(n<=1){
        cout << 1 << " ";
        return;
    }
    else{
        squareSeries(n-1);
        cout << pow(n,2) << " ";
    }
}

int findDivisor(int num,  int best_divisor){ // Pass in any number that is num-1
    if (best_divisor >= num || best_divisor < 1){
        return findDivisor( num , num-1);
    }
    if(num % best_divisor == 0)
        return best_divisor;
    else{
        return findDivisor(num, best_divisor -1);
    }
}

bool isPrimeNumber(int num){
    // return one if can not find divisor from num-1 to 2
    return (findDivisor(num, num -1) == 1);
}



bool Palindrome(string palindrome){
    if(palindrome.length() <= 1)
        return true;
    else{
        if(palindrome[0] == palindrome[palindrome.length() -1] )
            return Palindrome(palindrome.substr(1, palindrome.length() -2));
        return false;
    }
}









int main(){
    // printReverseInteger(-12345);
    // printDigitPerLine(-12345);
    // int answer = calculateSeries(6);
    // cout << answer << endl;
    // squareSeries(5);
    // cout << findDivisor(42,50) << endl;
    // cout << Palindrome("racecar") << endl;
    cout << isPrimeNumber(11) << endl;
    return 0;
}