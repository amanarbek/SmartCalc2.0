#include "MathCalculator.h"

double my::MathCalculator::Calculate(std::string input, double x) {
  Parser parser_(input, x);
  double left_operand = 0;
  double right_operand = 0;
  tokens_ = parser_.Parse();
  if (tokens_->empty()) return 0;
  for (auto it = tokens_->cbegin(); it != tokens_->cend(); ++it) {
    if ((*it)->type_token_ == TypeToken::kNumbers) {
      operands_.push(static_cast<Number*>(*it)->token_);
    } else if ((*it)->type_token_ == TypeToken::kUnary_minus) {
      left_operand = operands_.top();
      operands_.pop();
      operands_.push(-left_operand);
    } else if ((*it)->type_token_ == TypeToken::kOperators) {
      right_operand = operands_.top();
      operands_.pop();
      left_operand = operands_.top();
      operands_.pop();
      left_operand =
          functions_for_count.find(static_cast<Operator*>(*it)->token_)
              ->second(left_operand, right_operand);
      operands_.push(left_operand);
    } else {
      left_operand = operands_.top();
      operands_.pop();
      left_operand =
          functions_for_count.find(static_cast<Function*>(*it)->token_)
              ->second(left_operand, 0.0);
      operands_.push(left_operand);
    }
  }
  left_operand = operands_.top();
  operands_.pop();
  return left_operand;
}
