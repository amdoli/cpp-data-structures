#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
  int Data;
  Node* nextNode;
};

class linkedList{
  private:
    Node* head;
    int size;

  public:
    linkedList()
    {
      head = nullptr;
      size = 0;
    }

    void insert(int value);
    void deleteValue(int target);
    void printlist();
    int sizeoflinkedlist();
    void freerAll();
};

#endif
