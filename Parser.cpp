#include "Parser.h"
#include "tokenizer.h"
#include "linkedlist.h"

#include <vector>
#include <iostream>
#include <string>


Parser::sorter(char tokenValue){
  if (tokenValue == '*' || tokenValue == '/') {
    return 2;
  }
  if (tokenValue == '+' || tokenValue == '-') {
    return 1;
  }
  else {
    return 0;
  }
}

Parser::parse(const std::vector<Token>& tokens) {

  std::string Output = "";
  linkedList Stack;


  for ( int i = 0; i < tokens.size() ; i++ ) {
    char current = tokens[i].value ;
    if ( sorter(current) == 0 ) { 
      Output += current;
    }
    
    if ( sorter(current) == 1 || sorter(current) == 2 ) {
      if (Stack.sizeOfLinkedList() == 0) {
        Stack.insert()
      }
    }

  }
}

