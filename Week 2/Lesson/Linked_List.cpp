#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const bool TEST_HAS_CYCLE = false;
const int CYCLE_INDEX = 3;

class Node{

  int data;
  Node* next;

public: 

  // CONSTRUCTORS

  /**
   * @brief Construct a new Node object (Default)
   * data stored is NULL/0 depending on DataType
   * next pointer points to null
   */

  Node(): data(0), next(NULL) {}

  /**
   * @brief Construct a new Node object (Parametric)
   * data stores new_data which was inputed
   * next pointer points to null
   */

  Node(int new_data): data(new_data), next(NULL) {}

  // PURPOSE: SIMPLE GETTERS AND SETTERS

  /**
   * @brief Get the next object
   * @return Next Node* 
   */

  Node* getNext(){
    return next;
  }

  /**
   * @brief Set the next object
   * @param new_next  
   */

  void setNext(Node* new_next){
    next = new_next;
  }
  /**
   * @brief Get the Data object
   * @return data
   */

  int getData(){
    return data;
  }

  /**
   * @brief Set the Data object
   * @param new_data 
   */

  void setData(int new_data){
    data = new_data;
  }

};

//////////////////////////////////////////////////////////////////////////////////////


class LinkedList{

  Node* head;
  int size;

public:
  
  /**
   * @brief Construct a new Linked List object
   * Defualt Constructor 
   */

  LinkedList(): head(NULL), size(0){}

  int getSize(){
    return size;
  }

  void setSize(int new_size){
    size = new_size;
  }

  ~LinkedList(){
    vector<Node*> cleanup;
    while(head){
      if(std::find(cleanup.begin(), cleanup.end(), head) == cleanup.end()){ // Find head, set it to end
        cleanup.push_back(head); //Pop back the head
        head = head->getNext(); //Set head to next
      }
      else{
        head = NULL;
      }
    }
  }

  /**
   * @brief Add new node to end of the list
   * Creates a new node with data inside
   * @param data 
   */

  bool push_back(int data){
    if(!head){ // Will return true if not NULL
      head = new Node(data); // Set the head to a new node with input DATA
    }
    else{
      Node* end = head; // Set new node as head to Start Iteration
      
      while(end->getNext()){ //Continue to iterate until NULL
        end = end->getNext(); 
      }
      end-> setNext(new Node(data)); //Set the next to new Node, next will be NULL
    }
    size++;
    return true;
  }

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */

  bool pop_back(){
    if (!head){
      return false; // Nothing to do 
    }
    else if(head->getNext() == NULL) {
      delete head;
      head = NULL;
    }
    else{
      Node* end = head;
      while(end->getNext()->getNext()){
        end = end->getNext(); //Iterate Until Second Last
      }
      delete end->getNext(); //Free Memory for Last Node 
      end->setNext(NULL); //Set Next To NULL
    }
    --size;
    return true;
  };

  /**
   * @brief Print Linked List
   * 
   */

  void print(){
    if(!head){
      return;
    }
    cout << "("; //Print the header data
    Node* end = head;
    while(end){
      cout << "[" << end->getData() << "]"; //Print Node Data
      end = end->getNext();
      if(end != NULL){
        cout << "->";
      }
    }
    cout << ")\n"; 
  }

  /**
   * @brief Find Data
   * @param data 
   * @return true if data found
   * @return false else
   */

  bool findValue(int data){
    if(!head){

      return false;
    }
    Node* end = head;
    while(end->getNext()){ //While end points to something not NULL
      if(end->getData() == data){ //If pointer to data equals data request
        return true;
      }
      end = end->getNext(); 
    }
    return false;
  }

  /**
   * @brief reverse LinkedList
   */

  bool reverseList(){
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;

    while(curr){
      next = curr->getNext();
      curr->setNext(prev);
      prev = curr;
      curr = next;
    }
      head = prev;
      return true;
  }

  bool hasCycle(){ // Circular Linked List

    // In a cycle, no next or value can equal NULL
    if( !head || !head->getNext() ){
      return false;
    }
    Node* runner1 = head;
    Node* runner2 = head->getNext();
    while(runner1 != runner2){
      if(!runner2 || !runner2->getNext()){
        return false;
      }
      runner1 = runner1->getNext();
      runner2 = runner2->getNext()->getNext();
    }
    return true;
  }

  bool insertCycle(int value){
    Node* end = head;
    Node* cycle = NULL;
    int index = 0;

    if(!end || value >= size){ // Must have a head to become cyclone
      return false;
    }

    while(end->getNext()){
      if(index <= value){
        cycle = end;
        ++index;
      }
      end = end -> getNext();
    }
    end->setNext(cycle);
    return true;
  }
   
};


int main(){

  LinkedList list; //create a new list

  //test push_back() and print()
  list.push_back(5);
  list.push_back(7);
  list.push_back(3);
  list.push_back(1);
  list.push_back(14);
  list.print();
  cout << "The number of inserted nodes in the list: " << list.getSize() << endl;
  
  // test find()
	cout << "The value 11 is inside the list: " << (list.findValue(11) ? "Yes" : "No") << endl;
	cout << "The value 3 is inside the list: " << (list.findValue(3) ? "Yes" : "No") << endl;

 
  // test reverse_list()
  cout << "Reversing List" << endl;
  list.reverseList();
  list.print();

  if(TEST_HAS_CYCLE){
    cout << "The list has a cycle: " << (list.hasCycle() ? "Yes" : "No") << endl;
		cout << "Inserting a cycle to the node at index " << CYCLE_INDEX << "\n";
		list.insertCycle(CYCLE_INDEX);
		cout << "The list has a cycle: " << (list.hasCycle() ? "Yes" : "No") << endl;
    // need special cleanup method after this
  }

  else{
  // test pop_back() and print()
	list.pop_back(); // delete the last node
	list.pop_back(); // delete the last node
  cout << "HEloo" << endl;
	list.pop_back(); // delete the last node
	list.pop_back(); // delete the last node
	list.pop_back(); // delete the last node
	list.pop_back(); // delete the last node; try one extra
	list.print();
	cout << "The number of inserted nodes in the list: " << list.getSize() << endl;
  }
  
  return 0;

}