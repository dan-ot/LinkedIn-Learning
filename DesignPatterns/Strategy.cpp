#include "Strategy.h"
#include <iostream>

using namespace std;

Person::~Person()
{
	delete greeting;
}

void Person::greet(const string& name)
{
	greeting->greet(name);
}

void FormalGreetingStrategy::greet(const string& name)
{
	cout << "Greetings, " << name << ". Pleased to meet you.\n";
}

void NormalGreetingStrategy::greet(const std::string& name)
{
	cout << "Hello " << name << ".\n";
}

void CoolGreetingStrategy::greet(const std::string& name)
{
	cout << "'Sup " << name << ".\n";
}
