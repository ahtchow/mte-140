#include <iostream>
#include <vector>

using namespace std;

int main(){
    int *p = NULL;
    int x = 5;
    p = &x;
    *p = 100;
    p = *p + p;
    cout << *p << endl;

}