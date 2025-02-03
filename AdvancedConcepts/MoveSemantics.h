#pragma once

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <initializer_list>

template <typename T>
void swap(T& a, T& b) {
	std::cout << "::swap\n";
	T _tmp(std::move(a));
	a = std::move(b);
	b = std::move(_tmp);
}

template<typename T>
class container {
	std::vector<T> things{};
public:
	container();
	container(std::initializer_list<T> il);
	container(const container& rhs);
	container(container&& rhs) noexcept;
	~container();
	void reset();
	container<T>& operator =(container rhs);
	//container<T>& operator =(container&& rhs) noexcept;
	std::string str() const;
};

template<typename T>
inline container<T>::container()
{
	std::cout << "default constructor\n";
}

template<typename T>
inline container<T>::container(std::initializer_list<T> il)
	: things{ il.begin(), il.end() }
{
	std::cout << "initializer-list constructor\n";
}

template<typename T>
inline container<T>::container(const container& rhs) : things{ rhs.things }
{
	std::cout << "copy constructor\n";
}

template<typename T>
inline container<T>::container(container&& rhs) noexcept : things{ std::move(rhs.things) }
{
	std::cout << "move constructor\n";
}

template<typename T>
inline container<T>::~container()
{
	std::cout << "destructor\n";
}

template<typename T>
inline void container<T>::reset()
{
	things.clear();
}

template<typename T>
inline container<T>& container<T>::operator=(container rhs)
{
	std::cout << "copy swap operator\n";
	std::swap(things, rhs.things);
	return *this;
}

template<typename T>
inline container<T>& container<T>::operator=(container&& rhs) noexcept
{
	std::cout << "move assignment operator\n";
	if (this != &rhs) things = std::move(rhs.things);
	return *this;
}

template<typename T>
inline std::string container<T>::str() const
{
	if (things.empty()) return "[empty]";

	std::string out{};
	for (auto i : things) {
		if (out.size()) out+= ":";
		out += i;
	}
	return out;
}

template <typename T>
container<T> f(container<T> o) {
	return o;
}