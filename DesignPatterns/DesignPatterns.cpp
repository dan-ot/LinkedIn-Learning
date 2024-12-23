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
#include "Visitor.h"

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
    auto person = Visitor::Person("John", 48);
    auto landmark = Visitor::Landmark("Eiffel Tower", "Paris");
    auto car = Visitor::Car("Chevy", "Spark");

    Visitor::Visitor* dbv = new Visitor::DatabaseVisitor();
    Visitor::Visitor* tfv = new Visitor::TextFileVisitor();

    person.accept(dbv);
    person.accept(tfv);

    landmark.accept(dbv);
    landmark.accept(tfv);

    car.accept(dbv);
    car.accept(tfv);

    return 0;
}