// Clase de una calculadora con notacion polaca inversa

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <functional>
#include <typeinfo>

#include "bigint.h"

template <class T,class P>
class Calculator {
 public:
  Calculator();
  void InitOperations();
  void SetTokens(const std::vector<std::vector<std::string>>& tokens);
  T Operate(std::vector<std::string> tokens_line);
  void Process();
  bool CheckStackEmpty();
  bool CheckIsOperands(const std::string&, const std::string&);

  template <class U,class F>
  friend std::ostream& operator<<(std::ostream& os, const Calculator<U,F>& c);

 private:
  std::vector<std::vector<std::string>> tokens;
  std::stack<T> stack;
  std::map<std::string, T> variables;
  std::map<std::string, std::function<T(T, T)>> operations;
  std::map<std::string, std::function<T(T)>> unary_operations;

};

#include "calculator.cc"

#endif  // CALCULATOR_H