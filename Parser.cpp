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

std::vector<Token> Parser::parse(const std::vector<Token>& tokens) {

  std::vector<Token> Output;
  linkedList<std::string> Stack;


  for ( int i = 0; i < tokens.size() ; i++ ) 
  {
    std::string topOperator = Stack.showTheTop();
    char current = tokens[i].value[0];
    if ( sorter(current) == 0 ) { 
      Output.push_back(tokens[i]);
    }
    
    if ( sorter(current) >= 1 ) {
      if (Stack.sizeOfLinkedList() == 0) {
        Stack.insert(tokens[i].value);
      }
      else {
        while (Stack.sizeOfLinkedList() > 0 && sorter(current) <= sorter(Stack.showTheTop()[0]) ) 
        {
          std::string topOp = Stack.showTheTop();
          Output.push_back(topOp);
          Stack.deleteValue(topOp;
        }
        Stack.insert(tokens[i].value);
      }
    }
  }
  // I declared Size because It will be constant while Stack.sizeOfLinkedList is changable
  int Size = Stack.sizeOfLinkedList();
  while (Stack.sizeOfLinkedList() > 0)
  {
    topOp = Stack.showTheTop();
    Output.push_back(top) topOperator;
    Stack.deleteValue(topOperator);
  }
  return Output;
}

