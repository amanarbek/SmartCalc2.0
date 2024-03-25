#ifndef SMARTCALC_MODEL_TOKEN_H_
#define SMARTCALC_MODEL_TOKEN_H_

#include <string>

namespace my {

enum class Rank {
  kNumbers,
  kBrackets,
  kAdd_sub_operator,
  kMul_div_operator,
  kExponent,
  kUnary_minus,
  kFunctions,
};

enum class TypeToken {
  kNumbers,
  kOperators,
  kOpen_bracket,
  kClose_bracket,
  kFunctions,
  kUnary_minus,
};

class Token {
 public:
  explicit Token(Rank rank, TypeToken type_token)
      : rank_(rank), type_token_(type_token) {}
  Rank rank_;
  TypeToken type_token_;
};

class Number : public Token {
 public:
  explicit Number(double token, Rank rank, TypeToken type_token)
      : Token(rank, type_token), token_(token) {}
  double token_;
};

class Bracket : public Token {
 public:
  explicit Bracket(const std::string& token, Rank rank, TypeToken type_token)
      : Token(rank, type_token), token_(token) {}
  std::string token_;
};

class Operator : public Token {
 public:
 public:
  explicit Operator(const std::string& token, Rank rank, TypeToken type_token)
      : Token(rank, type_token), token_(token) {}
  std::string token_;
};

class Function : public Token {
 public:
  explicit Function(const std::string& token, Rank rank, TypeToken type_token)
      : Token(rank, type_token), token_(token) {}
  std::string token_;
};

};  // namespace my

#endif  // SMARTCALC_MODEL_TOKEN_H_
