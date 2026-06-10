cmake_minimum_required(VERSION 3.10)
project(MathParserEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MathParserEngine
  main.cpp
  src/Parser.cpp
  src/tokenizer.cpp
  src/Evaluator.cpp
  src/sympolTable.cpp
)

target_include_directories(MathParserEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header)