#include "Visitor.h"
#include <iostream>

using namespace std;

namespace Visitor {

void DatabaseVisitor::handlePerson(const std::string& name, const int age)
{
	cout << "Database - " << name << ", " << age << "\n";
}

void DatabaseVisitor::handleLandmark(const std::string& name, const std::string& cityName)
{
	cout << "Database - " << name << ", " << cityName << "\n";
}

void DatabaseVisitor::handleCar(const std::string& make, const std::string& model)
{
	cout << "Database - " << make << " " << model << "\n";
}

void TextFileVisitor::handlePerson(const std::string& name, const int age)
{
	cout << "Text File - " << name << ", " << age << "\n";
}

void TextFileVisitor::handleLandmark(const std::string& name, const std::string& cityName)
{
	cout << "Text File - " << name << ", " << cityName << "\n";
}

void TextFileVisitor::handleCar(const std::string& make, const std::string& model)
{
	cout << "Text File - " << make << " " << model << "\n";
}

void Person::accept(Visitor* visitor)
{
	visitor->handlePerson(name, age);
}

void Car::accept(Visitor* visitor)
{
	visitor->handleCar(make, model);
}

void Landmark::accept(Visitor* visitor)
{
	visitor->handleLandmark(name, cityName);
}

}
