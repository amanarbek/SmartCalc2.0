#ifndef SMARTCALC_MODEL_PARSER_H_
#define SMARTCALC_MODEL_PARSER_H_

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "Token.h"

namespace my {

class Parser {
 public:
  explicit Parser(const std::string& input, double x) : input_(input), x_(x) {}
  ~Parser() {
    for (auto it = tokens_.begin(); it != tokens_.end(); ++it)
      if ((*it)->type_token_ == TypeToken::kNumbers ||
          (*it)->type_token_ == TypeToken::kUnary_minus)
        delete *it;
    for (auto it = valid_tokens.begin(); it != valid_tokens.end(); ++it)
      delete it->second;
  }
  std::vector<Token*>* Parse();
  void Prepare();
  void GetString(std::string::const_iterator& it);
  void InsertToken(const std::string& input);
  Parser& Validate();
  std::vector<Token*>* PolishNotation();
  void CheckBrackets(std::vector<Token*>::const_iterator& it,
                     int& count_brackets);

 private:
  const std::map<const std::string, Token*> valid_tokens{
      {"+", new Operator("+", Rank::kAdd_sub_operator, TypeToken::kOperators)},
      {"-", new Operator("-", Rank::kAdd_sub_operator, TypeToken::kOperators)},
      {"*", new Operator("*", Rank::kMul_div_operator, TypeToken::kOperators)},
      {"/", new Operator("/", Rank::kMul_div_operator, TypeToken::kOperators)},
      {"(", new Bracket("(", Rank::kBrackets, TypeToken::kOpen_bracket)},
      {")", new Bracket(")", Rank::kBrackets, TypeToken::kClose_bracket)},
      {"^", new Operator("^", Rank::kExponent, TypeToken::kOperators)},
      {"sin", new Function("sin", Rank::kFunctions, TypeToken::kFunctions)},
      {"cos", new Function("cos", Rank::kFunctions, TypeToken::kFunctions)},
      {"tan", new Function("tan", Rank::kFunctions, TypeToken::kFunctions)},
      {"asin", new Function("asin", Rank::kFunctions, TypeToken::kFunctions)},
      {"acos", new Function("acos", Rank::kFunctions, TypeToken::kFunctions)},
      {"atan", new Function("atan", Rank::kFunctions, TypeToken::kFunctions)},
      {"sqrt", new Function("sqrt", Rank::kFunctions, TypeToken::kFunctions)},
      {"mod", new Function("mod", Rank::kFunctions, TypeToken::kOperators)},
      {"log", new Function("log", Rank::kFunctions, TypeToken::kFunctions)},
      {"ln", new Function("ln", Rank::kFunctions, TypeToken::kFunctions)}};
  static constexpr bool validity_matrix[][8] = {
      {0, 1, 0, 1, 0, 0, 1, 1},  //  0: numbers
      {1, 0, 1, 0, 1, 0, 0, 0},  //  1: operators
      {1, 0, 1, 0, 1, 1, 1, 0},  //  2: open bracket
      {0, 1, 0, 1, 0, 0, 0, 1},  //  3: close bracket
      {0, 0, 1, 0, 0, 0, 1, 0},  //  4: functions
      {1, 0, 1, 0, 1, 0, 1, 0},  //  5: unary_minus
                                 //  6: begin token
                                 //  7: end token
  };
  std::string input_;
  double x_;
  std::stack<Token*> operators_;
  std::vector<Token*> tokens_;
};

};  // namespace my

#endif  // SMARTCALC_MODEL_PARSER_H_
