#include "Expression.h"
#include <iostream>

using namespace std;

optional<int> Expression::evaluate() {
	if (get_if<OperationExpression>(&expression)) {
		return get_if<OperationExpression>(&expression)->evaluate();
	}
	else {
		return get_if<NumberExpression>(&expression)->evaluate();
	}
}

Expression Expression::Number(std::string number)
{
	return Expression(NumberExpression(number));
}

Expression Expression::Operation(std::string symbol, shared_ptr<Expression> lhs, shared_ptr<Expression> rhs)
{
	return Expression(OperationExpression(symbol, lhs, rhs));
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
