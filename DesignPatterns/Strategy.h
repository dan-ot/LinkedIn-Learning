#pragma once
#include <string>

class GreetingStrategy
{
public:
	virtual void greet(const std::string& name) = 0;
};

class FormalGreetingStrategy : public GreetingStrategy {
	void greet(const std::string& name) override;
};

class NormalGreetingStrategy : public GreetingStrategy {
	void greet(const std::string& name) override;
};

class CoolGreetingStrategy : public GreetingStrategy {
	void greet(const std::string& name) override;
};

class Person {
	GreetingStrategy* greeting;
public:
	Person(GreetingStrategy* greeting) : greeting(greeting) {};
	~Person();
	void greet(const std::string& name);
};