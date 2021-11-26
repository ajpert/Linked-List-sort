/******************************************************
** Program: linked_list.cpp
** Author: Andy James
** Date: 6/6/2021
** Description: holds functions of the linked list class
** Input: none
** Output: none
******************************************************/
#include "linked_list.h"

using namespace std;

/****************************************************************************************
** Function: Linked_List()
** Description: default constructor for Linked_list(), sets length to 0 and head to null
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Linked_List::Linked_List() {
    length = 0;
    head = nullptr;
}

/****************************************************************************************
** Function: get_length()
** Description: gets the length of the list
** Parameters: none
** Pre-Condition: none
** Post-Condition: return unsigned int length
*****************************************************************************************/
int Linked_List::get_length() {
    return length;
}

/****************************************************************************************
** Function: print()
** Description: prints out the linked list
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Linked_List::print() {
    if(length == 0) { //if list is empty
        cout << "the list is empty" << endl;
    }
    else {
        Node* temp = head;
        while(temp != nullptr) { //goes through each node and prints val           
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        //cout << temp->val << endl;
        /*cout << endl;
        temp = head;
        while(temp != nullptr) {
            cout << temp->prev << " " << temp << " " << temp->next << endl;
            temp = temp->next;
        }*/
    }
}


/****************************************************************************************
** Function: push_front(int val)
** Description: adds an element to the front of the linked list
** Parameters: int val
** Pre-Condition: pass in a int 
** Post-Condition: return length
*****************************************************************************************/
unsigned int Linked_List::push_front(int val){    
    Node* temp = new Node();
    temp->val = val;  
    if(length == 0) { //if the length is 0, this gets set to the head
        head = temp;
    }
    else {    
    temp->next = head;
    temp->prev = nullptr;
    head->prev = temp;

    head = temp;  
    }  
    length++;
    return length;
}

/****************************************************************************************
** Function: push_back(int val)
** Description: adds an element to the back of the linked list
** Parameters: int val
** Pre-Condition: pass in a int 
** Post-Condition: return length
*****************************************************************************************/
unsigned int Linked_List::push_back(int val) {
    Node* new_node = new Node();
    new_node->val = val;
    Node* temp = head;
    if(head == nullptr) { // if the length is 0, gets set as the new head
        head = new_node;
    }
    else{
        while(temp->next != nullptr) { //goes to the end of the list
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    length++;
    return length;
}

/****************************************************************************************
** Function: insert(int val)
** Description: adds an element to the index chosen on the linked list
** Parameters: int val
** Pre-Condition: pass in a int 
** Post-Condition: return length
*****************************************************************************************/
unsigned int Linked_List::insert(int val, unsigned int index) {
    Node* new_node = new Node();
    new_node->val = val;
    if(index == 0) { //if it is 0th index
        if(head == nullptr) {
            head = new_node;
        }
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    else{
        Node* temp;
        temp = head;
        for(int i = 0; i < index - 1; i++) { //itterates to index wated
            temp = temp->next;
        }
        new_node->next = temp->next;
        if(temp->next != nullptr) { //if the next is not a null pointer
            temp->next->prev = new_node;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    length++;
    return length;
}

/****************************************************************************************
** Function: clear()
** Description: clears the linked list, acts similarly to deconstructor
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Linked_List::clear() {
    Node* current = head;
    Node* next = nullptr;
    while(current != nullptr) { //goes until end of list and delets nodes
        next = current->next;
        delete current;
        current = next;
    }
    length = 0;
    head = nullptr;
}


/****************************************************************************************
** Function: num_primes()
** Description: returns how many primes are in the list
** Parameters: none
** Pre-Condition: none
** Post-Condition: return number of primes
*****************************************************************************************/
int Linked_List::num_primes() {
    int count = 0;
    Node* temp = head;
    if(head == nullptr) {
        return 0;
    }
    while(temp->next != nullptr) {
        if(is_prime(temp->val)) {
            count++;
        }
        temp = temp->next;
    }
    if(is_prime(temp->val))
        count++;
    return count;
}

/****************************************************************************************
** Function: is_prime(int num)
** Description: helper function for num_primes, determines if number is a prime
** Parameters: none
** Pre-Condition: none
** Post-Condition: retrn true if prime, false if not
*****************************************************************************************/
bool Linked_List::is_prime(int num) {
    if(num == 0 || num == 1 || num < 0) {
        return false;
    }
    for(int i = 2; i <= abs(num/2); i++) {
        if(num%i == 0) {
            return false;
        }
    }
    return true;
}

/****************************************************************************************
** Function: swap(Node* n1, Node* n2)
** Description: swaps two nodes around
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Linked_List::swap(Node* n1, Node* n2) {
    Node* n1_prev = n1->prev;
    Node* n1_next = n1->next;
    Node* n2_prev = n2->prev;
    Node* n2_next = n2->next;

    Node* temp_n1_next = n1->next;
    Node* temp_n2_prev = n2->prev;

    if(n1->next == n2) { //if they are adjacent
        swap_adjacent(n1,n2);
    }
    else { //if the nodes are not adjacent
        if(n1->prev != nullptr) { //if you are not swapping head values
            n1->prev->next = n2;
        }
        else { // if you are
            head = n2; 
        }
        n1->next->prev = n2;
        if(n2_next != nullptr) { //if you are not swapping tail values
            n2->next->prev = n1;
        }
        n2->prev->next = n1;

        n1->next = n2->next;
        n2->next = temp_n1_next;

        n2->prev = n1->prev;
        n1->prev = temp_n2_prev;
    }
}
/****************************************************************************************
** Function: swap_adjacent(Node* n1, Node* n2)
** Description: swaps two nodes around if adjacent
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Linked_List::swap_adjacent(Node* n1, Node* n2) {
    
        Node* n1_prev = n1->prev;
        Node* n1_next = n1->next;
        Node* n2_prev = n2->prev;
        Node* n2_next = n2->next;

        n1->next = n2_next;
        n2->next = n1;
        n1->prev = n2;
        n2->prev = n1_prev;

        if(n1_prev != nullptr) { //if you are not swapping head values
            n1_prev->next = n2;
        }
        else { //if you are swapping head values
            head = n2;
        }
        if(n2_next != nullptr) { // if you are not swapping tail values
            n2_next->prev = n1;
        }

}
/****************************************************************************************
** Function: sort_ascending()
** Description: sorts the linked list in ascending order
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Linked_List::sort_ascending() {

    Node* first;
    bool made_swap;

    do {
        made_swap = false;
        first = head;
        while(first->next != nullptr) { //itterates first until the tail (it sees next is null)
            if(first->val > first->next->val) { //if the node is bigger than the node after swap
                swap(first,first->next);
                made_swap = true;
            }
            else { //move forward if nothing happens
            first = first->next;
            }
        }
    } while(made_swap);

}

/****************************************************************************************
** Function: sort_descending
** Description: clears the linked list, acts similarly to deconstructor
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Linked_List::sort_descending() {
    Node* first;
    bool made_swap;

    do {
        made_swap = false;
        first = head;
        while(first->next != nullptr) { //itterates first until the tail (it sees next is null)
            if(first->val < first->next->val) { //if the node is smaller than the node after swap
                swap(first,first->next);
                made_swap = true;
            }
            else { //move forward if nothing happens
            first = first->next;
            }
            //print();
        }

    } while(made_swap);
}
