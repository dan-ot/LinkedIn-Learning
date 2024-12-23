#include <iostream>
#include <sstream>
#include "StringValidator2.h"
#include "CommandDomain.h"
#include "Command.h"
#include "Mediator.h"
#include "Observer.h"
#include "State.h"
#include "Strategy.h"

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
    auto business = Person(new FormalGreetingStrategy());
    auto normal = Person(new NormalGreetingStrategy());
    auto cool = Person(new CoolGreetingStrategy());
    auto politician = Person(new FormalGreetingStrategy());

    cout << "The businessperson says ";
    business.greet("Shaun");

    cout << "The normal person says ";
    normal.greet("Shaun");

    cout << "The cool person says ";
    cool.greet("Shaun");

    cout << "The politician says ";
    politician.greet("Shaun");

    return 0;
}