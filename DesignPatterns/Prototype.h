#pragma once
#include <string>

class Animal {
protected:
	std::string _hairColor;
	int _hairLength, _tail, _weight, _height, _age;
	int _intelligence, _stubbornness, _aggressiveness;

public:
	virtual Animal* clone() = 0;

	void setHairLength(const int length) { _hairLength = length; }
	void setHairColor(const std::string& color) { _hairColor = color; }
	void setTail(const int length) { _tail = length; }
	void setWeight(const int kg) { _weight = kg; }
	void setHeight(const int m) { _height = m; }
	void setAge(const int age) { _age = age; }
};

class Sheep : public Animal {
public:
	Sheep() {
		_hairLength = 5;
		_stubbornness = 3;
		_aggressiveness = 2;
		_intelligence = 7;
	}
	Sheep* clone() override { return new Sheep(*this); }
	void shear() { _hairLength -= 2; }
};

class Cow : public Animal {
public:
	Cow() {
		_stubbornness = 6;
		_aggressiveness = 5;
		_intelligence = 8;
	}
	Cow* clone() override { return new Cow(*this); }
};