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
  linkedList<std::string> Stack;  // that's a buffer for operators

  for ( int i = 0; i < tokens.size() ; i++ ) 
  {
    char current = tokens[i].value[0];

    if ( sorter(current) == 0 ) {
      Token currentToken = tokens[i];
      // then it's ether a number or a variable!
      if ( tokens[i].type == TokenType::Variable ) {
        showVariables();
        currentToken.value = getVariable(tokens[i].value); // for example if x = 25 the condition will change from x to 25
      }
      // in number we don't have to do anything just push it
      Output.push_back(currentToken);
    }
    if ( sorter(current) >= 1 ) 
    {
      while (Stack.sizeOfLinkedList() > 0 && sorter(current) <= sorter(Stack.showTheTop()[0]) ) 
      {
        std::string topOp = Stack.showTheTop();
        Token newOperator = { TokenType::Operator , topOp};
        Output.push_back(newOperator);
        Stack.deleteValue(topOp);
      }
      Stack.insert(tokens[i].value);
    }
  }
  // I declared Size because It will be constant while Stack.sizeOfLinkedList is changable
  int Size = Stack.sizeOfLinkedList();
  while (Stack.sizeOfLinkedList() > 0)
  {
    std::string topOp = Stack.showTheTop();
    Token newOperator = {TokenType::Operator, topOp};
    Output.push_back(newOperator);
    Stack.deleteValue(topOp);
  }

  Stack.freeAll();
  return Output;
  /*
  std::cout << "==============" << std::endl;
  for (int i = 0; i < Output.size(); i++)
  {
    std::cout << Output[i].value << " ";
  }
  std::cout << "\n==============\n" << std::endl;
  return Output;
  */
}

std::vector<Token> Parser::forceParse(const std::string& expression) {

  Tokenizer tokenizer;
  tokenizer.tokenize(expression);
  std::vector<Token> tokenizedEquation = tokenizer.tokenize(expression);

  return parse(tokenizedEquation);

}



