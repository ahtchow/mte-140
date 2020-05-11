#include <iostream>
using namespace std;

/** RECURSION as a Problem Solving Strategy
 *  A computing problem can be solved as smaller representation of itself.
 *  I.e Factorials , To compute 4! -> we compute 4x3x2x1
 *  we can also say 4! = 4 x 3! , which is a smaller version of itself.
 * 
 */

int Factorial( int n){
    
    if(n<= 1){
        return 1;
    }

    else{
        return (n * Factorial(n-1));
    }

}

/** DESIGNING RECURSIVE ALGORITHMS
 *  Requirements:
 *          1.  Smaller versions of the larger problem. [Recursive Case]
 *          2.  Endpoint(s). [Base Case]
 * 
 * @example Fibonacci Sequence Recursions
 *          1.  Recursive Case:  Fn = Fn-1 + Fn-2 for n>1   
 *          2.  Base Cases: Fo = 0 , F1 = 1 (Endpoints) 
 */

int Fibonacci(int n){

    if(n <= 0){
        return 0; 
    }

    else if(n == 1){
        return 1;
    }

    else{
        return (Fibonacci(n-1) + Fibonacci(n-2));
    }
}

/** SOMES ITERATIVE METHODS ARE BETTER THAN RECURSION
 *      For example: Print array
 */

void print_array_iterative(int my_array[] , int array_size){
    
    for (int i = 0 ; i < array_size; i++){
        cout << my_array[i] << " ";
    }

    cout << endl;

}

void print_array_recursion(int my_array[] , int array_size , int index){

    if (index == array_size -1){
        cout << my_array[index];
    }
    else{
        cout << my_array[index] << " ";
        return print_array_recursion( my_array , array_size , ++index);
    }

}

/** Overall: 
 *  1.  Always have a base case, e.g Eventually terminates
 *  2. Parameters approach base case with every iteration.
 *  3. Sometimes recursion is more complex than other methods
 *  4. Use trees or other methods to visualize call-backs
 *  5. Must contain Base-cases and Recursive Statements
 */

// Another Example: Design a recursive function to convert LOWER case strings to upper-case

void to_UpperCase( string& my_String, int index){

    //Base Case
    if (index == my_String.size()){
        return;
    }

    //Recursive Iteration
    if(my_String[index] >= 'a' && my_String[index] <= 'z'){
        my_String[index] = 'A' + (my_String[index] - 'a');
            return to_UpperCase(my_String, ++index);
    }

}

// Write a recursive function to check how many nodes are in a list

// int num_of_Nodes(Node* node){

//     //Recursive Element
//     if(node){
//         return (1+ num_of_Nodes(node->getNext()));
//     }

//     else{
//         return 0;
//     }
// }

int main(){

// Factorial Calculation
int Factorial_of = Factorial(0);
cout << Factorial_of << endl;

//Fibonacci Sequence
int Fibonacci_of = Fibonacci(10);
cout << Fibonacci_of << endl;

// Iterative vs Recursive Printing
int array[5] = {1,2,3,4,5};
print_array_iterative(array, 5);
print_array_recursion(array,5,0);

//Capitalizing Function
string test = "karenlee";
to_UpperCase(test , 0);
cout << endl  << test << endl;

return 0;


}