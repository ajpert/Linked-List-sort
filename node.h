/******************************************************
** Program: node.h
** Author: Andy James
** Date: 6/6/2021
** Description: header file for node.cpp
** Input: none
** Output: none
******************************************************/
#ifndef NODE_H
#define NODE_H

#include <iostream>


class Node {
public:
    Node();
   int val;    // the value that this node stores
   Node *next; // a pointer to the next node in the list
   Node *prev; //pointer to the previous node
};

#endif