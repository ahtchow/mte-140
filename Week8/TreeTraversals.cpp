#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct BinaryTreeNode{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int DATA): data(DATA), left(NULL), right(NULL){};
};

void preOrderUsingStack(BinaryTreeNode* T){
    stack<BinaryTreeNode*> s;
    s.push(T);
    cout << "Start Inorder Traversal:" << endl;	
    while(!s.empty()){
        BinaryTreeNode* curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
}

void inOrderUsingStack(BinaryTreeNode* T){
    stack<BinaryTreeNode*> s;
    BinaryTreeNode* curr = T;
    while(curr||!s.empty()){ //push left until 
        if(curr){
            s.push(curr);
            curr = curr->left;
        }
        else{ //pop i fthe left child is null
            curr = s.top();
            s.pop();
            cout << curr->data << " ";//print or other processing
            curr = curr ->right; //Push child right
        }
    }
}

void print_BFT(BinaryTreeNode* T){
    queue<BinaryTreeNode*> q;
    if(T)
        q.push(T);
    cout << "Start Breadth-First Traversal:" << endl;
    while(!q.empty()){
        BinaryTreeNode* cur = q.front();
        cout << cur->data << " "; // visit the current node
		if (cur->left) q.push(cur->left); // enqueue left
		if (cur->right) q.push(cur->right); // enqueue right
        q.pop();
    }
    cout << endl;
}

void preorder_traversal(BinaryTreeNode* T){
    if(!T) return;
    cout << T->data;
    if(T->left)
        preorder_traversal(T->left);
    if(T->right)
        preorder_traversal(T->right);
}

void postorder_traversal(BinaryTreeNode* T){
    if(!T) return;
    if(T->left)
        postorder_traversal(T->left);
    if(T->right)
        postorder_traversal(T->right);
    cout << T->data;
}

// PURPOSE: Removes tree nodes using postorder traversal
void postorder_cleanup(BinaryTreeNode* T){
    if(!T) return;
    if(T->left)
        postorder_traversal(T->left);
    if(T->right)
        postorder_traversal(T->right);
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
	inOrderUsingStack(T);		
	
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
