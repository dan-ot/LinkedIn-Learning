#pragma once
#include <string>

namespace Visitor {

class Visitor {
public:
	virtual void handlePerson(const std::string& name, const int age) = 0;
	virtual void handleLandmark(const std::string& name, const std::string& cityName) = 0;
	virtual void handleCar(const std::string& make, const std::string& model) = 0;
};

class DatabaseVisitor : public Visitor {
public:
	virtual void handlePerson(const std::string& name, const int age) override;
	virtual void handleLandmark(const std::string& name, const std::string& cityName) override;
	virtual void handleCar(const std::string& make, const std::string& model) override;
};

class TextFileVisitor : public Visitor {
public:
	virtual void handlePerson(const std::string& name, const int age) override;
	virtual void handleLandmark(const std::string& name, const std::string& cityName) override;
	virtual void handleCar(const std::string& make, const std::string& model) override;
};

class Person {
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {};
	void accept(Visitor* visitor);
};

class Landmark {
	std::string name;
	std::string cityName;
public:
	Landmark(const std::string& name, const std::string& cityName) : name(name), cityName(cityName) {};
	void accept(Visitor* visitor);
};

class Car {
	std::string make;
	std::string model;
public:
	Car(const std::string& make, const std::string& model) : make(make), model(model) {};
	void accept(Visitor* visitor);
};

}
