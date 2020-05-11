#include <stack>
#include <queue>
#include <iostream>

using std::stack;
using std::queue;
typedef int StackItem;
typedef stack<StackItem> DynamicStack;


stack<int> removeMaxFromStack(stack<int> p) {

    //If the size of stack is one or empty
    if(p.empty() || p.size() == 1){
        stack<int> empty;
        return empty;
    }

    int max = INT_MIN;
    stack<int> temp;
    while(!p.empty()){
        int popped = p.top();
        if (popped > max) max = popped;
        temp.push(popped);
        p.pop();
    }

    while(!temp.empty()){
        int popped2 = temp.top();
        if(!popped2 == max)
            p.push(popped2);
    }

    return p;
}

stack<int> removeMedianFromStack(stack<int>p){

    if(p.empty() || p.size() == 1){
        stack<int> empty;
        return empty;
    }

    int median_one, median_two;

    if(p.size() % 2 == 0) {
        median_one = p.size() -1;
        median_two = p.size();
    }

    else{
        median_one = median_two = p.size();
    }

    int count = 0;
    stack<int> t;
    while(!p.empty()){
        int temp = p.top();
        if(!(count == median_one || count == median_two))
            t.push(temp);
        p.pop();
        count++;
        }
    while(!t.empty()){
        int temp = t.top();
        t.pop();
        p.push(temp);
    }
    return p;

    }

DynamicStack transferStack(DynamicStack p){

    if(p.empty()) return p;

    DynamicStack q;
    size_t stack_size = p.size();
    StackItem temp;

    for(int i = 0; i < stack_size; ++i){

        size_t remove_count = 0;
        size_t temp_size = p.size();

        while(!p.empty()){
            
            StackItem transfer = p.top(); 
            p.pop();
            q.push(transfer);
            ++remove_count;
            if(remove_count == temp_size){
                temp = q.top();
                q.pop();
            }
        }

        for(int j = 0; j < temp_size - 1; ++j){

            StackItem transfer = q.top();
            q.pop();
            p.push(transfer);

        }

        q.push(temp);

    }

    return q;

}

int main(){

    DynamicStack p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5);
    p.push(6);
    DynamicStack q;
    q = transferStack(p);
    size_t e = q.size();
    for(int i = 0; i < e; ++i){
        std::cout << q.top() << std::endl;
        q.pop();
    }

    return 0;
}