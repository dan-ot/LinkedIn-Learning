#pragma once
#include <string>
#include <memory>
#include <optional>
#include <variant>

class Expression;

class OperationExpression {
	std::string operatorSymbol;
	std::shared_ptr<Expression> leftHandSide;
	std::shared_ptr<Expression> rightHandSide;
public:
	OperationExpression(std::string& symbol, std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs)
		: operatorSymbol(symbol), leftHandSide(lhs), rightHandSide(rhs) {};
	std::optional<int> evaluate();
};

class NumberExpression {
	std::string numberString;
public:
	NumberExpression(const std::string& numberString) : numberString(numberString) {}
	std::optional<int> evaluate();
};

class Expression
{
private:
	std::variant<OperationExpression, NumberExpression> expression;
public:
	Expression(std::variant<OperationExpression, NumberExpression> ex) : expression(ex) {};
	std::optional<int> evaluate();
	static Expression Number(std::string number);
	static Expression Operation(std::string symbol, std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs);
};