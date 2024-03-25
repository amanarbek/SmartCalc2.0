#include "Parser.h"

#include "Token.h"

std::vector<my::Token*>* my::Parser::Parse() {
  Prepare();
  for (auto it = input_.cbegin(); it != input_.cend(); ++it) {
    if (it == input_.cbegin() && *it == '-') {
      tokens_.push_back(
          new Operator("-", Rank::kUnary_minus, TypeToken::kUnary_minus));
      ++it;
    }
    if (std::isdigit(*it) || *it == '.') {
      size_t shift = 0;
      try {
        tokens_.push_back(new Number(std::stod(&*it, &shift), Rank::kNumbers,
                                     TypeToken::kNumbers));
      } catch (std::exception& e) {
        throw std::invalid_argument("Expression error");
      }
      it += shift - 1;
    } else {
      GetString(it);
    }
  }
  return this->Validate().PolishNotation();
}

void my::Parser::Prepare() {
  std::string tmp = std::move(input_);
  for (auto it = tmp.begin(); it != tmp.end(); ++it)
    if (*it != ' ') input_ += std::tolower(*it);
}

void my::Parser::GetString(std::string::const_iterator& it) {
  std::string output;
  if (*it == '-' && *(it - 1) == '(') {
    tokens_.push_back(
        new Operator("-", Rank::kUnary_minus, TypeToken::kUnary_minus));
    return;
  }
  if (*it == 'x') {
    tokens_.push_back(new Number(x_, Rank::kNumbers, TypeToken::kNumbers));
    return;
  }
  if (std::isalpha(*it)) {
    for (; it != input_.cend(); ++it) {
      if (!std::isalpha(*it)) break;
      output.push_back(*it);
    }
    --it;
  } else {
    output.push_back(*it);
  }
  InsertToken(output);
}

void my::Parser::InsertToken(const std::string& input) {
  auto search_token = valid_tokens.find(input);
  if (search_token == valid_tokens.cend())
    throw std::invalid_argument("Invalid token");
  tokens_.push_back(search_token->second);
}

my::Parser& my::Parser::Validate() {
  int count_brackets = 0;
  for (auto it = tokens_.cbegin(); it != tokens_.cend(); ++it) {
    if (it == tokens_.cbegin()) {
      if (!validity_matrix[(int)(*it)->type_token_][6]) {
        throw std::invalid_argument("Expression error");
      }
      if (tokens_.size() > 1 &&
          !validity_matrix[(int)(*it)->type_token_]
                          [(int)(*(it + 1))->type_token_]) {
        throw std::invalid_argument("Expression error");
      }
    } else if (it == tokens_.cend() - 1) {
      if (!validity_matrix[(int)(*it)->type_token_][7]) {
        throw std::invalid_argument("Expression error");
      }
    } else if ((*it)->type_token_ == TypeToken::kOperators) {
      if (!validity_matrix[(int)(*(it - 1))->type_token_]
                          [(int)(*it)->type_token_] ||
          !validity_matrix[(int)(*it)->type_token_]
                          [(int)(*(it + 1))->type_token_]) {
        throw std::invalid_argument("Expression error");
      }
    } else if (!validity_matrix[(int)(*it)->type_token_]
                               [(int)(*(it + 1))->type_token_]) {
      throw std::invalid_argument("Expression error");
    }
    CheckBrackets(it, count_brackets);
  }
  if (count_brackets) throw std::invalid_argument("Brackets error");
  return *this;
}

std::vector<my::Token*>* my::Parser::PolishNotation() {
  std::vector<Token*> tmp = std::move(tokens_);
  for (auto it = tmp.cbegin(); it != tmp.cend(); ++it) {
    if ((*it)->type_token_ == TypeToken::kNumbers) {
      tokens_.push_back(*it);
    } else if ((*it)->type_token_ == TypeToken::kOpen_bracket) {
      operators_.push(*it);
    } else if ((*it)->type_token_ == TypeToken::kClose_bracket) {
      while (!operators_.empty() &&
             operators_.top()->type_token_ != TypeToken::kOpen_bracket) {
        tokens_.push_back(operators_.top());
        operators_.pop();
      }
      operators_.pop();
    } else if ((*it)->type_token_ == TypeToken::kFunctions ||
               (*it)->type_token_ == TypeToken::kOperators ||
               (*it)->type_token_ == TypeToken::kUnary_minus) {
      if (operators_.empty()) {
        operators_.push(*it);
      } else {
        while (!operators_.empty() && operators_.top()->rank_ >= (*it)->rank_) {
          if (operators_.top()->rank_ == Rank::kExponent &&
              (*it)->rank_ == Rank::kExponent)
            break;
          tokens_.push_back(operators_.top());
          operators_.pop();
        }
        operators_.push(*it);
      }
    }
  }
  while (!operators_.empty()) {
    tokens_.push_back(operators_.top());
    operators_.pop();
  }
  return &tokens_;
}

void my::Parser::CheckBrackets(std::vector<Token*>::const_iterator& it,
                               int& count_brackets) {
  if ((*it)->type_token_ == TypeToken::kOpen_bracket)
    ++count_brackets;
  else if ((*it)->type_token_ == TypeToken::kClose_bracket)
    --count_brackets;
  if (count_brackets < 0) throw std::invalid_argument("Brackets error");
}
