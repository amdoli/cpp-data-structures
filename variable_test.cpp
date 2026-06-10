#include "sympolTable.h"
#include <iostream>


int main(){

    std::string value;
    SympolTable table;

    table.setVariable("x", "20");
    table.setVariable("x", "40");
    value = table.getVariable("x");
    std::cout << value << std::endl;

    return 0;
}