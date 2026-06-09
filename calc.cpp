#include <iostream>
#include "Evaluator.h"


int main(){


  Evaluator evaluate;

  double result = evaluate.Solve("324/34");
  std::cout << result << std::endl;


  return 0;
}
