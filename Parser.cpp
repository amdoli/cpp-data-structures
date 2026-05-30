#include "Parser.h"
#include "tokenizer.h"
#include "linkedlist.h"

#include <vector>
#include <iostream>
#include <string>
#include <cctype>


int Parser::sorter(char tokenValue){
  // from the strongest to the weakest
  if (tokenValue == '*' || tokenValue == '/') return 2;

  if (tokenValue == '+' || tokenValue == '-') return 1;

  else return 0;
}  

std::string Parser::parse(const std::vector<Token>& tokens) {

  std::string Output = "";
  linkedList<std::string> Stack;


  for ( int i = 0; i < tokens.size() ; i++ ) {
    std::string topOperator = Stack.showTheTop();
    char current = tokens[i].value[0];
    if ( sorter(current) == 0 ) { 
      Output += current;
    }
    
    if ( sorter(current) >= 1 ) {
      if (Stack.sizeOfLinkedList() == 0) {
        Stack.insert(tokens[i].value);
      }
      else {
        if ( sorter(current) > sorter(topOperator[0]) ) {
          Stack.insert(tokens[i].value);
        }
        else {
          Output += topOperator;
          Stack.deleteValue(topOperator);
          Stack.insert(tokens[i].value);
        }
      }
    }
  }
  std::cout << Output << std::endl;
  return Output;
}

