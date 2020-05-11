#include <iostream>
using namespace std;

int findLargestDist( int array[], int size){
    if(size <= 0)
        return 0;
    if(size <= 2)
        return array[0];
    if(array[0] < 0)
        return 0;

    int mid_index = (size/2) -1;
    if((array[mid_index] - array[0] ) > (array[size-1]-array[mid_index+1]))
        return array[mid_index];
    else  
        return array[mid_index+1];

}

int main(){
    int array[6] = {1,3,11,16,21,35};
    cout << findLargestDist(array, 6);
}