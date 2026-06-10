#include <iostream>
#include "Evaluator.h"


int main(){


  Evaluator evaluate;
  evaluate.setVariable("x" ,"20");
  double result = evaluate.Solve("x+10");
  std::cout << result << std::endl;


  return 0;
}
