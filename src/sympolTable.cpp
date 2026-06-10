#include "sympolTable.h"

#include <iostream>

SympolTable::SympolTable(){
    head = nullptr;
}

void SympolTable::setVariable(std::string name, std::string value) {
    node* current = head;
    bool isExist = false;
    while( current != nullptr ) 
    {
        if ( current -> identifire == name ) {
            current -> data = value;
            isExist = true;
            break;
        }
        else current = current -> nextNode; 
    }

    if (!isExist){
        node* newNode = new node;
        newNode -> identifire = name;
        newNode -> data = value;
        newNode -> nextNode = head;

        head = newNode;
    }
}

std::string SympolTable::getVariable(std::string name) {
    node* current = head;
    while ( current != nullptr ) 
    {
        if ( current -> identifire == name ) {
            return current -> data;
        }
        current = current -> nextNode;
    }
    std::cout << "Error, The variable did not exist!" << std::endl;
    return "0.0";
}

SympolTable::~SympolTable(){
    node* current = head;
    node* previous = current;
    while( current != nullptr ) 
    {
        current = current -> nextNode;
        delete previous;
        previous = current;
    }
}