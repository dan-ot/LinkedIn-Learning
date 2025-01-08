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
    auto p1 = V::Person("John", 40);
    auto p2 = V::Person("Joan", 80);
    auto p3 = V::Person("Brenda", 25);

    auto generator = GreetingCardGenerator();
    generator.addPerson(&p1);
    generator.addPerson(&p2);
    generator.addPerson(&p3);

    generator.setTemplate(new BirthdayCardTemplate("Bob"));
    auto birthdayCards = generator.sendGreetingCards();

    generator.setTemplate(new NewYearsCardTemplate("Penelope"));
    auto newYearCards = generator.sendGreetingCards();

    for (auto &card : birthdayCards) {
        cout << card;
    }

    for (auto& card : newYearCards) {
        cout << card;
    }

    return 0;
}