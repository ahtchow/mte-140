#include <iostream>
#include <cassert>

using namespace std;

class Node{
    int data;
    Node* next;

public:

    Node(): data(0), next(NULL){};
    Node(int new_data): data(new_data), next(NULL) {};

    Node* getNext(){ // Must return a DataType: Pointer to a Node 
        return next;
    }

    void setNext(Node* new_next){
        next = new_next;
    }

    int getData(){
        return data;
    }

    void setData(int new_data){
        data = new_data;
    }

    ~Node(){
        delete next;
        next = NULL;
    }

};

class LinkedList{
    
    Node* head;
    int size;

public:

    LinkedList(): head(NULL),size(0){};
    ~LinkedList(){
        delete head;
        head = NULL;
    }

    int getSize(){
        return size;
    }

    bool push_back(int data){
        if(!head){
            head = new Node(data);
        }
        else{
            Node* end = head;
            while(end->getNext()){
                end = head->getNext();
            }
            end->setNext(new Node(data));
        }
        size++;
        return true;
            
    }

    bool pop_back(){
        if(!head){
            return false; 
        }
        else if(!head->getNext()){
            delete head;
            head = NULL;
        }
        else{
            Node* end = head;
            while(end->getNext()->getNext()){
                end = end->getNext();
            }
            delete end->getNext();
            end->setNext(NULL); 
        }

        --size;
        return true;
    }

    void print(){
        cout << "(";
        Node* end = head;
        while(end){
            cout << "[" << end->getData() << "]";
            end = end->getNext();
            cout << "hi" << endl;
            if(end){
                cout << "->";
            }
        }
        cout << ")" << endl;
    }


    bool find(int data){
        if(!head){
            return false;
        }
        Node* end = head;
        while(end){
            if(end->getData() == data){
                return true;
            }
            end = end->getNext();
        }
        return false;
    }

    bool reverseList(){
        Node* cur = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(cur){
            next = cur->getNext();
            cur->setNext(prev);
            prev = cur;
            cur = next;
        }
        head = prev;
        return true;
    }

    bool hasCycle() { 
        if (!head || !head->getNext())
            return false;

        Node* runner1 = head;
        Node* runner2 = head->getNext();

        while (runner1 != runner2) {
            if (!runner2 || !runner2->getNext())
                return false;
            runner1 = runner1->getNext();
            runner2 = runner2->getNext()->getNext();
        }

        return true;
        }
};

int main(){
    LinkedList test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);

    test.print();

    // // assert(test.find(2) == true);
    // test.reverseList();
    // test.print();
    // test.pop_back();
    // // assert(test.find(1) == false);
    // cout << "passed" << endl;
    // return 0;

}