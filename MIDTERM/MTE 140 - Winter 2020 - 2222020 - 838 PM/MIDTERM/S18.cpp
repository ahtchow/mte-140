#include <iostream>
using namespace std;

/**
 * @brief Print all equiillibrium indices for the array 
 * 1. If array is empty can not contain valid indices
 * 2. If no equillibrium nothing is printed
 * 3. If all [0s] print all vallues
 */

void find_equillibrium(int *A, int size_A){
    if(!A){
        return;
    }
    if(size_A <= 0){
        return;
    }

    int right_sum = 0;
    int left_sum = 0;
    for(int i = 0; i < size_A; i++){
        right_sum += A[i];
    }
    for(int j = 0; j < size_A; j++){
        right_sum -= A[j];
        if(right_sum == left_sum)
            cout << j << endl;
        left_sum += A[j];
    }
}

int main(){

    int A[5] = {-4, 2, 3, 4, -6};
    int B[5] = {-4, -2, 3, 4, -5};
    int C[5] = {0, 0, 0,0 ,0};
    int D[6] = {1,1,1,1,1,1};
 
    find_equillibrium(B, 5);



}