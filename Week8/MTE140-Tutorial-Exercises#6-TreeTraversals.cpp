#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// PURPOSE: Models Binary Tree Node
struct BinaryTreeNode {
	int data; // value of the node
	BinaryTreeNode* left; // pointer to the left node
	BinaryTreeNode* right; // pointer to the right node
	BinaryTreeNode(int new_val) : data(new_val), left(NULL), right(NULL) {}    	
};

// PURPOSE: Prints tree nodes using inoder traversal
void inorder_using_stack(BinaryTreeNode* T) {
	stack<BinaryTreeNode*> s;		
	BinaryTreeNode* current = T;

	cout << "Start Inorder Traversal:" << endl;	
	while(current || !s.empty()){ 
  		if(current){ // push left child nodes to the stack until NULL
    		s.push(current);
    		current = current->left;
    		
  		} else if(!s.empty()) { // pop if the left child is NULL
			current = s.top(); s.pop();			
    		cout << current->data << " "; // visit the current node
    		current = current->right; // push right child nodes
    	}
	}
   	cout << endl;
}

// PURPOSE: Prints tree nodes using breadth-first traversal
void print_BFT(BinaryTreeNode* T) {
	queue<BinaryTreeNode*> q;
	
	if (T) q.push(T); // check if T is NULL
	cout << "Start Breadth-First Traversal:" << endl;
	while (!q.empty()) {
		BinaryTreeNode *cur = q.front();
		cout << cur->data << " "; // visit the current node
		if (cur->left) q.push(cur->left); // enqueue left
		if (cur->right) q.push(cur->right); // enqueue right
		q.pop();
	}
	cout << endl;
}

// PURPOSE: Prints tree nodes using preorder traversal
void preorder_traversal(BinaryTreeNode* T) {
	if (!T) return;
	cout << T->data << " "; // visit the current node
	if (T->left) preorder_traversal(T->left); // enqueue left
	if (T->right) preorder_traversal(T->right); // enqueue right
}

// PURPOSE: Removes tree nodes using postorder traversal
void postorder_cleanup(BinaryTreeNode* T) {
	if (!T) return;	
	if (T->left) postorder_cleanup(T->left); // enqueue left
	if (T->right) postorder_cleanup(T->right); // enqueue right
	delete T;
}

// PURPOSE: Helper function that creates a minimal-height binary tree
BinaryTreeNode* create_minimal_height_BT(int A[], int first, int last) {    
    if (last < first) return NULL; // the range is empty, so terminate
    
    int middle = (first + last) / 2; // compute the middle point in the array
    BinaryTreeNode* newNode = new BinaryTreeNode(A[middle]);
    newNode->left = create_minimal_height_BT(A, first, middle - 1);
    newNode->right = create_minimal_height_BT(A, middle + 1, last);
    return newNode;
}

// PURPOSE: Creates a minimal-height binary tree from a given array
BinaryTreeNode* create_minimal_height_BT(int A[], int length) {
	return create_minimal_height_BT(A, 0, length - 1);
}

// PURPOSE: Runs demonstrative tests
void run_tests() {
	// initialize required variables
	int A[8] = {1,2,3,4,5,6,7,8};	
	
	// create a new binary tree
	BinaryTreeNode* T = create_minimal_height_BT(A, 8);	
	
	// perform inorder traversal using a stack
	inorder_using_stack(T);		
	
	// perform preorder traversal recursively
	cout << "Start Preorder Traversal:" << endl;
	preorder_traversal(T);
	cout << endl;	
	
	// perform breadth-first traversal using a queue
	print_BFT(T);
	
	// use postorder traversal to perform cleanup
	postorder_cleanup(T);
}

int main() {	
	run_tests();

	return 0;
}
