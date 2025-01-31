#pragma once
#include <string>
#include <format>
#include <ostream>

const std::string nanstr{ "[NAN]" };

class Rational {
	int n{ 0 };
	int d{ 1 };
public:
	Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {};
	Rational(const Rational& rhs) : n(rhs.n), d(rhs.d) {};
	~Rational();
	int numerator() const;
	int denominator() const;
	Rational reduce() const;
	std::string str() const;
	std::string raw_str() const;
	Rational& operator =(const Rational&);
	operator std::string() const;
};

std::ostream& operator <<(std::ostream& out, const Rational& rational);
Rational operator -(const Rational& lhs, const Rational& rhs);
Rational operator *(const Rational& lhs, const Rational& rhs);
Rational operator /(const Rational& lhs, const Rational& rhs);
Rational operator +(const Rational& lhs, const Rational& rhs);


template <>
struct std::formatter<Rational> : std::formatter<unsigned> {
	template<typename FormatContext>
	auto format(const Rational& o, FormatContext& ctx) {
		return std::format_to(ctx.out(), "{}", o.str());
	}
};

class num {
	int _value;
public:
	num(int x = 0) : _value(x) {};
	int value() const;
	void value(int x);
	operator int();
	num& operator++();
	num operator ++(int);
	num& operator--();
	num operator --(int);
};

class MultBy {
	int mult;
public:
	MultBy(int n = 1) : mult(n) {};
	int operator() (int n) const;
};