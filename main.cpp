#include "linkedlist.h"
#include "Parser.h"
#include "tokenizer.h"
#include <iostream>

int main(){
  
  Tokenizer Sorterer;
  // if you will do that manually you have to write .value = "25" .TokenType = Number
  // Insted of tokenize it manually by yourself, Sorterer.tokenize do that for you automatically!
  std::vector<Token> equation = Sorterer.tokenize("25 + 5 - 12 * 43 /4");

  Parser mathParser;

  mathParser.parse(equation);


}
