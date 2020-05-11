#include <iostream>
#include <stack>
using namespace std;

/**
 * Implement a non‐recursive function named transfer_stack that takes 
 * as input a collection of integers stored in stack p, 
 * and transfers the elements from p into a new stack q while 
 * preserving the order from p in q.
 * Once q includes all the data items from p and in the same 
 * order as in p, the function returns q and terminates.
 * 
 * Your function needs to use only one other stack to implement 
 * the algorithm; that is, the new stack q. You may also use a 
 * number of primitive temporary variables, 
 * but no other arrays, lists, stacks, or other data structures.
 * In your code, you may only call the <stack> methods, such as bool empty()
 * , int size(), void push (int value), void pop(), and int top(). 
 * You may use helper functions if needed, but those need to be 
 * non‐recursive too.
 * 
 */

stack<int> transfer_stack(stack<int> p) {
    stack<int> q;
    int size = p.size();
    for (int count = 0; count < size ; ++count) {
        // pop the top element from p, and store it as temp
        int temp = p.top(); p.pop();
        // remove p.size() ‐ count elements from p and store them onto q 
        int p_size_cached = p.size(); 
        for(int i=0; i<(p_size_cached - count);++i) {
            int cur = p.top(); p.pop(); 
            q.push(cur);
        }
        // store temp onto p 
        p.push(temp);
        // move back all the elements back from q to p 
        while(!q.empty()) {
            int cur = q.top(); q.pop(); 
            p.push(cur);
        } 
    }
        while(!p.empty()) {
            int cur = p.top(); p.pop();
            cout << cur << endl;
            q.push(cur); 
        }
        
    return q;
}

int main(){
    stack<int> testEven;
    for(int i = 3; i >= 1; i--){
        testEven.push(i);
        cout << i << endl;
    }
    testEven = transfer_stack(testEven);
}
