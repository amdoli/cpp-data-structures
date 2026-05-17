#include <iostream>
// block content
struct node {
  int data;
  node* nextnode;
};

class linkedlist{

  private:
    node* head;
    int number_of_index;

  public:
    linkedlist()
    {
      head = nullptr;
      number_of_index = 0;
    }
  
  void insertathead(int value){
    // add new Node in the memory
    node* newvalue = new node;
    number_of_index ++;

    newvalue -> data = value;
    newvalue -> nextnode = head;  // let the New Value points to the head 
    // for each new node the head will be changed to the newest starting from the nullptr
    head = newvalue;
  }

  void deletevalue(int target)  // to delete certain value
  {

    node* current = head;
    bool deleted = false;
    // check if the list is actually have data
    if ( sizeoflinkedlist() > 0)
    {
      // if the target is at the top of the list
      if (current -> data == target){
        head = head -> nextnode;
        delete current;
        deleted = true;
      }
      else {
        // It will be 3 node pointers. Current pointer will have the present, previous pointer will have the last node, and lastly buffer will have the next node if the condition applied. 
        node* buffer = nullptr;
        node* previous = current;
        current = current -> nextnode;
        int i = 0;
        while (current != nullptr)
        {
          if ( current -> data == target )
          {
            buffer = current -> nextnode;
            previous -> nextnode = buffer;
            delete current;
            deleted = true;
            break;
          }

          else
          {
            previous = current;
            current = current -> nextnode;
          }
        }
      }
    }
    if (deleted){
      number_of_index --;
    }
  }

  void printlist(){

    node* current = head;
    int counter = 0;
    
    std::cout<<"[";
    while(current != nullptr)
    {
      counter++;
      std::cout << current -> data;
      if (counter < number_of_index){
        std::cout << ",";
      }
      current = current -> nextnode;
    }
    std::cout << "]" << std::endl;

  }
  
  int sizeoflinkedlist(){
    return number_of_index;
  }

};

int main(){

  linkedlist list;

  list.insertathead(5);
  list.insertathead(8);
  list.insertathead(-90);
  
  list.printlist();

  std::cout << "what data you want to delete?" << std::endl;
  int user_input = 0;
  std::cin >> user_input;
  
  list.deletevalue(user_input);
  list.printlist();
  
  int size = list.sizeoflinkedlist();
  std::cout << size << std::endl;

  return 0;
}
