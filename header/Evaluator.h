#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "tokenizer.h"
#include "linkedlist.h"
#include "Parser.h"
#include <iostream>
#include <vector>

class Evaluator : public Parser {
    public:
    double evaluate(const std::vector<Token>& parsedEquation);
    double solve(const std::string& expression);
};



#endif