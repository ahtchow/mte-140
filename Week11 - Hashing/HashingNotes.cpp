/**
 * @file HashingNotes.cpp
 * @author Adrian Chow (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/**
 * @brief INTRODUCTION to Hashing
 * 
 *  HASH Tables and Hashing
 *      - Used when crafting software components that provide info security, fast access
 *        to unordered data and association of shorter strings w/ larger data records
 * 
 *  Components:
 * 
 *  1. Hash Table (Type of Associative Map)
 *  - A collection of (KEY,VALUE) associations, where each key is typically unique and keys are 
 *    need to be comparable objects such as strings
 *  
 *  2. A Hash Function
 *  - Used to map each key to a specific location w/in data structures
 *  
 *  Use of hash table and hash function is referred to as hashing.
 * 
 *   Hash Explained.
 *      A hash function, h(key) takes a single key as input and it produces a hash index as output
 *      The index represents a location of a specific entry in the hash table and determines
 *      the placement of a key-value association in the has table.
 * 
 *    
 *    (key, value) --->  Hash function [ h(key)]  -> Hash Index   -> Use has index to retrieve data
 *      INPUT ---------  HASH FUNCTION ------------  OUTPUT
 * 
 * 
 */

/**
 * @brief Hash ADT
 *      
 *  1. Search() -> returns a value that matches a specific key
 *  2. Insert() -> Inserts a key-value association into the hash table
 *  3. Delete() -> Deletes key-value assocation from the table
 * 
 *  Runtime Efficiency:
 *      O(1) for all three operations
 *     1. Search -> Simply calculate the key index and check if value is there
 *     2. Insert -> Compute the index key and then place into the matching entry
 *     3. Delete -> compute index of key and then delete the pair from matching entry
 * 
 *      Collision and Hash Function can have a huge impact on the runtime
 *         
 *      c++ uses STL <unordered_map> for hash table implementation
 *      and <map> implements hashing using balanced BST
 * 
 *   E.g Hashing in Information Security
 *      - Users password is extended w/ random 'salt value' and stored as a hash value
 *      - The server finds the entry for the username and compares hashed 
 *          salt + password value against the value stored in the database
 *      - If matches then authentication is granted
 * 
 *  E.g Hashing Names
 *        -Derives the index based on the first letter of the username (0-25 = a-z)
 *  
 */

/**
 * @brief Collision
 *
 *      - A situation where two keys are mapped into the same index in the hash table
 *        (Can only store one key,value pair per index)
 * 
 *      Why do they occur? 
 *          - Number of possible keys is larger than hash table size;
 *          - Hence , the hash function is used to map large set of keys 
 *              into a small set of has-table entries
 *      
 *      Ideal Hashing Setup
 *          - Know all the keys ahead of time and design hash function based on that
 *          - Will never had to deal w/ collision due to well design
 * 
 *      Collisions could cause the complexity to degrade to O(n) which is
 *      counter-intuitive for the idea of hashing
 * 
 *  
 * 
 */

/**
 * @brief Seperate Chaining
 * 
 *      - The hash table implemented as an of linked lists,
 *          where each index stores a linked list.
 * 
 *     - Can be useful when distribution of keys and number is not known. (Avoid Collision)
 *          (but bad hashing function could cause O(n))
 * 
 *     -  For Each entry the table stores a pointer to a seperate linked list
 *              - Longer chains may resort to a self-balancing tree for O(log(n)) complexity
 * 
 *      - Every entry points to the previous entry
 *     
 *     - Each of the keys in one of the lists are mapped to the same hash index and
 *      each list node includes a key-value pair. 
 *           
 * 
 */

/**
 * @brief Open Addressing and Linear Probing
 * 
 *     - The hash table implemented as a dynamic array of key-value association    
 *     (Open-Addressing)
 *      
 *     - Check if h(key) + i , where i starts at 0 is empty
 *     - If not ++i and repeat until found empty index.
 *     - Insert (key,value) pair 
 *     
 *     - Same idea for searching, deleting
 *     - If we reach NULL before finding key, the key,value pair does not exist
 * 
 *     Primary Clustering: keys that hash within a cluster add to the cluster size
 * 
 */

/**
 * @brief Quadratic Probing 
 *      
 *      - The new key-value association is inserted at h(key) + i^2 , starts at 0
 *      Secondary Clustering: keys that have same hash will have same probing steps
 */

/**
 * @brief Double Hashing
 * 
 *  The new key-value associated will be inserted on next empty based on:
 *      h1(key) + i * h2(key)
 * 
 *         - h1(key) is starting index on the tabble
 *          - h2(key) is the scaled secondary hash key is used as offset collision
 *              -> e.g h2(x): k -(x%k) where k is size of table RANDOM CONSTANT
 * 
 *          - If collision occurs move to next hash index
 *  
 *     Slower, but can avoid primary and secondary clustering
 */

/**
 * @brief Performance Considerations
 * 
 *  - To avoid collisions , hash entries need to be spread around
 *  - No unbalance clusters , where many items are hashed in same locations
 *  - Linear Probing Requires load size/capacity to be high performance
 *  
 *  Lazy deletion w/ open addressing:
 *      - do not delete values from hash , but instead mark them as deleted to enable consistent queries
 *      - when inserting, replace and mark with new value
 * 
 *  A desirable hash function:
 *      - ensure key-value associations are spread around table
 *      - be unaffected by patterns in the keys
 *      - match data type of keys, utilize all parts of keys
 *      - efficient computing
 * 
 * 
 */