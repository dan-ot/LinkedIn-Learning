#include "Visitor.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace V {

string DatabaseVisitor::handlePerson(const std::string& name, const int age)
{
	auto ss = stringstream();
	ss << "Database - " << name << ", " << age << "\n";
	return ss.str();
}

string TextFileVisitor::handlePerson(const std::string& name, const int age)
{
	auto ss = stringstream();
	ss << "Text File - " << name << ", " << age << "\n";
	return ss.str();
}

string Person::accept(Visitor* visitor)
{
	return visitor->handlePerson(name, age);
}

}
