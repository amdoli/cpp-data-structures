cmake_minimum_required(VERSION 3.10)
project(MathParserEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(engine
  calc.cpp
  Parser.cpp
  tokenizer.cpp
  Evaluator.cpp
)
