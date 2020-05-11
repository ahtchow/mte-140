/**
 * @file Heap.cpp
 * @author Adrian Chow
 * @brief Heap ADT
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 */

/**
 * @brief A complete binary tree with keys 
 *  or (key,value) pairs stored in its nodes
 * 
 *  MAX-HEAP: All children values <= root values
 *  MIN-HEAP: All children values >= root values
 * 
 *          Min                 Min
 * 
 *          8                     1
 *        /  \                  /  \
 *      7     5                2    3
 *     / |   / \              /\   / \
 *   4    3  2  1            5  4  7 8
 *  
 * Properties:
 *      1. Root has largest key
 *      2. Subtree rooted at any node of a heap os also a heap
 *      3. Can be represented as an array 
 *   
 * Applications:
 *      1. Sorting values (Heap Sort)
 *      2. Priority Queue
 * 
 * ADT Operations:
 *      1. Insert - Insert a Node 
 *      2. Remove - Remove a Node
 *      3. Heapify - Turns a general binary tree into a heap
 *  
 * 
 * 
 **/

