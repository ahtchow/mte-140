/**
 * @file StacksNQueues.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stack>;
#include <queue>;
#include <iostream>;

/**
 * @brief Stack ADT 
 * 
 */
class Stack{
public:
    typedef int StackItem; // Define StackItem Datatype as int

    bool push(StackItem sItem); // Add item to top of stack
    StackItem pop(); // remove item from top of stack
    StackItem peek(); // Return reference to top item 
};

class Queue{
public:
    typedef int QueueItem;

    bool enqueue(QueueItem qItem); // Add item to back of queue
    QueueItem dequeue(); // remove item from front of queue
    QueueItem peek(); // return reference to front of queue
};

/**
 * @brief A function named removeMaxFromStack from a stack of integers
 * 1. iterate through stack
 * 2. finds the maximum integer inside;
 * 3. puts maximum back in order w. maximum elements removed
 * 4. return modified stack
 */

typedef int StackItem;

std::stack<StackItem> removeMaxFromStack(std::stack<StackItem> p){
    if(p.empty()){
        std::cout << "The stack is empty" << std::endl;
        return p; 
    }

    std::stack<StackItem> helper;
    StackItem max = p.top();
    while(!p.top()){
        StackItem cur = p.top();
        if(cur > max)
            max = cur;
        helper.push(cur);
        p.pop();
    }

    while(!helper.empty()){
        StackItem cur = helper.top();
        if(cur < max)
            p.push(cur);
        helper.pop();
    }

    return p;

}