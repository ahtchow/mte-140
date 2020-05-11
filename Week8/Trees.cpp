/**
 * @file Trees.cpp
 * @author Adrian Chow (you@domain.com)
 * @brief Trees ADT
 * @version 0.1
 * @date 2020-03-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief 
 * - One Root Node
 * - Zero or more nodes child nodes
 * - At most One parents
 * - Descendants: Reachable from current downwards 
 * - Ascestors: Reachable from the current upwards 
 */

// DESIGN A BINARY TREE 
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

void visit(int other);

class BinaryTreeNode{

private:
    int data; // holds value at node
    BinaryTreeNode* left;
    BinaryTreeNode* right;
public:
    BinaryTreeNode(); // Constructor
    ~BinaryTreeNode(); // Destructor

    int get_data(){return data;}
    BinaryTreeNode* get_left(){return left;}
    BinaryTreeNode* get_right(){return right;}
    BinaryTreeNode* get_depth(); // Length from root to child node.
    int get_height(); // Length from root to leaf.

    void pre_order(BinaryTreeNode* other);
    void post_order(BinaryTreeNode* other);
    void in_order(BinaryTreeNode* other);

};

int get_height(BinaryTreeNode* T){
    if(!T)
        return -1;
    else{
        return (1 + max(get_height(T->get_left()), get_height(T->get_right())));
    }

}

/**
 * @brief What's a complete tree.
 *  All levels filled except bottom layer, all leaf nodes are furthest left
 */

/**
 * @brief Traversing Trees
 */

void pre_order(BinaryTreeNode* T){
    if(!T)
        return;

    visit(T->get_data()); // Visit Root
    T->pre_order(T->get_left()); // Visit Left Subtree
    T->pre_order(T->get_right()); // Visit Right Subtree
}

void pre_order(BinaryTreeNode* T){
    if(!T)
        return;
    T->in_order(T->get_left()); // Visit Left Subtree
    visit(T->get_data()); // Visit Root
    T->in_order(T->get_right()); // Visit Right Subtree
}

void pre_order(BinaryTreeNode* T){
    if(!T)
        return;

    T->post_order(T->get_left()); // Visit Left Subtree
    T->post_order(T->get_right()); // Visit Right Subtree
    visit(T->get_data()); // Visit Root

}

void preOrderUsingStack(BinaryTreeNode* T){
    stack<BinaryTreeNode*> s;
    s.push(T);
    while(!s.empty()){
        BinaryTreeNode* curr = s.top();
        s.pop();
        visit(curr->get_data());
        if(curr->get_right())
            s.push(curr->get_right());
        if(curr->get_left())
            s.push(curr->get_left());
    }
}

void inOrderUsingStack(BinaryTreeNode* T){
    stack<BinaryTreeNode*> s;
    BinaryTreeNode* curr = T;
    while(curr||!s.empty()){ //push left until 
        if(curr){
            s.push(curr);
            curr = curr->get_left();
        }
        else{ //pop i fthe left child is null
            curr = s.top();
            s.pop();
            visit(curr->get_data()); //print or other processing
            curr = curr -> get_right(); //Push child right
        }

    }


}