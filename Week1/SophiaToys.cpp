#include <iostream>
#include <vector>
using namespace std;

class Toy
{
    string shape;
    string color;
    bool doesSqueek;

public:

    Toy(){};

    Toy(string animalShape, string colorModel, bool SqueekOption): 
        shape(animalShape), color(colorModel), doesSqueek(SqueekOption){};

    string getShape()
    {
        return shape;
    }    

    string getColor()
    {
        return color;
    }
    
    bool tellifSqueks()
    {
        return doesSqueek;
    }

    bool operator ==(Toy t1)
    {
        bool isEqual = true;
        isEqual = isEqual && (shape == t1.getShape());
        isEqual = isEqual && (color == t1.getColor());
        isEqual = isEqual && (doesSqueek == t1.tellifSqueks());
        return isEqual; 
    }
};

class ToyCollection
{
    vector<Toy>collection;

public:

    int size()
    {
        return collection.size();
    }

    void insert_toy(Toy& toy_info)
    {
        collection.push_back(toy_info);
    }

    bool is_duplicate(Toy& toy_info)
    {
        for(vector<Toy>::iterator it = collection.begin(); it != collection.end(); it++)
        {
            if(*it == toy_info)
            {
                return true;
            }
        }
        return false;
    }

    bool remove_toys(Toy& toy_info)
    {
        bool removedSomething = false;
        for(int i = 0; i < collection.size(); i++)
        {
            if(collection[i] == toy_info)
            {
                swap(collection[i], collection[collection.size() -1] );
                collection.pop_back;
                removedSomething = true;
                --i;
            }
        }
        if(removedSomething)
        {
            return true;
        }
        return false;
    }
    
    int count_duplicates()
    {
        int duplicateCount = 0;
        for(int i = 0; i < collection.size(); i++)
        {
            if(is_duplicate(collection[i]))
            duplicateCount++;
        }
        return duplicateCount/2;
    }

};





int main(){

}