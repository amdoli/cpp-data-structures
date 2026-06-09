#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <string>

enum class TokenType{
  Number,
  Variable,
  Operator,
  LeftParen,
  RightParen
};

struct Token {
  TokenType type;
  std::string value;
};

class Tokenizer {
  public:
    std::vector<Token> tokenize(const std::string& expression);
};

#endif 
