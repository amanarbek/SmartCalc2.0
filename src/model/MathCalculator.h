#ifndef SMARTCALC_MODEL_MATHCALCULATOR_H_
#define SMARTCALC_MODEL_MATHCALCULATOR_H_

#include <cmath>
#include <functional>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "Parser.h"
#include "Token.h"

namespace my {

class MathCalculator {
 public:
  MathCalculator() = default;
  ~MathCalculator() = default;

  double Calculate(std::string input, double x = 0.0);

 private:
  std::vector<Token*>* tokens_;
  std::stack<double> operands_;
  const std::map<std::string, std::function<double(double, double)>>
      functions_for_count{
          {"+", [](double arg_1, double arg_2) { return arg_1 + arg_2; }},
          {"-", [](double arg_1, double arg_2) { return arg_1 - arg_2; }},
          {"*", [](double arg_1, double arg_2) { return arg_1 * arg_2; }},
          {"/", [](double arg_1, double arg_2) { return arg_1 / arg_2; }},
          {"^", [](double arg_1, double arg_2) { return pow(arg_1, arg_2); }},
          {"sin",
           [](double arg_1, double arg_2 = 0.0) { return sin(arg_1 + arg_2); }},
          {"cos",
           [](double arg_1, double arg_2 = 0.0) { return cos(arg_1 + arg_2); }},
          {"tan",
           [](double arg_1, double arg_2 = 0.0) { return tan(arg_1 + arg_2); }},
          {"asin", [](double arg_1,
                      double arg_2 = 0.0) { return asin(arg_1 + arg_2); }},
          {"acos", [](double arg_1,
                      double arg_2 = 0.0) { return acos(arg_1 + arg_2); }},
          {"atan", [](double arg_1,
                      double arg_2 = 0.0) { return atan(arg_1 + arg_2); }},
          {"sqrt", [](double arg_1,
                      double arg_2 = 0.0) { return sqrt(arg_1 + arg_2); }},
          {"mod",
           [](double arg_1, double arg_2) { return fmod(arg_1, arg_2); }},
          {"log", [](double arg_1,
                     double arg_2 = 0.0) { return log10(arg_1 + arg_2); }},
          {"ln", [](double arg_1, double arg_2 = 0.0) {
             return log(arg_1 + arg_2);
           }}};
};

};  // namespace my

#endif  // SMARTCALC_MODEL_MATHCALCULATOR_H_
