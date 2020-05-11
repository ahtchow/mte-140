#include <iostream>

using namespace std;

/**
 * @breif Code Fragment that will
 * 
 * 
 * */


int main()
{
    int entry = 0;
    bool continue_loop = true;
    while(continue_loop)
    {
        cin >> entry;
        continue_loop = (entry < 1 || entry > 10);
    }

    cout << entry << endl;
    return 0;

}