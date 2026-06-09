#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "tokenizer.h"
#include "linkedlist.h"
#include <iostream>
#include <vector>

class Evaluator {
    public:
    double evaluate(const std::vector<Token>& parsedEquation);
    double Solve(const std::string& expression);
};



#endif