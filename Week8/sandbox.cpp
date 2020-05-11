#include <iostream>
using namespace std;

unsigned int call(){
    return -1;
}

int main(){
    unsigned int c = call();
    cout << c << endl;
    return 0;
}