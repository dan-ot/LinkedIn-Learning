#include "TemplateMethod.h"

std::string GreetingCardTemplate::intro(const std::string& to)
{
    return "Dear " + to + ",\n";
}

std::string GreetingCardTemplate::occasion()
{
    return "Just writing to say hi! Hope all is well with you.";
}

std::string GreetingCardTemplate::closing(const std::string& from)
{
    return "Sincerely,\n" + from + "\n";
}

std::string GreetingCardTemplate::generate(const std::string& to, const std::string& from)
{
    return intro(to) + occasion() + closing(from);
}

std::string BirthdayCardTemplate::occasion()
{
    return "Happy birthday! Hope you have a wonderful day and lots of cake.";
}

std::string NewYearsCardTemplate::intro(const std::string& name)
{
    return name + "!!!\n";
}

std::string NewYearsCardTemplate::occasion()
{
    return "Happy New Year!! See you at the gym tomorrow...\n";
}
