//
// Created by Adrian Chow on 2020-01-08.
//

#include "vectors.h"
#include <vector>
#include <iostream>
#include <array>
/* WHY VECTORS
 * -Resizable through Execution and Addition
 *
 */
/*VECTOR SYNTAX
 *  vector<<type>> <identifier> -> Initialize
 *  <identifier>.push_back() -> Insert element at End
 *  <identifier>.pop_back()  -> Remove element at End
 *  <identifier>[<index>] -> Index value

 */

using namespace std;

int main()
{
//HOW TO INITIALIZE VECTORS

    //1. Empty Constructor


    vector<double> vec1;

    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    cout << vec1.size() << endl;

    for (int i = 0; i < vec1.size(); i++ )
        cout << "Q1 " << vec1[i] << endl;



    //2. Fill Constructor - Initialize all same values

    int n1 = 3;

    vector<double> vec2(n1,10.0); //(# of object, repeated value)
    for(int i = 0; i < vec2.size() ; i++)
        cout << vec2[i] << endl;

    cout << "Q2 " << vec2.size() <<endl;


    //3. Range Constructor -> Use another vector as reference , essentially copy another vector

    vector<double> vec3(vec1.begin(), vec1.end()); //(# of object, repeated value)
    cout << vec3.size() << " Size"<< endl;
    // vec1.begin(), vec1.end() are not values, these are tools for the constructor


    for( int i = 0 ; i < vec3.size(); i++)
        cout << "Q3 " << vec3[i] << endl;

    //4. Copy Constructor - Copy another vector

    vector<double> vec4(vec1);

    for( int i = 0 ; i < vec4.size(); i++)
        cout << "Q4 " << vec4[i] << endl;

    // 5. Copy Array

    int my_int[5] = {-11,21,-33,41,-53};
    vector<int> vec5(my_int, my_int + sizeof(my_int) / sizeof(int));

    for( int i = 0 ; i < vec5.size(); i++)
        cout << "Q5 " << vec5[i] << endl;

    //6. Vector Iterator

    vector<int> vec6;

    for (vector<int>::iterator my_it= vec5.begin(); my_it!= vec5.end(); ++ my_it)
        cout<< "Q6 " << *my_it<< endl; // access the value via my_itpointer


     //7. <Array> Container iterators
     // Can iterators be used on fixed size containers like <array>

     array<int,10> my_array = {-12, 14, 13, 11, 10}; //Set sized array
     cout << my_array.size() << endl;

     for(array<int,10>::iterator p = my_array.begin() ;  p != my_array.end(); ++p )
         cout << "Q7. " << *p << endl;

    //8. <Array> Container Range Constructor
    // Can iterators be used on fixed size containers like <array>


    vector<int>vec8(my_array.begin(), my_array.end());

    for(vector<int>::iterator p2 = vec8.begin() ;  p2 != vec8.end(); ++p2 )
        cout << "Q8 " << *p2 << endl;

    /* Vector Capacity vs.Vector Size:
         *  Vector Size: # of Elements currently inserted while the capacity is not filled
         *  Vector are automatically allocated extra space (i.e Thus push_back() can be called)
         *  A vector's capacity can be pre-allocated for efficiency improvement via vector reserve()
         *  Cannot insert values though
    */

    vector<int> vec9; //Capacity and size both at 0
    vec9.reserve(5000); // set CAPACITY to 5000 element , "Set Space"
    vec9.resize(50); // set SIZE to 50 element, "Set Number of Elements Allowed" vec9[0-49] = 0

    vec9[20] = 2; // Now you can assign individual sections

    cout << vec9[20] << endl;
    cout << "Vector Capacity: " << vec9.capacity() << endl;
    cout << "Vector Size: " << vec9.size() << endl;


    return 0;








}
