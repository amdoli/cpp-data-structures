#include "linkedlist.h"
#include "Parser.h"
#include "tokenizer.h"
#include <iostream>

int main(){
  
  Tokenizer Sorterer;

  std::vector<Token> equation = Sorterer.tokenize("5 + 4 * 3");

  Parser mathParser;
  mathParser.parse(equation);
  



}
