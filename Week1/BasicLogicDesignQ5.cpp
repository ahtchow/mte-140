#include <iostream>
using namespace std;


void swap(int my_array[] , int i , int j)
{
    int store = my_array[i];
    my_array[i] = my_array[j];
    my_array[j] = store;
}

int main()
{
    int my_array[10] = {13, 3 ,45 ,45 ,15 ,20 ,11 ,5 ,17 ,5};
    
    bool in_order = false;


    while(!in_order)
    {
        bool swapped = false;
        for (int i = 0; i < 10 - 1; i++)
        {
            if(my_array[i] > my_array[i+1])
            {
                swap(my_array, i , i+1);
                swapped = true;
            }
        }
        if(!swapped)
        {
            in_order = true;
        }

    }

    for(int i; i <10 ; i++)
    {
        cout << my_array[i] << endl;
    }

    return 0;


}