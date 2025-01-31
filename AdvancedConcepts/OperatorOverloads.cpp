#include "OperatorOverloads.h"
#include <iostream>

using namespace std;

Rational::~Rational()
{
	n = 0;
	d = 1;
}

int Rational::numerator() const
{
	return n;
}

int Rational::denominator() const
{
	return d;
}

Rational Rational::reduce() const
{
	if (n == 0 || d <= 3) return *this;
	
	for (auto div = d - 1; div > 0; --div) {
		if (n % div == 0 && d % div == 0) {
			return Rational(n / div, d / div);
		}
	}

	return *this;
}

std::string Rational::str() const
{
	if (d == 0) return nanstr;
	if (d == 1 || n == 0) return to_string(n);

	auto abs_n = abs(n);
	if (abs_n > d) {
		auto whole = n / d;
		auto remainder = abs_n % d;
		if (remainder) return to_string(whole) + " " + Rational(remainder, d).str();
		else return to_string(whole);
	}
	else {
		return reduce().raw_str();
	}
}

std::string Rational::raw_str() const
{
	return to_string(n) + "/" + to_string(d);
}

Rational& Rational::operator=(const Rational& rhs)
{
	if (this != &rhs) {
		n = rhs.numerator();
		d = rhs.denominator();
	}

	return *this;
}

Rational::operator string() const
{
	return str();
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	return Rational((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

ostream& operator<<(ostream& out, const Rational& rational)
{
	out << rational.str();
	return out;
}

int num::value() const
{
	return _value;
}

void num::value(int x)
{
	_value = x;
}

num::operator int()
{
	return _value;
}

num& num::operator++()
{
	cout << "Pre-increment: ";
	_value += 1;
	return *this;
}

num num::operator++(int)
{
	cout << "Post-increment: ";
	auto temp = *this;
	_value += 1;
	return temp;
}

num& num::operator--()
{
	cout << "Pre-decrement: ";
	_value -= 1;
	return *this;
}

num num::operator--(int)
{
	cout << "Post-decrement: ";
	auto temp = *this;
	_value -= 1;
	return temp;
}

int MultBy::operator()(int n) const
{
	return mult * n;
}
