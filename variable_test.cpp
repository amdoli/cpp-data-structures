#include "sympolTable.h"
#include <iostream>


int main(){

    std::string value;
    SympolTable table;

    table.setVariable("x", "20");
    table.setVariable("x", "40");

    table.setVariable("y", "50");

    table.showVariables();

    value = table.getVariable("y");
    std::cout << value << std::endl;
    

    return 0;
}