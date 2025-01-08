#pragma once
#include <string>

namespace V {

class Visitor {
public:
	virtual std::string handlePerson(const std::string& name, const int age) = 0;
};

class DatabaseVisitor : public Visitor {
public:
	virtual std::string handlePerson(const std::string& name, const int age) override;
};

class TextFileVisitor : public Visitor {
public:
	virtual std::string handlePerson(const std::string& name, const int age) override;
};

class Person {
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {};
	std::string accept(Visitor* visitor);
};

class Landmark {
	std::string name;
	std::string cityName;
public:
	Landmark(const std::string& name, const std::string& cityName) : name(name), cityName(cityName) {};
};

class Car {
	std::string make;
	std::string model;
public:
	Car(const std::string& make, const std::string& model) : make(make), model(model) {};
};

}
