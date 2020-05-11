#include "ahtchow_lab2_drone_manager.hpp"

DronesManager::DronesManager() {

	first = NULL;
	last = NULL;
	size = 0;

}

DronesManager::~DronesManager() {

	//Case 1 & 2: Single Node/ More than one Node
    if(first){

        DroneRecord* runner = first;

        while(first){
            delete runner;
            first = first->next;
            runner = first;        
        }

        runner = NULL;
        first = NULL;
        last = NULL;
        size = 0;

	}
     // Case 3: No node, in that case nothing is required to be deleted.

}

bool operator==(const DronesManager::DroneRecord& Drone_A, const DronesManager::DroneRecord& Drone_B) {
    
	bool is_equal = true;
    is_equal = is_equal && (Drone_A.droneID == Drone_B.droneID);

    return is_equal;

}

unsigned int DronesManager::get_size() const {

	return size;

}

bool DronesManager::empty() const {

	return !size;
    
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {

	if(index >= size ){
		cout << "Error: Index size out of range." << endl;
		return DroneRecord();
	}

    DroneRecord* runner = first;

    for(int i = 0; i < index; i++){
            runner = runner->next;
        }

    return *runner;

}

unsigned int DronesManager::search(DroneRecord value) const {

    if(!first){
        cout << "Error: No Drones Stored" << endl;
        return size;
    }

    DroneRecord* runner = first;
        
        for(int index = 0; index < size; index++){
            if(*runner == value){
                return index;
            }
            runner = runner->next;
        }

    cout << "Error: Could not find the Drone in the Manager" << endl;
    return size;  // Returning the size is the most appropriate [Out of Range].

}

void DronesManager::print() const {

    cout << "(";
	DroneRecord* runner = first; 

	while (runner) {
		cout << "["  
                << runner->droneID << " , "
                << runner->range << " , "
                << runner->yearBought << " , "
                << runner->droneType << " , "
                << runner->manufacturer << " , "
                << runner->description << " , "
                << runner->batteryType << "]";
		
        runner = runner->next;

		if (runner){
			cout << "->";
        }    
	}	

	cout << " )"<<  endl; 

}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
    
    DroneRecord* runner = new DroneRecord(select(index));
    DroneRecord* new_Drone = new DroneRecord(value);

    if(index > size){
        cout << "Error: Attempt to insert out of range" << endl;
        return false;
    }

    else if(index == 0){
        insert_front(value);
        return true;
    }

    else if(index == size){
        insert_back(value);
        return true;
    }

    runner->prev->next = new_Drone;
    new_Drone->prev = runner->prev;
    runner->prev = new_Drone;
    new_Drone->next = runner;
    size++;
	return true;

}

bool DronesManager::insert_front(DroneRecord value) {
    
    DroneRecord* new_Drone = new DroneRecord(value);
    size++;

    if (!first){
        first = new_Drone;
        last = new_Drone; 
    }

    else{
        first->prev = new_Drone; 
        new_Drone->next = first;
        first = new_Drone;
    }

    return true;

}

bool DronesManager::insert_back(DroneRecord value) {

    DroneRecord* new_Drone = new DroneRecord(value);
    size++;

    if(!first){
        first = new_Drone;
        last = new_Drone; 
    }

    else{
        last->next = new_Drone;
        new_Drone->prev = last;
        last = new_Drone;
    }

    return true;

}

bool DronesManager::remove(unsigned int index) {
    
    if(size == 0){
        cout << "Error: Can not remove list with no Drones." << endl;
        return false;
    }

    else if(index >= size){
        cout << "Error: Index out of Range" << endl;
        return false;
    }

    else if(index == 0){
        remove_front();
        return true;
    }

    else if(index  == size -1){
        remove_back();
        return true;
    }

    DroneRecord* runner = new DroneRecord(select(index));
    runner->prev->next = runner->next;
    runner->next->prev = runner->prev; 
    delete runner;
    runner = NULL;
    size--;
	return true;

}

bool DronesManager::remove_front() {

    if(!first){
        cout << "Error: Cannot remove empty list" << endl;
        return false;
    }

    else if(size == 1){
        delete first;
        last = NULL;
        first = NULL;
        size--;
        return true;
    }

    else{
        first = first->next;
        delete first->prev;
        first->prev = NULL;
        size--;
        return true;
    } 
    
}

bool DronesManager::remove_back() {

    if(!first){
        cout << "Error: Cannot remove empty list" << endl;
       return false;
    }

    else  if(size == 1){
        delete last;
        last = NULL;
        first = NULL;
        size--;
        return true;
    }

    else{
        last = last->prev;
        delete last->next;
        last->next = NULL;
        size--;
        return true;
    }

}

bool DronesManager::replace(unsigned int index, DroneRecord value) {

    DroneRecord* new_Drone =  new DroneRecord(value);
    DroneRecord* runner = new DroneRecord(select(index));

    if(!first){
        cout << "Error: List is empty, can not replace." << endl;
        return false;
    }

    else if(index >= size){
        cout << "Error: Index out of range." << endl;
        return false;
    }

    else if(!first->next){
        //Single Node
        delete first;
        first = new_Drone;
        last = new_Drone;
        return true;
    }

    else{
        if(!runner->next){
            //Case: Replacing last node
            remove_back();
            insert_back(value);
            return true;
        }

        runner->next->prev = new_Drone;
        runner->prev->next = new_Drone;
        new_Drone-> next = runner->next;
        new_Drone->prev = runner->prev;
        delete runner;
        runner = NULL;
        return true;

    }

}

bool DronesManager::reverse_list() {

    if(!first){
        cout << "Error: Empty list, cannot reverse." << endl;
        return false;
    }

    if(!first->next){
        cout << "Error: List with one item can not be reversed" << endl;
        return false;
    }

    DroneRecord* curr = first;
    first = last;
    DroneRecord* runner;

    while(curr){
        runner = curr->prev;
        curr->prev = curr->next;
        curr ->next = runner;
        curr = curr->prev;
    }
    runner = new DroneRecord(select(size-1));
    last = runner;

	return true;

};
