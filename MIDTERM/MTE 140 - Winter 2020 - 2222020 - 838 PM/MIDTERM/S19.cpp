#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Generate unsorted list of values in range [1,1000] inclusive w/duplicates
 * Read through the list and extract min and max values
 * Look for ith missing number from the range of min to max, if no value return -1
 * If you guess correctly three times
 * 
 */

int find_ith_missing_value(vector<int> values, unsigned int missing_index){
    if(missing_index < 0)
        return -1;
    
    if(values.size() <= 1)
        return -1;

    int counter[1000] = {0}; // Will not use 0th index
    int min = 1000;
    int max = 0;
    for(int i = 0 ; i < values.size() ; i++){
        ++counter[values[i]-1];
        if(min > values[i])
            min = values[i];
        if(max < values[i])
            max = values[i];
    }
    
    int count = 0;
    for(int j = min; j < max-1; j++){
        if(counter[j] == 0){
            if(count == missing_index)
                return (j+1);
            ++count;
        }
        
    }   
    return -1;
}

int main(){
    vector<int> vec;
    vec.push_back(14);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(6);

    cout << find_ith_missing_value(vec, 5) << endl;

};