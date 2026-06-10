#ifndef SYMPOLTABLE_H
#define SYMPOLTABLE_H

#include <iostream>

struct node{
    std::string identifire;
    std::string data;
    node* nextNode;
};


class SympolTable {
    private:
    node* head;
    public:
    SympolTable();
    void setVariable(std::string name, std::string value);
    std::string getVariable(std::string name);


    ~SympolTable();



};



#endif