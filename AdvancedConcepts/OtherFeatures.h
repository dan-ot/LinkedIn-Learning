#pragma once

#include <format>
#include <iostream>
#include <string_view>
#include <numbers>
#include <span>

template <typename T>
struct Frac {
	T n;
	T d;
};

constexpr void print(const std::string_view str_fmt, auto&&... args) {
	fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

template <typename T>
struct std::formatter<Frac<T>> : std::formatter<int> {
	template <typename Context>
	auto format(const Frac<T>& f, Context& ctx) const {
		return std::format_to(ctx.out(), "{}/{}", f.n, f.d);
	}
};

class numOf {
	int a;
public:
	numOf() = delete;
	constexpr numOf(const int& n) : a(n) {}
	constexpr int get() const { return a; }
	auto operator <=> (const numOf& rhs) const = default;
};

class fracOf {
	long n;
	long d;
public:
	fracOf() = delete;
	constexpr fracOf(int a, int b) : n{ a }, d{ b } {}
	constexpr double dbl() const;
	constexpr auto operator <=> (const fracOf& rhs) const;
	constexpr auto operator == (const fracOf& rhs) const;
};

template<typename T>
void pspan(const std::span<T> s) {
	std::cout << "number of elements: " << s.size() << "\n";
	std::cout << "size of span: " << s.size_bytes() << "\n";
	for (auto e : s) std::cout << e << " ";
	std::cout << "\n";
}