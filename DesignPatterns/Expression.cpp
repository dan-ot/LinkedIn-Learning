#include "Expression.h"
#include <iostream>

using namespace std;

OperationExpression::OperationExpression(string& symbol, Expression *lhs, Expression *rhs)
{
	operatorSymbol = symbol;
	leftHandSide = make_unique<Expression>(*lhs);
	rightHandSide = make_unique<Expression>(*rhs);
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

std::optional<int> NumberExpression::evaluate()
{
	return stoi(numberString);
}
