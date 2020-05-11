#include "lab3_priority_queue.hpp"

using namespace std;

/**
 * @brief Parametric Constructor
 * Initializes heap to an array of (n_capacity + 1) elements
 **/

PriorityQueue::PriorityQueue(unsigned int n_capacity) {

	// Intialize the capacity and size to appropriate values
	capacity = n_capacity;
	size = 0;

	// Initialize heap an array to (n_capacity + 1) elements
	heap = new TaskItem*[n_capacity + 1];

}

// PURPOSE: Explicit destructor of the class PriorityQueue
PriorityQueue::~PriorityQueue() {

	size = 0;
	capacity = 0;

	// Delete Each Index
	for(int i = 1; i <= size; ++i){
		delete heap[i];
		heap[i] = NULL;
	}
	
	// Delete Heap
	delete heap;
	heap = NULL;

}

/**
 * @brief Size Getter
 * Returns the number of elements in the priority queue
 */

unsigned int PriorityQueue::get_size() const {

	// Return size
	return size;

}

/**
 * @brief Checks if the priority queue is empty
 * Returns true if the priority queue is empty; false, otherwise
 */

bool PriorityQueue::empty() const {
	
	// Return bool for if size is not zero
	return !size;

}

/**
 * @brief Checks if the priority queue is full
 * Returns true if the priority queue is full; false, otherwise
 */

bool PriorityQueue::full() const {

	// Return bool for if size is equal to capacity
	return (size == capacity);

}

// PURPOSE: Prints the contents of the priority queue; format not specified
void PriorityQueue::print() const {
	
    // Print each element in Heap by level by level order
	for(int i=1;i<=size;i++){

		cout << heap[i]->priority << "-";

	}
	cout << endl;
}

/**
 * @brief Returns the max element of the priority queue without removing it
 * If the priority queue is empty, it returns (-1, "N/A")
 */

PriorityQueue::TaskItem PriorityQueue::max() const {

	// Return Max Element if exists
	if(size > 0)
		return *heap[1];
	
	cout << "There is not max element in HEAP ADT" << endl;
	return TaskItem(-1, "NULL");

}

/**
 * @brief Inserts the given value into the priority queue.
 * 1. re-arranges the elements back into a heap
 * 2. returns true if successful and false otherwise
 * 3. priority queue does not change in capacity
 */

bool PriorityQueue::enqueue( TaskItem val ) {

	// Do not insert if Priority Queue is full
	if(full())
		return false;

	// Case: First item in Priority Queue
	if (empty()){
		heap[1] = new TaskItem(val);
		++size;
		return true;
	}

	// Insert at end of Priority Queue
	int node_id = size + 1;
	heap[node_id] = new TaskItem(val);

	// Ensure Heap property compliance
	int child = node_id;
	int parent = node_id/2;

	while(node_id > 1 && (heap[parent]->priority < heap[child]->priority)){

		//Swap Parent and Child values
		TaskItem* temp = heap[node_id]; 
		heap[node_id] = heap[node_id/2];
		heap[node_id/2] = temp; 
		node_id /= 2;

	}

	++size;
	return true;
	
}

/**
 * @brief Removes the top element with the maximum priority.
 * 1. re-arranges the remaining elements back into a heap
 * 2. returns true if successful and false otherwise
 * 3. priority queue does not change in capacity
 */

bool PriorityQueue::dequeue() {

	// Empty Priority Queue
	if(empty())
		return false;

	// One item on Priority Queue
	if(size == 1){

		heap[size] = NULL;
		--size;
		return true;
		
	}

	// Swap and remove root node w/ last task.
	int index = 1;
	heap[index]->priority = heap[size]->priority;
	heap[index]->description = heap[size]->description;
	delete heap[size];
	heap[size] = NULL;
	--size;

	int left_index, right_index, left_priority, right_priority;

	// Ensure Heap property compliance
	while(size >= 2*index){ // While node index is a leaf (in range)

		left_index = 2*index;
		right_index = (2*index)+1;

		//Check for case that left child exists, but right node does not.
		if(right_index > size)
			right_index = left_index;

		int left_priority = heap[left_index]->priority;
		int right_priority = heap[right_index]->priority;

		//Check if priority is at index node is greater than its both childs
		if(heap[index]->priority > left_priority && heap[index]->priority > right_priority)
			return true;

		//Swap left, if larger
		else if(left_priority > right_priority){

			TaskItem* temp = heap[left_index]; // Will swap with left if right does not exist.
			heap[left_index] = heap[index];
			heap[index] = temp;
			index = left_index;

		}

		//Swap right, if less than right and greater than left
		else{

			TaskItem* temp = heap[right_index]; // Will swap with left if right does not exist.
			heap[right_index] = heap[index];
			heap[index] = temp;
			index = right_index;

		}

	}

	return true;

}
