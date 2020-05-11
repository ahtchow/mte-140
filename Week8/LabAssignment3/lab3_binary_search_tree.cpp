#include <iostream>
#include <queue>
#include "lab3_binary_search_tree.hpp"

using namespace std;

/**
 * @brief Default / Empty Constructor
 */

BinarySearchTree::BinarySearchTree() {

	//Initaialize new empty root
	root = NULL;
	size = 0;

}

/**
 * @brief BinarySearchTree Destructor
 */

BinarySearchTree::~BinarySearchTree() {

	//Use remove function to delete each TaskItem
	while(size)
		remove(*root);
}

/**
 * @brief Returns the number of nodes in the tree 
 */

unsigned int BinarySearchTree::get_size() const {

	// Return size
	return size;

}

/**
 * @brief Returns the maximum value of a node in the tree
 * If the tree is empty, it returns (-1, "N/A")
 */

BinarySearchTree::TaskItem BinarySearchTree::max() const {
	
	//If the tree is empty
	if(!size)
		return BinarySearchTree::TaskItem(-1, "N/A");
	
	TaskItem* temp = root;
	
	// Traverse to furthest right from the node
	while(temp->right)
		temp = temp->right;

	return *temp;

}

/**
 * @brief Returns the minimum value of a node in the tree
 * If the tree is empty, it returns (-1, "N/A")
 */

BinarySearchTree::TaskItem BinarySearchTree::min() const {
	
	//Empty Binary Search Tree
	if(!size)
		return BinarySearchTree::TaskItem(-1, "N/A");
	
	TaskItem* temp = root;
	
	// Traverse to furthest left from the node
	while(temp->left)
		temp = temp->left;

	return *temp;

}

/**
 * @brief Return the height of the Binary Search Tree
 * if there is no TaskItems return -1
 */

unsigned int BinarySearchTree::height() const {

	//Call Recursive function countBranches()
	return get_node_depth(root);	
}

// PURPOSE: Prints the contents of the tree; format not specified
void BinarySearchTree::print() const {

    queue<TaskItem*> q;

    if(root)
        q.push(root);

    cout << "Start Breadth-First Traversal:" << endl;

    while(!q.empty()){

        TaskItem* cur = q.front();
        cout << cur->priority << " "; // visit the current node
		if (cur->left) q.push(cur->left); // enqueue left
		if (cur->right) q.push(cur->right); // enqueue right
        q.pop();

    }

    cout << endl;

}

/**
 * @brief Returns true if a node with the value val exists in the tree otherwise, returns false
 */

bool BinarySearchTree::exists( BinarySearchTree::TaskItem val ) const {

	//Empty Binary Search Tree
	if(!size)
		return false;
	
	TaskItem* temp = root;

	//While the value is not found
	while(temp != NULL){

		//If found
		if(val == *temp){
			return true;
		}
		
		// If priority is greater than current node, traverse right
		if(val.priority > temp->priority){

			temp = temp->right;

		}

		// If priority is greater than current node, traverse left
		else{
			
			temp = temp->left;

		}
		
	}

	//End of search, could not find
	return false;

}

/**
 * @brief Optional helper function that returns a pointer to the root node
 */

BinarySearchTree::TaskItem* BinarySearchTree::get_root_node() {

	//Return root node
    return root;
}

/**
 * @brief Optional helper function that returns the root node pointer address
 */

BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    
	//Return root node
	return &root;
}

/**
 * @brief Optional helper function that gets the maximum depth for a given node 
 */

int BinarySearchTree::get_node_depth( BinarySearchTree::TaskItem* n ) const {
	
	// No TaskItem
	if(n == NULL)
		return -1;

	//Recursively return max between height between every branch
	return 1 + std::max(get_node_depth((n->left)), get_node_depth(n->right));

}

/**
 * @brief Inserts the value val into the tree if it is unique
 *  returns true if successful; returns false if val already exists
 */

bool BinarySearchTree::insert( BinarySearchTree::TaskItem val ) {
    
	//Empty Tree Case
	if(root == NULL){

		root = new TaskItem(val.priority,val.description);
		++size;
		return true;

	}	

	//Check for Duplicates
	if(exists(val)){

		cout << "TaskItem already exists in binary search tree." << endl;
		return false;

	}

	TaskItem* temp = NULL;
	TaskItem* runner = root;
	
	while(runner){

		temp = runner;

		//Val Priority is greater than current node
		if(val.priority > temp->priority){

			runner = runner->right;

		}

		//Val Priority is greater than current node
		else{

			runner = runner->left;

		}

	}

	//Add left leaf node if priority is less than temp
    if (val.priority < temp->priority)
        temp->left = new TaskItem(val.priority,val.description);

	//Add right leaf node if priority is greater than temp	
    else
        temp->right = new TaskItem(val.priority,val.description);
    
    ++size;
    return true;

}

/**
 * @brief Removes the value val into the tree if it is unique
 *  returns true if successful; returns false if val already exists
 */

bool BinarySearchTree::remove( BinarySearchTree::TaskItem val ) {
    
	//Check to see val exists
	if(!exists(val))
		return false;

	// One TaskItem in the binary search tree
	if(size == 1){

		delete root;
		root = NULL;
		--size;
		return true;

	}

	TaskItem* parent_temp = NULL;
	TaskItem* temp = root;

	//Find the value
	while(!(*temp == val)){

		parent_temp = temp;

		//Val Priority is greater than current node
		if(val.priority > temp->priority)
			temp = temp->right;

		//Val Priority is greater than current node
		else
			temp = temp->left;

	}

	//2. Both left and right exists
	if(temp->left != NULL && temp->right != NULL){
		
		TaskItem* parent_of_min = temp;
		TaskItem* min_in_right_subtree = temp->right;

		while(min_in_right_subtree->left != NULL){
			parent_of_min = min_in_right_subtree;
			min_in_right_subtree = min_in_right_subtree->left;
		}

		//Set the target node to min right subtree
		temp->priority = min_in_right_subtree->priority;
		temp->description = min_in_right_subtree->description;

		// If min has a right subtree
		if(min_in_right_subtree == parent_of_min->left)
			parent_of_min->left = min_in_right_subtree->right;

		else if(min_in_right_subtree == parent_of_min->right)
			parent_of_min->right = min_in_right_subtree->right;

		delete min_in_right_subtree;
		min_in_right_subtree = NULL;

	}

	//3. Both left and right do not exist.
	else if(temp->left == NULL && temp->right == NULL){

		//If the temp is the left child 
		if(parent_temp->left != NULL && temp == parent_temp->left)
			parent_temp->left = NULL;

		//If the temp is the right child
		else
			parent_temp->right = NULL;

		delete temp;
		temp = NULL;
	}

	//4. Right child for temp does not exist
	else if(temp->left != NULL && temp->right == NULL){

		//If not root node
		if(parent_temp){

			//If the temp is the left child 
			if(parent_temp->left != NULL && temp == parent_temp->left)
				parent_temp->left = temp->left;

			//If the temp is the right child
			else
				parent_temp->right = temp->left;

			delete temp;
			temp = NULL;
		}

		else{

			delete root;
			root = temp->left;

		}
	}

	// 5. Left child for temp does not exist
	else if(temp->right != NULL && temp->left == NULL){

		//If not root node
		if(parent_temp){

			//If the temp is the left child 
			if(parent_temp->left != NULL && temp == parent_temp->left)
				parent_temp->left = temp->right;

			//If the temp is the right child
			else
				parent_temp->right = temp->right;
		
			delete temp;
			temp = NULL;
		
		}

	else{

			delete root;
			root = temp->right;
			
		}
	}

	--size;
	return true;

}
