#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "ahtchow_lab2_drone_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)

		//Can insert, remove starting with empty list
		DronesManager::DroneRecord empty_record;
		ASSERT_TRUE(manager.insert(empty_record, 0))
		ASSERT_TRUE(manager.get_size() == 1)

		ASSERT_TRUE(manager.remove(0))
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)

	    return true;
	}
	
	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		//Case 1: Empty DroneManager
		DronesManager manager_empty_insert;
		DronesManager::DroneRecord test_Drone;
		ASSERT_TRUE(manager_empty_insert.insert_front(test_Drone))
		ASSERT_TRUE(manager_empty_insert.insert_back(test_Drone))

		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))		

	    return true;
	}
	
	// TODO: Implement all of the test cases below
	
	// PURPOSE: select() and search() work properly
	bool test3() {
		DronesManager empty_manager;
		DronesManager* test3 = new DronesManager(empty_manager);
		DronesManager::DroneRecord test_Drone1(1, 1, 1, "a", "a","a", "a");
		DronesManager::DroneRecord test_Drone2(2, 2, 2, "b", "b","b", "b");
		DronesManager::DroneRecord test_Drone3(3, 3, 3, "c", "c","c", "c");
		DronesManager::DroneRecord test_Drone4(4, 4, 4, "d", "d","d", "d");
		DronesManager::DroneRecord test_Drone5(5, 5, 5, "e", "e","e", "e");

	//Test: search() 

		//Case 1: Empty search & select.
		// If empty, should return size for search() and empty DroneRecord for select()
		DronesManager::DroneRecord empty;
		ASSERT_TRUE(test3->search(test_Drone1) == test3->get_size() )
		ASSERT_TRUE(test3->select(0) == empty)
		ASSERT_TRUE(test3->select(2) == empty)

		//Case2: Normal search & select.
		test3->insert_back(test_Drone1);
		test3->insert_back(test_Drone2);
		test3->insert_back(test_Drone3);
		test3->insert_back(test_Drone4);
		test3->insert_back(test_Drone5);

		ASSERT_TRUE(test3->search(test_Drone1) == 0)
		ASSERT_TRUE(test3->search(test_Drone3) == 2)
		ASSERT_TRUE(test3->select(0) == test_Drone1)
		ASSERT_TRUE(test3->select(2) == test_Drone3)

		//Case 3: Out of index search and fail to select for not exisiting
		DronesManager::DroneRecord test_Drone6(6, 6, 6, "f", "f","f", "f");
		ASSERT_TRUE(test3->search(test_Drone6) == test3->get_size())
		ASSERT_TRUE(test3->select(7) == empty)
		ASSERT_TRUE(test3->select(100) == empty)

		delete test3;
		test3 = NULL;

	    return true;
	}
	
	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
		DronesManager empty;
		DronesManager* test4a = new DronesManager(empty);
		DronesManager* test4b = new DronesManager(empty);
		DronesManager::DroneRecord test_Drone1(1, 1, 1, "a", "a","a", "a");
		test4a->insert_back(test_Drone1);
		test4b->insert_back(test_Drone1);

		//Case: Remove front
		ASSERT_TRUE(test4a->remove_front())
		ASSERT_TRUE(test4a->get_size() == 0)
		ASSERT_TRUE(test4a->first == NULL)
		ASSERT_TRUE(test4a->last == NULL)

		//Case: Remove back
		ASSERT_TRUE(test4b->remove_back())
		ASSERT_TRUE(test4b->get_size() == 0)
		ASSERT_TRUE(test4b->first == NULL)
		ASSERT_TRUE(test4b->last == NULL)

		delete test4a;
		delete test4b;
		test4a = test4b = NULL;
	    return true;
	}
	
	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
		DronesManager empty;
		DronesManager* test5 = new DronesManager(empty);
		DronesManager::DroneRecord test_Drone1(1, 1, 1, "a", "a","a", "a");
		DronesManager::DroneRecord test_Drone2(2, 2, 2, "b", "b","b", "b");
		DronesManager::DroneRecord test_Drone3(3, 3, 3, "c", "c","c", "c");
		DronesManager::DroneRecord test_Drone4(4, 4, 4, "d", "d","d", "d");
		DronesManager::DroneRecord test_Drone5(5, 5, 5, "e", "e","e", "e");

		//Case 1: Replace empty list 
		ASSERT_FALSE(test5 -> replace(0,test_Drone1))
		ASSERT_FALSE(test5 -> replace(1,test_Drone1))
		ASSERT_TRUE(test5-> first == NULL)
		ASSERT_TRUE(test5-> last == NULL)
		ASSERT_TRUE(test5-> get_size() == 0)

		// //Case2: Replace element insingle-element list and try to replace out of index
		test5->insert_back(test_Drone3);
		ASSERT_TRUE(test5->replace(0,test_Drone1))
		ASSERT_TRUE(*test5-> first == test_Drone1)
		ASSERT_TRUE(*test5-> last == test_Drone1)
		ASSERT_TRUE(test5-> get_size() == 1)

		ASSERT_FALSE(test5->replace(2,test_Drone2))
		ASSERT_TRUE(test5-> get_size() == 1)

		//Case 3: Replace element in multi-element list and last element
		test5->insert_back(test_Drone4);
		test5->insert_back(test_Drone3);
		test5->insert_back(test_Drone4);
		test5->insert_back(test_Drone1);
		ASSERT_TRUE(test5->replace(2,test_Drone2))
		ASSERT_TRUE(*test5-> first == test_Drone1)
		ASSERT_TRUE(*test5-> last == test_Drone1)
		ASSERT_TRUE(test5-> get_size() == 5)
		ASSERT_TRUE(test5->replace(4,test_Drone5))
		ASSERT_TRUE(*test5-> first == test_Drone1)
		ASSERT_TRUE(*test5-> last == test_Drone5)
		ASSERT_TRUE(test5-> get_size() == 5)
		ASSERT_TRUE(*test5->last == test_Drone5)
		ASSERT_TRUE(*test5->first == test_Drone1)

		//Reverse Linked List 
		
		//Case 1: Normal Reverse Linked List
		cout << "Before reversal:" << endl;
		test5->print();
		cout << "After reversal:" << endl;
		ASSERT_TRUE(test5->reverse_list())
		test5->print();
		ASSERT_TRUE(*test5->last == test_Drone1)
		ASSERT_TRUE(*test5->first == test_Drone5)

		//Case 2: Reverse a empty list
		cout << "Empty reversal:" << endl;
		test5 = new DronesManager(empty);
		test5->print();
		ASSERT_FALSE(test5->reverse_list())

		//Case 3: Single Item Reverse Linked List
		test5->insert_back(test_Drone1);
		test5->print();
		ASSERT_FALSE(test5->reverse_list())

		delete test5;
		test5 = NULL;

	    return true;
	}
	
	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
		DronesManager empty;
		DronesManager* test6 = new DronesManager(empty);
		DronesManager::DroneRecord test_Drone1(1, 1, 1, "a", "a","a", "a");
		DronesManager::DroneRecord test_Drone2(2, 2, 2, "b", "b","b", "b");
		DronesManager::DroneRecord test_Drone3(3, 3, 3, "c", "c","c", "c");
		DronesManager::DroneRecord test_Drone4(4, 4, 4, "d", "d","d", "d");
		DronesManager::DroneRecord test_Drone5(5, 5, 5, "e", "e","e", "e");

		//Case 1: insert_front() on an empty  list
		ASSERT_TRUE(test6->insert_front(test_Drone5))
		ASSERT_TRUE(*test6->first == test_Drone5)
		ASSERT_TRUE(*test6->last == test_Drone5)
		ASSERT_TRUE(test6->get_size() == 1)
		//Current List:: 5

		//Case 2: insert_front() on an a single-object in  list
		ASSERT_TRUE(test6->insert_front(test_Drone4))
		ASSERT_TRUE(*test6->first == test_Drone4)
		ASSERT_TRUE(*test6->last == test_Drone5)
		ASSERT_TRUE(test6->get_size() ==2)
		//Current List:: 4->5

		//Case 3: insert_front() on an a multi-object  list
		ASSERT_TRUE(test6->insert_front(test_Drone3))
		ASSERT_TRUE(test6->insert_front(test_Drone2))
		ASSERT_TRUE(test6->insert_front(test_Drone1))
		ASSERT_TRUE(test6->get_size() ==5)
		//Current List:: 1->2->3->4->5
		
		//Check if the inserts moved foward the nodes
		ASSERT_TRUE(test6->select(0) == test_Drone1)
		ASSERT_TRUE(test6->select(1) == test_Drone2)
		ASSERT_TRUE(test6->select(2) == test_Drone3)
		ASSERT_TRUE(test6->select(3) == test_Drone4)
		ASSERT_TRUE(test6->select(4) == test_Drone5)
		ASSERT_TRUE(*test6->first == test_Drone1)
		ASSERT_TRUE(*test6->last == test_Drone5)

		delete test6;
		test6 = NULL;
	    return true;
	}
	
	// PURPOSE: inserting at different positions in the list
	bool test7() {
		DronesManager empty;
		DronesManager* test7 = new DronesManager(empty);
		DronesManager::DroneRecord test_Drone1(1, 1, 1, "a", "a","a", "a");
		DronesManager::DroneRecord test_Drone2(2, 2, 2, "b", "b","b", "b");
		DronesManager::DroneRecord test_Drone3(3, 3, 3, "c", "c","c", "c");
		DronesManager::DroneRecord test_Drone4(4, 4, 4, "d", "d","d", "d");
		DronesManager::DroneRecord test_Drone5(5, 5, 5, "e", "e","e", "e");

		//Case 1: Inserting Out of Range
		ASSERT_FALSE(test7->insert(test_Drone1,2) )
		ASSERT_TRUE(test7->get_size() == 0)
		ASSERT_TRUE(test7->last == NULL)
		ASSERT_TRUE(test7->first == NULL)

		//Case 2: Normal Insertions
		ASSERT_TRUE(test7->insert(test_Drone1,0))
		ASSERT_TRUE(test7->insert(test_Drone5,1))
		ASSERT_TRUE(test7->insert(test_Drone3,1))
		ASSERT_TRUE(test7->insert(test_Drone4,2))
		ASSERT_TRUE(test7->insert(test_Drone2,1))
		//Current List:: 1->2->3->4->5
		test7->print();
		
		//Check if the inserts were inserted correctly
		ASSERT_TRUE(test7->select(0) == test_Drone1)
		ASSERT_TRUE(test7->select(1) == test_Drone2)
		ASSERT_TRUE(test7->select(2) == test_Drone3)
		ASSERT_TRUE(test7->select(3) == test_Drone4)
		ASSERT_TRUE(test7->select(4) == test_Drone5)
		ASSERT_TRUE(*test7->first == test_Drone1)
		ASSERT_TRUE(*test7->last == test_Drone5)

		// //More Fails
		ASSERT_FALSE(test7->insert(test_Drone3,6) )
		ASSERT_FALSE(test7->insert(test_Drone5, 9) )
		ASSERT_TRUE(test7->get_size() == 5)

		delete test7;
		test7 = NULL;

	    return true;
	}
	
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
		DronesManager empty;
		DronesManager* test8 = new DronesManager(empty);
		DronesManager::DroneRecord test_Drone1(1, 1, 1, "a", "a","a", "a");
		DronesManager::DroneRecord test_Drone2(2, 2, 2, "b", "b","b", "b");
		DronesManager::DroneRecord test_Drone3(3, 3, 3, "c", "c","c", "c");
		DronesManager::DroneRecord test_Drone4(4, 4, 4, "d", "d","d", "d");
		DronesManager::DroneRecord test_Drone5(5, 5, 5, "e", "e","e", "e");

		//Case 1: Remove empty list
		ASSERT_FALSE(test8->remove(1))
		ASSERT_FALSE(test8->remove(0))
		
		ASSERT_TRUE(test8->insert_back(test_Drone1))
		ASSERT_TRUE(test8->insert_back(test_Drone2))
		ASSERT_TRUE(test8->insert_back(test_Drone3))
		ASSERT_TRUE(test8->insert_back(test_Drone4))
		ASSERT_TRUE(test8->insert_back(test_Drone5))
		ASSERT_TRUE(test8->get_size() == 5)
		//Current List:: 1->2->3->4->5

		//Case 2: Remove too many 
		ASSERT_TRUE(test8->remove(0))
		ASSERT_TRUE(test8->remove(3))
		ASSERT_TRUE(test8->remove(1))
		ASSERT_TRUE(test8->remove(1))
		ASSERT_TRUE(test8->remove(0))
		ASSERT_TRUE(test8->get_size() == 0)
		
		//Current List: Empty , Continure to Remove
		ASSERT_FALSE(test8->remove(0))
		ASSERT_FALSE(test8->remove(2))
		ASSERT_FALSE(test8->remove(5))

		//Insert a few elements
		ASSERT_TRUE(test8->insert_back(test_Drone1))
		ASSERT_TRUE(test8->insert_back(test_Drone2))
		ASSERT_TRUE(test8->insert_back(test_Drone3))
		ASSERT_TRUE(test8->get_size() == 3)
		ASSERT_TRUE(*test8->first == test_Drone1)
		ASSERT_TRUE(*test8->last == test_Drone3)

		delete test8;
		test8 = NULL;

	    return true;
	}
	
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		//Set-up:
		DronesManager empty;
		DronesManager* test9 = new DronesManager(empty);
		DronesManager::DroneRecord test_Drone1(1, 1, 1, "a", "a","a", "a");
		DronesManager::DroneRecord test_Drone2(2, 2, 2, "b", "b","b", "b");
		DronesManager::DroneRecord test_Drone3(3, 3, 3, "c", "c","c", "c");
		DronesManager::DroneRecord test_Drone4(4, 4, 4, "d", "d","d", "d");
		DronesManager::DroneRecord test_Drone5(5, 5, 5, "e", "e","e", "e");

		ASSERT_TRUE(test9->insert_back(test_Drone1))
		ASSERT_TRUE(test9->insert_back(test_Drone2))
		ASSERT_TRUE(test9->insert_back(test_Drone3))
		ASSERT_TRUE(test9->insert_back(test_Drone4))
		ASSERT_TRUE(test9->insert_back(test_Drone5))
		//Current State: 1->2->3->4->5

		ASSERT_FALSE(test9->remove(100))
		ASSERT_TRUE(test9->remove_front())
		ASSERT_TRUE(test9->remove_back())
		ASSERT_FALSE(test9->remove(4))
		ASSERT_FALSE(test9->insert(test_Drone5,5 ))
		ASSERT_FALSE(test9->insert(test_Drone2,7))
		ASSERT_TRUE(test9->replace(1,test_Drone5))
		ASSERT_FALSE(test9->replace(3,test_Drone5))
		//Current State: 2->5->4

		ASSERT_TRUE(test9->remove_back())
		ASSERT_TRUE(test9->remove_back())
		ASSERT_TRUE(test9->remove_front())
		//Empty
		ASSERT_FALSE(test9->replace(0,test_Drone5))
		ASSERT_FALSE(test9->remove_front())
		ASSERT_FALSE(test9->remove_front())
		
		delete test9;
		test9 = NULL;
		
		return true;
	}    
	    	
	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
		//Set-up:
		DronesManager empty;
		DronesManager* test10 = new DronesManager(empty);
		DronesManager::DroneRecord test_Drone1(1, 1, 1, "a", "a","a", "a");
		DronesManager::DroneRecord test_Drone2(2, 2, 2, "b", "b","b", "b");
		DronesManager::DroneRecord test_Drone3(3, 3, 3, "c", "c","c", "c");
		DronesManager::DroneRecord test_Drone4(4, 4, 4, "d", "d","d", "d");
		DronesManager::DroneRecord test_Drone5(5, 5, 5, "e", "e","e", "e");

		//Inserts
		ASSERT_TRUE(test10->insert_front(test_Drone1))
		ASSERT_TRUE(test10->insert_back(test_Drone2))
		ASSERT_TRUE(test10->insert(test_Drone3,2))
		ASSERT_TRUE(test10->insert(test_Drone4,3))
		ASSERT_TRUE(test10->insert_back(test_Drone5))
		//Current State: 1->2->3->4->5
		
		// Reverse Linked List
		ASSERT_TRUE(test10->reverse_list())
		ASSERT_TRUE(*test10->last == test_Drone1)
		ASSERT_TRUE(*test10->first == test_Drone5)
		ASSERT_TRUE(test10->size == 5)
		//Current State: 5->4->3->2->1
		test10->print();

		ASSERT_TRUE(test10->remove_front())
		ASSERT_TRUE(test10->remove_back())
		ASSERT_TRUE(test10->remove(2))
		ASSERT_TRUE(test10->remove_front())
		ASSERT_TRUE(test10->remove(0))
		//Current State: Empty
		
		delete test10;
		test10 = NULL;
		
	   return true;
	} 
};

#endif
