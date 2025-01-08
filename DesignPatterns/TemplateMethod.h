#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Visitor.h"

class GreetingCardTemplate : public V::Visitor
{
private:
	std::string from;
protected:
	virtual std::string intro(const std::string& to);
	virtual std::string occasion();
	virtual std::string closing(const std::string& from);

public:
	GreetingCardTemplate(const std::string& from) : from(from) {};
	std::string generateCardFor(V::Person *person);
	std::string handlePerson(const std::string& name, int age) override;
};

class BirthdayCardTemplate : public GreetingCardTemplate {
protected:
	std::string occasion() override;
public:
	BirthdayCardTemplate(const std::string& from)
		: GreetingCardTemplate(from) {
	};
};

class NewYearsCardTemplate : public GreetingCardTemplate {
protected:
	std::string intro(const std::string& name) override;
	std::string occasion() override;
public:
	NewYearsCardTemplate(const std::string& from)
		: GreetingCardTemplate(from) {
	};
};

class GreetingCardGenerator {
	GreetingCardTemplate *temp;
	std::vector<V::Person*> people;
public:
	void addPerson(V::Person *p);
	void setTemplate(GreetingCardTemplate* temp);
	std::vector<std::string> sendGreetingCards();
};