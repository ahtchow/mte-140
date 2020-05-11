#include <iostream>

using namespace std;

/**
 * @breif Code Fragment that will
 * iterate from 0,10000 (inclusive) using entry variable as iterator
 * will increment as step size of 3
 * if entry is divisible by 2 or 3 and 11 , then output value
 * after 5 outputs exits
 * */


int main()
{
    unsigned int valid_count = 0;
    bool contine_loop = true;

    for(int entry = 0; entry <= 10000; entry = entry + 3 )
    {
        bool is_valid_entry = true;
        is_valid_entry = is_valid_entry && (entry % 3 == 0); 
        is_valid_entry = is_valid_entry && (entry % 2 == 0);
        is_valid_entry = is_valid_entry && (entry % 11 == 0);

        if(is_valid_entry)
        {
            cout << entry << endl;
            valid_count++;
        }

        if(valid_count == 5){contine_loop = false;}   

        if(!contine_loop)
        {
            entry = 10001;
        }
    } 

    return 0;

}