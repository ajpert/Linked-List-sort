/******************************************************
** Program: linked_list.h
** Author: Andy James
** Date: 6/6/2021
** Description: header file for linked_list.cpp
** Input: none
** Output: none
******************************************************/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>
#include <cmath>
#include "node.h"

class Linked_List {
private:
   unsigned int length; // the number of nodes contained in the list
   Node *head; // a pointer to the first node in the list
   // anything else you need...
public:
   Linked_List();
   int get_length();
   void print(); // output a list of all integers contained within the list
   void clear(); // delete the entire list (remove all nodes and reset length to 0)
   unsigned int push_front(int); // insert a new value at the front of the list (returns the new length of the list)
   unsigned int push_back(int); // insert a new value at the back of the list (returns the new length of the list)
   unsigned int insert(int val, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)
   void sort_ascending(); // sort the nodes in ascending order. 
   void sort_descending(); // sort the nodes in descending order
   int num_primes(); // gives num primes
   bool is_prime(int); // tells if num is prime
   void swap(Node*,Node*); // swaps nodes
   void swap_adjacent(Node*, Node*); // swaps nodes next to each other
   
};



#endif