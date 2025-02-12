#pragma once

#include <initializer_list>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <ratio>
#include <filesystem>

template <typename T>
class thing {
	T v{};
	std::string state{ "undef" };
public:
	thing() : v(T{}) {
		std::cout << "default constructor\n";
		state = "zero";
	}

	thing(const T& p) : v(p) {
		std::cout << "copy constructor\n";
		state = "copied value";
	}

	thing(const std::initializer_list<T>& list) {
		std::cout << "initializer_list: ";
		for (const auto& e : list) std::cout << e << " ";
		std::cout << "\n";

		const auto sz = list.size();
		auto pt = list.begin();
		if (sz > 1) pt += sz / 2;
		v = *pt;
		state = "list constructed";
	}

	thing(const size_t p1, const T& p2) {
		std::cout << "specific constructor: " << p1 << ", " << p2 << "\n";
		if (p1 < 10) return;
		else v = p2;
		state = "specific value";
	}

	void status() const {
		std::cout << "status: " << state << ", value " << v << "\n";
	}
};

void initialize_this();

struct thing2 {
	int alpha{};
	double bravo{};
	const char* charlie{};
};

constexpr size_t n_samples{ 1000 };
constexpr size_t n_partitions{ 10 };
constexpr size_t n_max{ 50 };

template <typename RNG>
void histogram(const std::string_view& rng_name) {
	auto p_ratio = static_cast<double>(RNG::max() / n_partitions);

	RNG rng{};
	std::vector<size_t> v(n_partitions);
	for (size_t i{}; i < n_samples; ++i) {
		++v[static_cast<size_t>(rng() / p_ratio)];
	}

	auto max_el = std::max_element(v.begin(), v.end());
	auto v_ratio = *max_el / n_max;
	if (v_ratio < 1) v_ratio = 1;

	std::cout << "engine: " << rng_name << "\n";
	for (size_t i{}; i < n_partitions; ++i) {
		std::cout << std::setw(2) << std::right << i + 1 << ":" << std::setfill('*') << std::left << std::setw(v[i] / v_ratio) << " " << "\n";
	}
	std::cout << "\n";
}

constexpr uint64_t MAX_PRIME{ 0x1FFFF };

template<typename T>
concept Callable = requires (T f) { f(); };

std::chrono::duration<double> timed(const Callable auto& f) {
	auto t1 = std::chrono::steady_clock::now();
	auto count = f();
	auto t2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> secs{ t2 - t1 };
	std::cout << "Found " << make_commas(count) << " primes in range\n";
	return secs;
}

uint64_t count_primes2();

std::ostream& operator<<(std::ostream& out, std::filesystem::path& p);
void printdir(const std::filesystem::path& p);
constexpr const char* fp{ "testdir/foo.txt" };
constexpr const char* homedir{ "./" };
