#include <iostream>
#include <sstream>
#include "StringValidator2.h"
#include "CommandDomain.h"
#include "Command.h"
#include "Mediator.h"
#include "Observer.h"
#include "State.h"
#include "Strategy.h"
#include "TemplateMethod.h"

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
    auto gct = GreetingCardTemplate();
    auto bct = BirthdayCardTemplate();
    auto nyt = NewYearsCardTemplate();

    cout << "Greeting:\n";
    cout << gct.generate("A", "B");

    cout << "Birthday:\n";
    cout << bct.generate("A", "B");

    cout << "New Year's:\n";
    cout << nyt.generate("A", "B");

    return 0;
}