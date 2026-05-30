#include "tokenizer.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>


std::vector<Token> Tokenizer::tokenize(const std::string& expression) {
  std::vector<Token> Equation;
  Token newData;

  std::string buffer = "";
  int i = 0;
  while (i < expression.size()) {
    char current = expression[i];

    if ( std::isdigit(current) ) {
      while ( i < expression.size() && std::isdigit(expression[i]) ) {

        buffer += expression[i];
        i++;
      }

      if ( i < expression.size()){
         current = expression[i];
      }

      newData.type = TokenType::Number;
      newData.value = buffer;

      Equation.push_back(newData);
      buffer = "";
      continue;
    }

    if ( std::isalpha(current) || current == '_') {
      while ( i < expression.size() && (std::isalpha(expression[i]) || expression[i] == '_') ) {

        buffer += expression[i];
        i++;
      }
    
      if ( i < expression.size()) {
        current = expression[i];
      }

      newData.type = TokenType::Variable;
      newData.value = buffer;

      Equation.push_back(newData);
      buffer = "";
      continue;

    }

    if ( current == ' ') { 
      i++;
      continue;
    }

    if ( current == '+' || current == '-' || current == '*' || current == '/') {

      newData.type = TokenType::Operator;
      newData.value = current;

      Equation.push_back(newData);

      i++;
    }
  }
  return Equation;
}
