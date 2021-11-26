/******************************************************
** Program: node.cpp
** Author: Andy James
** Date: 6/6/2021
** Description: defines a node when created
** Input: none
** Output: none
******************************************************/

#include "node.h"
/****************************************************************************************
** Function: Node()
** Description: sets everything to null;
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Node::Node() {
    next = nullptr;
    prev = nullptr;
}