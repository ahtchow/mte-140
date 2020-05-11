#include <iostream>
#include <vector>
using namespace std;

class Test
{
    private:
        string name;
    
    public:
        Test(string NAME): name(NAME){};
        virtual void print()
        {
            cout << name << endl;
        }
};

class Boo : public Test{
    private:
        string pokemon;
    public:
        Boo(string pokemoN , Test a): pokemon(pokemoN), Test(a){};
        virtual void print()
        {
            cout << pokemon << endl;
        }
        friend void PRINT(Boo a)
        {
        cout << a.pokemon << endl;
        }

};


int main()
{
    vector<double>my_vector = {1,2,3,4};
    Test hi("adrian");
    Test to(hi);
    Boo bebe("hi", hi);
    bebe.print();
    hi.print();
    PRINT(bebe);
    vector<Test> array = {hi, to}; 
    int p[5] = {0,1,2,3,4};
    char a = 97;
    cout << a << endl;
    if(1+1 == 3)
    {
        cout << a <<endl;
    }
    else 
    {
        cout << p[1] <<endl;
    }
int count = 0;
do{
    count += 2;
    count -= 1;
    cout << count << endl;
} while(count <10);

}