#include <iostream>
#include <sstream>
#include "StringValidator2.h"
#include "CommandDomain.h"
#include "Command.h"
#include "Mediator.h"
#include "Observer.h"
#include "Expression.h"

using namespace std;

static string vector_to_string(vector<string> v) {
    stringstream ss;
    for (auto& s : v) {
        ss << s << ", ";
    }
    return ss.str();
}

int main()
{
    auto five = NumberExpression("5");
    auto seven = NumberExpression("7");
    string plus = "+";
    string minus = "-";
    auto fivePlusSeven = OperationExpression(plus, (Expression*)&five, (Expression*)&seven);
    auto thirteen = NumberExpression("13");
    auto thirteenMinusFivePlusSeven = OperationExpression(minus, (Expression*)&thirteen, (Expression*)&fivePlusSeven);

    auto fps = fivePlusSeven.evaluate();

    if (fps.has_value()) {
        cout << "5 + 7 = " << fps.value();
    }
    else {
        cout << "5 + 7 = ERROR";
    }

    auto tmf = thirteenMinusFivePlusSeven.evaluate();

    if (tmf.has_value()) {
        cout << "13 - (5 + 7) = " << tmf.value();
    }
    else {
        cout << "13 - (5 + 7) = ERROR";
    }

    return 0;
}