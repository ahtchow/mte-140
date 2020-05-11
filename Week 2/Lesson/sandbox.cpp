#include <iostream>

using namespace std;

int main(){
    int* pull;
    int s= 5;
    pull = &s;
    cout << *pull << endl;

    int* ip;
    int array[5] = {1,2,3,4,5};
    ip = array;
    cout << *ip << endl;
    ip++;
    cout << *ip << endl;
    ip+=2;
    cout << *ip << endl;




}