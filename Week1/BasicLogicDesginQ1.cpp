#include <iostream>

using namespace std;

/**
 * @breif Code Fragment that will
 * 1.Check if Integer > 5000
 * 2.Third digit from right is 3
 * 3.Second digit from right is even 
 * 4.Divisible by 10
 * */

bool checkNum(int target)
{
    bool isValid = true;
    int thridDigit = (target % 1000) - (target % 100);
    int secDigit = (target % 100) - (target % 10);
    int firstDigit = (target % 10);

    if(!(target > 5000 && (thridDigit == 300) && ((secDigit % 2) == 0) && (firstDigit == 0)))
    {
        cout << "not valid num" << endl;
        return false;
    }
    cout << "valid num" << endl;
    return isValid;
}

int main()
{
    checkNum(5380);
    checkNum(5381);
    checkNum(4000);
    checkNum(5480);

    return 0;
}