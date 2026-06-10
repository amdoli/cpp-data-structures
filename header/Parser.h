#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"
#include "sympolTable.h"
#include <vector>

class Parser : public SympolTable{

  public:
    
    int sorter(char tokenValue);

    std::vector<Token> parse(const std::vector<Token>& tokens);
    std::vector<Token> forceParse(const std::string& expressino);
};

#endif
