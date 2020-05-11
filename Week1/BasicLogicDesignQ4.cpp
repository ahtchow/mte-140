#include <iostream> 
using namespace std;

int main()
{
    int size;
    int a[10] = {};
    cout << "Enter an integer" << endl;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        int entry;
        cin >> entry;
        a[i] = entry + 2;
    }

    for(int i = size - 1; i >= 0; i = i - 1)
    {
        cout << a[i] << endl;
    }


}