#ifndef DRONES_MANAGER_HPP
#define DRONES_MANAGER_HPP
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @Purpose Drones Manager class is a doubly linked list data structure that stores an Drone Record instance.
 */

class DronesManager{

protected:
    /**
     * @Purpose Drone Record stores information about a drone. 
     * The object will be stored in a DronesManager
     */
    struct DroneRecord{
        //CONSTRUCTORS:

        /**
         * @brief Default/Empty Constructor for a new Drone Record object. 
         */
        DroneRecord() : prev(NULL), next(NULL), droneID(0), range(0), yearBought(0) {}
        /**
         * @brief Single Parameter Constructor for a new Drone Record object
         * @param newDroneID 
         */
        DroneRecord(unsigned int newDroneID) : prev(NULL), next(NULL), droneID(newDroneID), range(0), yearBought(0) {}
        /**
         * @brief Parametric Constructor for a new Drone Record object.
         * @param newDroneID 
         * @param newRange 
         * @param newYearBought 
         * @param newDroneType 
         * @param newManufacturer 
         * @param newDescription 
         * @param newBatteryType 
         */
        DroneRecord(unsigned int newDroneID, 
                unsigned int newRange,
		    	unsigned int newYearBought, 
                string newDroneType,
			    string newManufacturer, 
                string newDescription, 
                string newBatteryType) :
				prev(NULL), 
                next(NULL), 
                droneID(newDroneID), 
                range(newRange), 
				yearBought(newYearBought), 
                droneType(newDroneType),
				manufacturer(newManufacturer), 
                description(newDescription), 
				batteryType(newBatteryType) {}
        
        // CLASS ELEMENTS:

        unsigned int droneID;
        unsigned int range;
        unsigned int yearBought;
        string droneType;
        string manufacturer;
        string description;
        string batteryType;
        DroneRecord* prev;
        DroneRecord* next;
    };
    /**
     * @brief Getter for any Drone Record in the  Drone Manager.
     * @param index 
     * @return DroneRecord* at index
     */
    DroneRecord* getDroneRecord(unsigned int index) const;
     
     //CLASS ELEMENTS:
     DroneRecord* first;
     DroneRecord* last;
     unsigned int size;

public:
    //CONSTRUCTORS:
    /**
     * @brief Defualt/Empty Constructor for a new Drones Manager object.
     */
    DronesManager();
    /**
     * @brief Destroy the Drones Manager object.
     */
    ~DronesManager();
    /**
     * @brief Comparison operator between two DroneRecord instances.
     * @param Drone_A 
     * @param Drone_B 
     * @return true if equal
     * @return false if not equal
     */
    friend bool operator ==(const DronesManager::DroneRecord& Drone_A, const DronesManager::DroneRecord& Drone_B );
    /**
     * @brief Setup DronesManagerTest as friend so tests have access to private variables
     */
    friend class DronesManagerTest;

    //ACCESSORS:

    /**
     * @brief Get the size object.
     * @return size of object
     */
    unsigned int get_size() const;
    /**
     * @brief Check if the list is empty
     * @return true if empty
     * @returns false if not empty
     */
    bool empty() const;
    /**
     * @brief Returns the value at the given index in the list.
     * @param index 
     * @return DroneRecord at index
     */
	DroneRecord select(unsigned int index) const;
	/**
	 * @brief Searches for the given value, and returns the index of this value if found.
     * @param DroneRecord data
	 * @return index the Drone is located
     **/
	unsigned int search(DroneRecord val) const;
    /**
     * @brief Prints all the elements in the list
     */
	void print() const;
	
	// MUTATORS:

    /**
     * @brief Inserts a value into the list at a given index.
     * (The list is not sorted reject if invalid)
     * @param val of Drone to be inserted
     * @param index to which the drone will be inserted
     * @return true if inserted
     * @return false if not inserted
     */
	bool insert(DroneRecord val, unsigned int index);
    /**
     * @brief Inserts a value at the beginning of the list.
     * @param val of Drone to be inserted
     * @return true if inserted in the front
     * @return false if not inserted in the front
     */
	bool insert_front(DroneRecord val);
    /**
     * @brief Inserts a value at the back of the list.
     * @param val of Drone to be inserted
     * @return true if inserted in the back
     */
	bool insert_back(DroneRecord val);
    /**
     * @brief Removes a value from the list at the given index
     * @param index of where the Drone is removed
     * @return true if removed at index 
     */
	bool remove(unsigned int index);
    /**
     * @brief Remove value from front of the list
     * @return true if first is removed
     * @return false if first is not removed
     */
	bool remove_front();
    /**
     * @brief Removes a value at the end of the list
     * @return true value is removed from back of the list
     * @return false value is not removed from back of the list
     */
	bool remove_back();
    /**
     * @brief Replaces value at the given index with the given value; the list is not sorted	
	 * (If the index is invalid, replacement is rejected)
     * @param index of where the Drone will be replaced
     * @param val of the Drone that will replace the existing
     * @return true if replaced
     * @return false if not replaced
     */
	bool replace(unsigned int index, DroneRecord val);    
    /**
     * @brief Reverse the linked list
     * @return true if reversed
     * @return false if not reversed
     */
	bool reverse_list();

};
#endif 