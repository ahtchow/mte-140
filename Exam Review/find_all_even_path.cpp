#include <iostream>
#include  <vector>
#include <queue>
#include<string>

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

using namespace std;

class BinaryTreeNode{

    int val;
    BinaryTreeNode * left;
    BinaryTreeNode * right;

public:

    /**
     * @brief Construct a new Binary Tree Node object
     * @param new_val 
     */
    BinaryTreeNode(int new_val): val(new_val), left(NULL), right(NULL){};
    
    /**
     * @brief Print value 
     */
    void print(){ cout << val << " "; }

    friend class BinaryTree;
    friend class BinaryTreeTest;

};

class BinaryTree{

    BinaryTreeNode * root;
    int size;

public:

    /**
     * @brief Construct a new Binary Tree object
     */
    BinaryTree(): root(NULL), size(0){};

    /**
     * @brief Destroy the Binary Tree object
     */
    ~BinaryTree() { clean_up(root); size = 0; root = NULL; }
    
    /**
     * @brief Clean up function for destructor
     * @param T
     */
    void clean_up(BinaryTreeNode* T) {
		if (T == NULL) return;
		clean_up(T->left);
		clean_up(T->right);
		delete T;
	}

    /**
     * @brief Breadth-First Traversal
     * @param T 
     */
    void BreadthFirstTraversal(BinaryTreeNode* T) {
		if (T == NULL) return;

		queue<BinaryTreeNode*> bft_queue;
		bft_queue.push(T);

		while(!bft_queue.empty()) {
			BinaryTreeNode* cur = bft_queue.front();
			bft_queue.pop();

			cur->print();
			if (cur->left) bft_queue.push(cur->left);
			if (cur->right) bft_queue.push(cur->right);
		}
	}

    void BreadthFirstTraversal() { BreadthFirstTraversal(root); }

    void insert(BinaryTreeNode * T) { 

        if(!root){
            root = T;
            ++size;
            return;
        }

        queue<BinaryTreeNode* > q; 
        q.push(root); 
    
        // Do level order traversal until we find 
        // an empty place.  
        while (!q.empty()) { 
            BinaryTreeNode* temp = q.front(); 
            if(temp->val == T->val)
                return;
            q.pop(); 
    
            if (!temp->left) { 
                temp->left = T;
                break; 
            }
             else
                q.push(temp->left); 
    
            if (!temp->right) { 
                temp->right = T; 
                break; 
            } 
            else
                q.push(temp->right); 
        } 
        ++size;
    } 

    //Assignment Functions
    void find_and_print_sum_of_nodes(
            BinaryTreeNode * T,
            int desired_sum,
            int cur_sum,
            string buffer){
            
        //exit if T is NULL
        if(!T) return;

        //update the ongoing sum with the current value for T
        int  new_sum = cur_sum + T->val;

        //update the current string path;
        string new_buffer = buffer + " " + to_string(T->val);

        //if the desired sum is found, print the corresponding path
        if(new_sum == desired_sum)
            cout << new_buffer << endl;

        //continue down the left subtree
        find_and_print_sum_of_nodes(T->left, desired_sum, new_sum, new_buffer);
        
        //continue down the right subree
        find_and_print_sum_of_nodes(T->right, desired_sum, new_sum, new_buffer);

        //restart from left subtree if buffer = ""
        if(buffer == "")
            find_and_print_sum_of_nodes(T->left, desired_sum, 0, "");

        //restart from right subtree if buffer = ""
        if(buffer == "")
            find_and_print_sum_of_nodes(T->right, desired_sum, 0, "");

    }

    void paths_with_even_nodes(BinaryTreeNode * T, string buffer){
        if(!T)return;

        if(T->val % 2 == 0 ){
            string new_buffer = buffer + "(" + to_string(T->val) + ")";
            int count = 0;

            if(T->left){
                if(T->left->val % 2 == 0){
                    ++count;
                    paths_with_even_nodes(T->left, new_buffer);
                }
            }

            if(T->right){
                if(T->right->val % 2 == 0){
                    ++count;
                    paths_with_even_nodes(T->right, new_buffer);
                }
            }

            if((!T->right && !T->left) || count == 0) 
                cout << new_buffer << endl; 
        }
        
        paths_with_even_nodes(T->left, "");
        paths_with_even_nodes(T->right, "");
    };


    int find_max_sum_of_nodes(BinaryTreeNode * T,  int & temp_max_sum){
        
        // exit if T is NULL
        if(!T) return 0;

        //derive the maximum sum for the left subtree
        int left_sum = find_max_sum_of_nodes(T->left, temp_max_sum);
        
        //derive the maximum sum for the right subtree
        int right_sum = find_max_sum_of_nodes(T->right, temp_max_sum);

        int max1 = max(T->val, T->val+ left_sum);
        max1 = max(max1, T->val+ right_sum);
        //find max
        int max2 = max(max1, T->val + left_sum + right_sum);

        //update temp_max_sum
        temp_max_sum = max(temp_max_sum, max2);

        return max1;
    }

    int find_max_sum_of_nodes(BinaryTreeNode * T){

        if (root == NULL) return 0; 
        int temp_max_sum = INT8_MIN;
        find_max_sum_of_nodes(T, temp_max_sum);
        return temp_max_sum;

    }



    friend class BinaryTreeTest;
    
};

class BinaryTreeTest {
public:


    /**
     * @brief Test for the function find_and_print_sum_nodes
     */
    void test_find_and_print_sum_nodes(){
        
        cout << endl << "TESTING: FIND AND PRINT SUM NODES" << endl;
        cout  << "=================================" << endl;
        test1_find_and_print_sum_nodes();
        test2_find_and_print_sum_nodes();
        test3_find_and_print_sum_nodes();
    }

    void test1_find_and_print_sum_nodes(){
        string expected_tree = "5 3 1 -1 8 11 18  6";  //BFT
        cout <<  endl << "Test Tree 1 -> BFT: " << expected_tree << endl << endl;

        BinaryTree test_tree;
        test_tree.insert(new BinaryTreeNode(5));
        test_tree.insert(new BinaryTreeNode(3));
        test_tree.insert(new BinaryTreeNode(1));
        test_tree.insert(new BinaryTreeNode(-1));
        test_tree.insert(new BinaryTreeNode(8));
        test_tree.insert(new BinaryTreeNode(11));
        test_tree.insert(new BinaryTreeNode(18));
        test_tree.insert(new BinaryTreeNode(6));

        string expected_result = "[3,8] , [11] ";
        cout <<  endl << "Expected Results: " << expected_result << endl << "Results: " << endl;
        test_tree.find_and_print_sum_of_nodes(test_tree.root, 11, 0, "");
        
        string expected_result2= "[5,3] , [3, -1, 6] , [8] ";
        cout <<  endl << "Expected Results: " << expected_result2 << endl << "Results: " << endl;
        test_tree.find_and_print_sum_of_nodes(test_tree.root, 8, 0, "");

        string expected_result3= "[5,1] , [6] ";
        cout <<  endl << "Expected Results: " << expected_result3 << endl << "Results: " << endl;
        test_tree.find_and_print_sum_of_nodes(test_tree.root, 6, 0, "");
    }

    void test2_find_and_print_sum_nodes(){
        string expected_tree = "-6 -4 -3 -5 -10 -11 -18  -1 -7";  //BFT
        cout <<  endl << "Test Tree 2 -> BFT: " << expected_tree << endl << endl;

        BinaryTree test_tree;
        test_tree.insert(new BinaryTreeNode(-6));
        test_tree.insert(new BinaryTreeNode(-4));
        test_tree.insert(new BinaryTreeNode(-3));
        test_tree.insert(new BinaryTreeNode(-5));
        test_tree.insert(new BinaryTreeNode(-10));
        test_tree.insert(new BinaryTreeNode(-11));
        test_tree.insert(new BinaryTreeNode(-18));
        test_tree.insert(new BinaryTreeNode(-1));
        test_tree.insert(new BinaryTreeNode(-7));

        string expected_result = "[-6,-4] , [-4,-5,-1] , [-10] ";
        cout <<  endl << "Expected Results: " << expected_result << endl << "Results: " << endl;
        test_tree.find_and_print_sum_of_nodes(test_tree.root, -10, 0, "");
        
        string expected_result2= "[-4,-10] , [-3,-11] ";
        cout <<  endl << "Expected Results: " << expected_result2 << endl << "Results: " << endl;
        test_tree.find_and_print_sum_of_nodes(test_tree.root, -14, 0, "");

        string expected_result3= "[-6,-3] , [-4, -5] ";
        cout <<  endl << "Expected Results: " << expected_result3 << endl << "Results: " << endl;
        test_tree.find_and_print_sum_of_nodes(test_tree.root, -9, 0, "");
    }

    void test3_find_and_print_sum_nodes(){
        string expected_tree = "1 2 3 4 5 6 7 8 9 10 11 12";  //BFT
        cout <<  endl << "Test Tree 3 -> BFT: " << expected_tree << endl << endl;

        BinaryTree test_tree;
        test_tree.insert(new BinaryTreeNode(1));
        test_tree.insert(new BinaryTreeNode(2));
        test_tree.insert(new BinaryTreeNode(3));
        test_tree.insert(new BinaryTreeNode(4));
        test_tree.insert(new BinaryTreeNode(5));
        test_tree.insert(new BinaryTreeNode(6));
        test_tree.insert(new BinaryTreeNode(7));
        test_tree.insert(new BinaryTreeNode(8));
        test_tree.insert(new BinaryTreeNode(9));
        test_tree.insert(new BinaryTreeNode(10));
        test_tree.insert(new BinaryTreeNode(11));
        test_tree.insert(new BinaryTreeNode(12));

        string expected_result = "[1,2,5,10] , [2,5,11] , [6,12] ";
        cout <<  endl << "Expected Results: " << expected_result << endl << "Results: " << endl;
        test_tree.find_and_print_sum_of_nodes(test_tree.root, 18, 0, "");
        
        string expected_result2= "[4,8] , [12] ";
        cout <<  endl << "Expected Results: " << expected_result2 << endl << "Results: " << endl;
        test_tree.find_and_print_sum_of_nodes(test_tree.root, 12, 0, "");

        string expected_result3= "[1,2,4,9] , [5,11] ";
        cout <<  endl << "Expected Results: " << expected_result3 << endl << "Results: " << endl;
        test_tree.find_and_print_sum_of_nodes(test_tree.root, 16, 0, "");
    }

    /**
     * @brief Test for the function test_find_max_sum_of_nodes
     */
    void test_find_max_sum_of_nodes(){
        
        cout << endl << "TESTING: FIND MAX SUM OF NODES ACROSS SUBTREES" << endl;
        cout  << "=================================================" << endl;
        
        if(test1_find_max_sum_of_nodes())
            cout << "Test 1: PASSED" << endl;
        else
            cout << "Test 1: FAILED" << endl;

        if(test2_find_max_sum_of_nodes())
            cout << "Test 2: PASSED" << endl;
        else
            cout << "Test 2: FAILED" << endl;

        if(test3_find_max_sum_of_nodes())
            cout << "Test 3: PASSED" << endl;
        else
            cout << "Test 3: FAILED" << endl;

    }

    bool test1_find_max_sum_of_nodes(){

        string expected_tree = "5 6 -15 15 10 -12 9";  //BFT
        cout <<  endl << "Test Tree 1 -> BFT: " << expected_tree << endl << endl;

        BinaryTree test_tree;
        test_tree.insert(new BinaryTreeNode(5));
        test_tree.insert(new BinaryTreeNode(6));
        test_tree.insert(new BinaryTreeNode(-15));
        test_tree.insert(new BinaryTreeNode(15));
        test_tree.insert(new BinaryTreeNode(10));
        test_tree.insert(new BinaryTreeNode(-12));
        test_tree.insert(new BinaryTreeNode(9));
        cout << "ANSWER: 31" << endl;
        ASSERT_TRUE(test_tree.find_max_sum_of_nodes(test_tree.root) == 31)
        return true;
    }

    bool test2_find_max_sum_of_nodes(){

        string expected_tree = "6 10 4 -5 -6 4 7";  
        cout <<  endl << "Test Tree 2 -> BFT: " << expected_tree << endl << endl;

        BinaryTree test_tree;
        test_tree.root = new BinaryTreeNode(6);
        BinaryTreeNode * a = new BinaryTreeNode(-6);
        a->right = new BinaryTreeNode(7);
        BinaryTreeNode * b = new BinaryTreeNode(-5);
        b->right = new BinaryTreeNode(4);
        BinaryTreeNode * c = new BinaryTreeNode(10);
        c->right = b;
        BinaryTreeNode * d = new BinaryTreeNode(4);
        d->right = a;
        test_tree.root ->right = d;
        test_tree.root ->left = c;

        cout << "ANSWER: 21" << endl;
        ASSERT_TRUE(test_tree.find_max_sum_of_nodes(test_tree.root) == 21)
        return true;
    }

     bool test3_find_max_sum_of_nodes(){

        string expected_tree = "1 -2 3 4 5 -6 2";  //BFT
        cout <<  endl << "Test Tree 3 -> BFT: " << expected_tree << endl << endl;

        BinaryTree test_tree;
        test_tree.insert(new BinaryTreeNode(1));
        test_tree.insert(new BinaryTreeNode(-2));
        test_tree.insert(new BinaryTreeNode(3));
        test_tree.insert(new BinaryTreeNode(4));
        test_tree.insert(new BinaryTreeNode(5));
        test_tree.insert(new BinaryTreeNode(-6));
        test_tree.insert(new BinaryTreeNode(2));
        cout << "ANSWER: 9" << endl;
        ASSERT_TRUE(test_tree.find_max_sum_of_nodes(test_tree.root) == 9)
        return true;
    }

    void test_exam(){

        BinaryTree test_tree;
        test_tree.insert(new BinaryTreeNode(-1));
        test_tree.insert(new BinaryTreeNode(-5));
        test_tree.insert(new BinaryTreeNode(-4));
        test_tree.insert(new BinaryTreeNode(-2));
        test_tree.insert(new BinaryTreeNode(-3));
        test_tree.insert(new BinaryTreeNode(-2));
        test_tree.insert(new BinaryTreeNode(-6));

        test_tree.paths_with_even_nodes(test_tree.root,"");
    }


};

int main(){
    
    BinaryTreeTest test_tree;
    test_tree.test_exam();
    return 0;

}
