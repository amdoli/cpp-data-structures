#include "linkedlist.h"
#include "Parser.h"
#include "tokenizer.h"
#include "Evaluator.h"
#include <iostream>

int main(){
  
  Tokenizer Sorterer;

  // if you will do that manually you have to write .value = "25" .TokenType = Number
  // Insted of tokenize it manually by yourself, Sorterer.tokenize do that for you automatically!
  
  std::vector<Token> equation = Sorterer.tokenize("25 + 5 - 12 * 43 /4");

  Parser mathParser;

  mathParser.parse(equation);
  // OUTPUT: 25 5 + 12 43 * 4 / -

  // I have showed you how my programs communicate under the hood
  // but you don't have to write all that!
  // you can just write this:
  
  std::vector<Token> parsedEquation = mathParser.forceParse("25 + 5 - 12 * 43 /4");
  // OUTPUT: 25 5 + 12 43 * 4 / -

  Evaluator evaluator;

  double result = evaluator.evaluate(parsedEquation);
  // OUTPUT: -99

  std::cout << result << std::endl;


}
