#pragma once

#include <optional>
#include <any>
#include <string_view>
#include <iostream>

static std::optional<long> factor(long n);

static std::ostream& operator <<(std::ostream& out, const std::any& o);

class Animal {
	std::string_view _name{};
	std::string_view _sound{};
public:
	Animal() = delete;
	Animal(std::string_view n, std::string_view s) : _name{ n }, _sound{ s } {};

	void speak() const {
		std::cout << _name << " says " << _sound << "\n";
	}

	void sound(std::string_view s) {
		_sound = s;
	}
};

class Cat : public Animal {
public:
	Cat(std::string_view n) : Animal(n, "meow") {};
};

class Dog : public Animal {
public:
	Dog(std::string_view n) : Animal(n, "arf!") {};
};

class Wookiee : public Animal {
public:
	Wookiee(std::string_view n) : Animal(n, "grrraaarrgghh!") {};
};

struct animal_speaks {
	void operator()(const Dog& d) const { d.speak(); }
	void operator()(const Cat& c) const { c.speak(); }
	void operator()(const Wookiee& w) const { w.speak(); }
};
