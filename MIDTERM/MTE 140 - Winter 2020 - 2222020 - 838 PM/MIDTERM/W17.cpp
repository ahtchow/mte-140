#include <iostream>
using namespace std;

/**
 * @brief Two unsorted arrays A and B
 * range [0,999] inclusive , no duplicates
 * 
 */

void find_reapeated_values( int *A, int size_A, int *B , int size_B){
    if(size_A <= 0 || size_B <= 0){
        cout << "Empty" << endl;
    }
    if(A==NULL || B==NULL)
        cout << "NULL" << endl;

    int A_temp[1000]= {};
    int B_temp[1000]= {};

    for(int i = 0; i < size_A; i++ ){
        A_temp[A[i]] = 1;
        if(A[i] >999 || A[i] <0 )
            return; 
    }
    for(int j = 0; j < size_B; j++){
        B_temp[B[j]] = 1;
        if(B[j] >999 || B[j] <0)
            return; 
    }
    int count = 0;
    for(int k = 0; k<1000; k++ ){
        if(B_temp[k] == 1 && A_temp[k] == 1  ){
            cout << k << endl;
            ++count;
        }    
    }
    cout << "total count: " << count << endl;
} 

int main(){
    int* A = new int[5];
    A[0] = 42;
    A[1] = 1;
    A[2] = 57;
    A[3] = 5;
    A[4] = 317;
    int* B = new int[6];
    B[0] = 5;
    B[1] = 57;
    B[2] = 11;
    B[3] = 111;
    B[4] = 256;
    B[5] = 317;

    find_reapeated_values(A, 5, B, 6);

}