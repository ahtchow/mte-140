#include <stack>
#include <iostream>
using namespace std;

class SpecialQueue{

private:
    const int empty = -999;
    stack<int> main, side;

public:
    void enqueue(int value){
        main.push(value);
    }
    int size(){
        if(main.empty())
            return empty;
        return main.size();
    }
    void dequeue(){
        while(!main.empty()){
            int temp = main.top(); main.pop();
            side.push(temp);
        }
        cout << side.top() << endl;
        side.pop();

        while(!side.empty()){
            int temp = side.top(); side.pop();
            main.push(temp);
        }

    }

};

int main(){
    SpecialQueue test;
    cout << test.size() << endl;
    for(int i = 0; i < 5; i++){
        test.enqueue(i);
        cout << i << endl;
    }
    test.dequeue();
    for(int i = 0; i < 4; i++){
        test.dequeue();
    }


    
}