#include "TemplateMethod.h"
#include <sstream>

using namespace std;
using namespace V;

string GreetingCardTemplate::intro(const string& to)
{
    return "Dear " + to + ",\n";
}

string GreetingCardTemplate::occasion()
{
    return "Just writing to say hi! Hope all is well with you.";
}

string GreetingCardTemplate::closing(const string& from)
{
    return "Sincerely,\n" + from + "\n";
}

string GreetingCardTemplate::generateCardFor(Person* person)
{
    return person->accept(this);
}

string GreetingCardTemplate::handlePerson(const std::string& name, int age)
{
    auto ss = stringstream();
    ss << "Sending this card to: " << name << ":\n\n"
        << intro(name) << occasion() << closing(from) << "\n";
    return ss.str();
}

string BirthdayCardTemplate::occasion()
{
    return "Happy birthday! Hope you have a wonderful day and lots of cake.";
}

string NewYearsCardTemplate::intro(const string& name)
{
    return name + "!!!\n";
}

string NewYearsCardTemplate::occasion()
{
    return "Happy New Year!! See you at the gym tomorrow...\n";
}

void GreetingCardGenerator::addPerson(Person* p)
{
    people.push_back(p);
}

void GreetingCardGenerator::setTemplate(GreetingCardTemplate* t)
{
    temp = t;
}

vector<string> GreetingCardGenerator::sendGreetingCards()
{
    auto cards = vector<string>(people.size());
    for (auto & person : people) {
        cards.push_back(temp->generateCardFor(person));
    }
    return cards;
}
