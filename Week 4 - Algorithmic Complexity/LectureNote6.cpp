#include <iostream>

using namespace std;

int SequentialSearch(int A[], int size, int K){
    for(int i = 0; i < size ; i++){
        if(A[i] == K){
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[] , int L , int R , int K){
    //must be already sorted to work
    int mid =( L + R )/2;

    if ( R < L){
        return -1;
    }

    else if (A[mid] == K){
        return mid;
    }

    else if (A[mid] < K){
        return BinarySearch(A , mid+1, R, K);
    }

    else {
        return BinarySearch(A, L, mid - 1, K );
    }
}


int main(){
    int size = 11;
    int A[11] = {0,1,2,3,4,5,6,7,8,9,10};

    int a = SequentialSearch(A, size , 8 );
    cout << a << endl;

    int b = BinarySearch(A, 0, size , 8 );
    cout << b << endl;

    /**
     * Which is faster?
     *      Small inputs - both finish in negligable amount of time
     *      As input grows, so does the time it takes for each algorithm
     *      Growth rate determines which performs faster
     * 
     * To determine the growth, consider worst-case scenarios
     *      1. Assign it to its own caregory
     *      2. Use Big-O notaion to express performance info
     *      
     *      Therefore:
     *          1. Sequential seach - O(n) 
     *                      Worst Case: n indexes to find K
     *          2. BinarySearch as O(log(n))
     *                      Worst Case: log(n) halvings (base 2) to find K
     *                                  
     *                          [0,1,2,3,4,5,6,7,8,9,10]
     *                                           /  \
     *                          [0,1,2,3,4]     [6,7,8,9,10]     exit if 5
     *                                  / \                  / \
     *                         [0,1]   [3,4]      [6,7]  [9,10]     exit if 2,8
     *                          / \         / \             / \        / \      
     *                      [0]  [1]  [3] [4]    [6] [7] [8][9]  
     *       */



    return 0;

}