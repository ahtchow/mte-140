#include <iostream>
#include <math.h>
using namespace std;

// 1. Convert a string of digits into matching integers

int ascii2int(string num, int index, int char_left){
    if(char_left == 0){
        return 0;
    }
    else{

            int digit = pow(10, char_left-1);
            int value = num[index]-48;
            if(num[index] == 45){ //Negative numbers
                return (-1*ascii2int(num, ++index,char_left));
            }
            return (value*digit + ascii2int(num, ++index,--char_left));
    }
}

// 2. Convert a integers of digits into matching string

string int2ascii(int num){
    if(num < 0){
        return "-" + int2ascii(-1*num);
    }
    else if(num <= 9){
        return string(1,'0' + num); // Eventually will end here.
    }
    else{
        return int2ascii(num/10) + char('0' + (num%10));
    }

}

//3. Converts binary string into the matching decimal (i.e  "101" = 5)

int binarystring2decimal(string num,  int index){
    if(index == num.size()){
        return 0;
    }
    else if(num.at(index) == '-') // Negative
        return -1* binarystring2decimal(num.substr(1), index);
    else if(num.at(index) == '1' || num.at(index) == '0') // Handle non-0 or non-1
        return binarystring2decimal(num,++index);
    else {
        if(num.at(index)==  '0')
            return binarystring2decimal(num,++index);
        int sum = pow(2,index);
        return (sum + binarystring2decimal(num,++index));
    }
}

//Converts decimal into binary string

string decimal2binarystring( int num){
     if (num < 0){
        return "-" + decimal2binarystring(-1 * num);
    }
    //Base Case:
    else if(num == 0)
        return "0";
    else if(num == 1)
        return "1";
    else{
        return (decimal2binarystring(num/2) + (num%2 != 0 ? "1" : "0" ));
        // If there the digit can not be divisible by two , add "1"
    }

}

int main(){

    string test_num = "-2";
    int num_result = ascii2int(test_num, 0 , 1);
    cout << num_result << endl;

    int test_num2 = -21243;
    string num_result2 = int2ascii(test_num2);
    cout << num_result2 << endl;

    string o = "-101";
    cout << binarystring2decimal(o,0) << endl;

    int x = 12;
    cout << decimal2binarystring(12) << endl;

    return 0;

}