#pragma once
#include <string>
#include <memory>
#include <optional>

class Expression
{
private:
	std::optional<OperationExpression> maybeOperation;
	std::optional<NumberExpression> maybeNumber;
public:

	std::optional<int> evaluate();
	static Expression Number(std::string number);
	static Expression Operation(std::string symbol, Expression lhs, Expression rhs);
};

class OperationExpression : public Expression {
	std::string operatorSymbol;
	std::unique_ptr<Expression> leftHandSide;
	std::unique_ptr<Expression> rightHandSide;
public:
	OperationExpression(std::string& symbol, Expression *lhs, Expression *rhs);
	std::optional<int> evaluate() override;
};

class NumberExpression : public Expression {
	std::string numberString;
public:
	NumberExpression(const std::string& numberString) : numberString(numberString) {}
	std::optional<int> evaluate() override;
};