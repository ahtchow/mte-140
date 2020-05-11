#include <iostream>
#include <stack>
using namespace std;

/**
 * Implement a non‐recursive function named remove_median_from_stack that takes as input a sorted 
 * collection of integers stored in stack p. The function (1) iterates through the stack, 
 * (2) finds the median value inside the stack (i.e., the middle value for an odd number of elements,
 *  or the average between the two middle values for an even number of elements), (3) puts all 
 * the elements back in the original order but with the median value or values removed, and (4) 
 * returns the modified stack to the caller. That is, for input [1, 3, 5, 7, 55], remove_median_from_stack would return [1, 3, 7, 55].
 * Your function may only use one other Stack as part of its implementation; that is, the new stack q. 
 * You may also use a number of primitive temporary variables, but no other data structures. 
 * In your code, you may only call the <stack> methods, such as bool empty(), int size(), void push (int value), void pop(), and int top().
 * 
 */

stack<int> remove_median_from_stack(stack<int> p){
    if(p.empty())
        return p;
    stack<int> q;
    stack<int> empty;
    int size = p.size();
    if(p.size() == 1)
        return empty;

    if(size % 2 == 0){ // EVEN
        int mid = (size/2);
        for(int i = 0; i < size; i++){
            if (!(i == mid || i == mid -1 )){
                q.push(p.top());
            }
            p.pop();
        }
    }
    else{
        int mid = (size/2);
        for(int j = 0; j < size; j++){
            if (!(j == mid )){
                q.push(p.top());
            }
            p.pop();
        }
    }
    size = q.size();
    for(int k = 0; k < size; k++){
        p.push(q.top());
        cout << q.top() << endl;
        q.pop();
    }
    return p; 
}

int main(){
    stack<int> testEven;
    for(int i = 1; i <= 7; i++){
        testEven.push(i);
        cout << i << endl;
    }
    testEven = remove_median_from_stack(testEven);
}
