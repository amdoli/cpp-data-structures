#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"
#include <vector>

class Parser{
  public:
    
    int sorter(char tokenValue);

    std::string parse(const std::vector<Token>& tokens);
};

#endif
