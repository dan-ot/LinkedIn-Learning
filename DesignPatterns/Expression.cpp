#include "Expression.h"
#include <iostream>

using namespace std;

optional<int> Expression::evaluate() {
	if (maybeOperation.has_value()) {
		return maybeOperation.value().evaluate();
	}
	else {
		return maybeNumber.value().evaluate();
	}
}

Expression Expression::Number(std::string number)
{
	auto ex = Expression();
	ex.maybeNumber = optional<NumberExpression>(NumberExpression(number));
	return ex;
}

Expression Expression::Operation(std::string symbol, Expression& lhs, Expression& rhs)
{
	auto ex = Expression();
	ex.maybeOperation = optional<OperationExpression>(OperationExpression(symbol, lhs, rhs));
	return ex;
}

OperationExpression::OperationExpression(string& symbol, Expression& lhs, Expression& rhs)
{
	operatorSymbol = symbol;
	leftHandSide = make_unique<Expression>(lhs);
	rightHandSide = make_unique<Expression>(rhs);
}

optional<int> OperationExpression::evaluate()
{
	auto lhs = leftHandSide->evaluate();
	auto rhs = rightHandSide->evaluate();
	if (lhs.has_value() && rhs.has_value()) {
		if (operatorSymbol == "+") {
			return lhs.value() + rhs.value();
		}
		else if (operatorSymbol == "-") {
			return lhs.value() - rhs.value();
		}
		else {
			cout << "Unrecognized operator: " << operatorSymbol;
			return optional<int>();
		}
	}
	else {
		cout << "Evaluation failure.";
		return optional<int>();
	}
}

optional<int> NumberExpression::evaluate()
{
	return stoi(numberString);
}
