/******************************************************
** Program: prog.cpp
** Author: Andy James
** Date: 6/6/2021
** Description: runs through functions of a linked list
** Input: none
** Output: none
******************************************************/
#include <iostream>
#include <string>
#include "linked_list.h"

using namespace std;

void entering_options(Linked_List&);
int number_check();
int input_check(int,int);

/****************************************************************************************
** Function: int main()
** Description: runs through loop for creating and manipulating linked list
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
int main() {
    cout << "\033[2J\033[1;1H"; //clear screen
    int choice = 1;
    cout << "hello welcome to the list thing" << endl;
    Linked_List list;
    
    while (choice == 1) {
        list.clear();
        entering_options(list);
        cout << "your current list is : ";
        list.print();
        cout << "1 for ascending, 2 for descending: ";
        choice = input_check(1,2);
        (choice == 1) ? list.sort_ascending() : list.sort_descending(); //checks for sort type
        cout << "your linked list is now: "; 
        list.print();
        cout << "you have " << list.num_primes() << " prime number(s) in your list." << endl;
        cout << "would you like to go again? 1 for yes, 2 for no: ";
        choice = input_check(1,2);
    }
    list.clear();
}

/****************************************************************************************
** Function: void entering_options(Linked& list)
** Description: lets user choose how to enter a number into the linked list
** Parameters: Linked_List&
** Pre-Condition: pass in a adress to a linked list class
** Post-Condition: none
*****************************************************************************************/
void entering_options(Linked_List& list) {
    int num;
    int option;
    int cont = 1;
    while(cont == 1) {
        cout << "please enter a number: ";
        num = number_check();
        cout << "1 for push front, 2 for push back, 3 for insert: ";
        option = input_check(1,3);
        if(option == 1) { // push front option
            cout << "the list is now length "<< list.push_front(num) << endl;
        }
        else if(option == 2) { // push back option
            cout << "the list is now length "<< list.push_back(num) << endl;
        }
        else { // index option
            cout << "the list is length " << list.get_length() << ", what index: ";
            option = input_check(0,list.get_length());
            cout << "the list is now length "<< list.insert(num,option) << endl;
        }
        cout << "Do you want another number? 1 for yes, 2 for no: ";
        cont = input_check(1,2);
        cout << "\033[2J\033[1;1H"; //clear screen
    }


}

/****************************************************************************************
** Function: number_check()
** Description: checks if user input within the funciton is a number
** Parameters: none
** Pre-Condition: none
** Post-Condition: return an int if the user inputs an int
*****************************************************************************************/
int number_check() {
    int a;
    while(true) {
        cin >> a;

        if(cin.fail()) { //if not an int
            cin.clear();
            cin.ignore(1000000,'\n');
            cout << "error in input, please try again: ";
        }
        else if(!cin.fail()) { //if an int
            
            return a;
        }
    }
}

/****************************************************************************************
** Function: int input_check(int lower, int upper)
** Description: checks to see if number inputed is between a certain bounds
** Parameters: int lower, int upper
** Pre-Condition: pass in a int for lower bounds, and int for upper bounds
** Post-Condition: return a number once user types between the bounds
*****************************************************************************************/
int input_check(int lower,int upper) {
    int num;
    bool cont = true;
    while(cont) {
        num = number_check();
    
        if(num < lower || num > upper) { // if not on or between bounds
            cout << "enter a number from " << lower << " to " << upper << ": ";
        }
        else {
            cont = false;
        }
    }
    return num;
}