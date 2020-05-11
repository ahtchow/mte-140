#include <vector>
#include <iostream>

using namespace std;

class FavItem{

private:
    unsigned int itemID;
    string itemName;
    int ratings; // 1-5 stars
    string category;
    string notes;
    FavItem* next = NULL;
    FavItem* prev = NULL;
    friend class FavsManager;
public:
    FavItem();
    FavItem(unsigned int itemID);
    FavItem(unsigned int itemID, string itemName, int rating, string category, string notes);
    bool operator== (const FavItem & item) const;

};

class FavsManager{

private:
    FavItem * first = NULL;
    FavItem * last = NULL;
    int size;
public:
    FavsManager();
    void push_back(FavItem& new_item){
        if(new_item == NULL){
            return;
        }
        if(size == 0){
            first = last = &new_item;
            ++size;
            return;
        }
        else{
            FavItem* runner = first;
            for(int i = 0; i < size-1; i++){
                if(*runner == new_item) // Check duplicates
                    return;
                runner = runner->next;
            }
            last->next = &new_item;
            new_item.prev = last;
            last = &new_item;
            ++size;
        }
    };
    void pop_nth_from_end(unsigned int index){
        if(index == 0 || index > size)
            return; //Invalid Index
        if(!first)
            return; //Empty Lists
        
        FavItem* runner = last;
        if(!last->prev){ // One item
            first = NULL;
            last = NULL;
            delete runner;
            runner = NULL;
            --size;
            return;
        }

        if(size == index){
            //At front
            runner = first;
            first = runner->next;
            first->prev = NULL;
            delete runner;
            runner = NULL;
            --size;
            return;
        }

        int count = 1;
        while(index != count){
            runner = runner->prev;
            ++count;
        }

 `       else { //Standard index w/ prev and next
            runner->prev->next = runner->next;
            runner->next->prev = runner->prev;
            delete runner;
            runner = NULL;
            --size;
            return;
        }

    };

    void print();
    int getSize() const;
    void reverseList();
    FavItem getItem(unsigned int index)const;
    void insert(FavItem &item, unsigned int index);

};