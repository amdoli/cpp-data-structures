#include <iostream>
#include "linkedlist.h"

linkedList::linkedList(){
  head = nullptr;
  size = 0;
}

void linkedList::insert(int value){
  Node* newValue = new Node;
  size ++;
  
  newValue -> data = value;
  newValue -> nextNode = head;
  head = newValue;
}

void linkedList::deleteValue(int target){
  Node* current = head;
  if ( size < 0 ) return;
  
  if (current -> data == target){

    head = head -> nextNode;

    delete current;
    size --;
  }
  
  else{
    Node* buffer = nullptr;
    Node* previous = current;
    current = current -> nextNode;

    while( current != nullptr){

      if (current -> data != target) {
        previous = current;
        current = current -> nextNode;
        contenue;
      }

      buffer = current->nextNode;
      previous -> nextNode = buffer;

      delete current;
      size --;
      break;

    }
  }
}
void linkedList::printlist(){
  Node* current = head;
  int counter = 0;

  std::cout << "[";
  while (current != nullptr){
    counter++;

    std::cout << current->data;

    if (counter < size) {
      std::cout << ",";
    }
    current = current -> nextNode
  }
  std::cout << "]" << std::endl;
}

int linkedList::sizeOfLinkedList() {
  return size;
}

void linkedList::freeAll() {
  Node* current = head;
  while (head != nullptr) {
    head = head -> nextNode;
    delete current;
    current = head;
  }
}



