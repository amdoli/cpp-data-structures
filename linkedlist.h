#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// =========================
//      THE BLUEPRINTS
// =========================

template <typename T>
struct Node {
  T Data;
  Node<T>* nextNode;
};

template <typename T>
class linkedList{
  private:
    Node<T>* head;
    int size;

  public:
    linkedList()
    {
      head = nullptr;
      size = 0;
    }

    void insert(T value);
    void deleteValue(T target);
    void printlist();
    T showTheTop();
    int sizeOfLinkedList();
    void freeAll();
};

//==========================
//        THE LOGIC
//==========================


template <typename T>
void linkedList<T>::insert(T value){
  Node<T>* newValue = new Node<T>;
  size ++;
  
  newValue -> Data = value;
  newValue -> nextNode = head;
  head = newValue;
}

template <typename T>
void linkedList<T>::deleteValue(T target){
  Node<T>* current = head;
  if ( size < 0 ) return;
  
  if (current -> Data == target){

    head = head -> nextNode;

    delete current;
    size --;
  }
  
  else{
    Node<T>* buffer = nullptr;
    Node<T>* previous = current;
    current = current -> nextNode;

    while( current != nullptr){

      if (current -> Data != target) {
        previous = current;
        current = current -> nextNode;
        continue;
      }

      buffer = current->nextNode;
      previous -> nextNode = buffer;

      delete current;
      size --;
      break;

    }
  }
}

template <typename T>
void linkedList<T>::printlist(){
  Node<T>* current = head;
  int counter = 0;

  std::cout << "[";
  while (current != nullptr){
    counter++;

    std::cout << current->data;

    if (counter < size) {
      std::cout << ",";
    }
    current = current -> nextNode;
  }
  std::cout << "]" << std::endl;
}

template <typename T>
int linkedList<T>::sizeOfLinkedList() {
  return size;
}

template <typename T>
void linkedList<T>::freeAll() {
  Node<T>* current = head;
  while (head != nullptr) {
    head = head -> nextNode;
    delete current;
    current = head;
  }
}

template <typename T>
T linkedList<T>::showTheTop() {
  if ( sizeOfLinkedList() > 0 ) {
    return head -> Data;
  }
  return T();
}


#endif
