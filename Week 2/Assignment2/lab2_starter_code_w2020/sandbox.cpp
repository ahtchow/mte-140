#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    struct DroneRecord{
        //CONSTRUCTORS:

        /**
         * @brief Default/Empty Constructor for a new Drone Record object. 
         */
        DroneRecord() : prev(NULL), next(NULL), droneID(0), range(0), yearBought(0) {}
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

    int main(){
        int size = 0;
        for(int i = 0 ; i <1 ; i++){
            cout <<"hi" <<endl;
        }
    }


    /**
     * 1. No Capacity
     * 2. Can we assume no cycle
     * 3. Can we assume if first == null, then size == 0
     */