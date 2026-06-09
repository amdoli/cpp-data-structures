#include "Evaluator.h"
#include "tokenizer.h"
#include "linkedlist.h"
#include "Parser.h"

#include <iostream>
#include <vector>
#include <string>

double Evaluator::evaluate (const std::vector<Token>& parsedEquation) {

    linkedList<double> NumbersStack;

    for (int i = 0; i < parsedEquation.size(); i++) {
        if ( parsedEquation[i].type == TokenType::Number ) 
        {
            NumbersStack.insert( std::stod(parsedEquation[i].value) );
        }
        if ( parsedEquation[i].type == TokenType::Operator) 
        {
            char Operator = parsedEquation[i].value[0];

            double firstNumber = NumbersStack.showTheTop();
            NumbersStack.deleteValue(firstNumber);

            double secondNumber = NumbersStack.showTheTop();
            NumbersStack.deleteValue(secondNumber);

            double result = 0.0;

            switch (Operator) {
                case '+':
                    result = secondNumber + firstNumber;
                    NumbersStack.insert(result);      
                    break;

                case '-':
                    result = secondNumber - firstNumber;
                    NumbersStack.insert(result);  
                    break;

                case '*':
                    result = secondNumber * firstNumber;
                    NumbersStack.insert(result);   
                    break;

                case '/':
                    result = secondNumber / firstNumber;
                    NumbersStack.insert(result);  
                    break;
            }
        }
    }

    double result = NumbersStack.showTheTop();

    NumbersStack.freeAll();
    return result;
   

}

double Evaluator::Solve (const std::string& expression) {
    
    Parser parser;
    std::vector<Token> parsedEquation = parser.forceParse(expression);
    return evaluate(parsedEquation);

}