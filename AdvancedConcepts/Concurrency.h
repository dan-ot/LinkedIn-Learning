#pragma once
#include <chrono>
#include <thread>
#include <iostream>
#include <list>
#include <deque>
#include <future>
#include <mutex>
#include <optional>
#include <atomic>
#include <string>

static void sleepms(const unsigned ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

static void thread_func(const int n) {
	std::cout << "This is " << n << "\n";
	auto sleep_duration = 100 * n;

	for (auto i = 0; i < 5; ++i) {
		sleepms(sleep_duration);
		std::cout << "t" << n << " (" << sleep_duration << "ms): loop " << i + 1 << "\n";
	}
	std::cout << "Finishing t" << n << "\n";
}

struct prime_time {
	std::chrono::duration<double> dur{};
	uint64_t count{};
};

prime_time count_primes(const uint64_t& max);

static std::mutex animal_mutex{};

class AnimalC {
	using friend_t = std::list<AnimalC>;
	std::string_view s_name{ "unk" };
	friend_t l_friends{};
public:
	AnimalC() = delete;
	AnimalC(const std::string_view n) : s_name(n) {}

	bool operator ==(const AnimalC& o) const {
		return s_name.data() == o.s_name.data();
	}

	bool add_friend(AnimalC& o) noexcept {
		std::cout << "add_friend " << s_name << " -> " << o.s_name << "\n";
		if (*this == o) return false;

		std::lock_guard<std::mutex> l{ animal_mutex };
		if (!is_friend(o)) l_friends.emplace_back(o);
		if (!o.is_friend(*this)) o.l_friends.emplace_back(*this);

		return true;
	}

	bool delete_friend(AnimalC& o) noexcept {
		std::cout << "delte_friend " << s_name << " <-> " << o.s_name << "\n";
		if (*this == o) return false;

		std::lock_guard<std::mutex> l{ animal_mutex };
		if (auto it = find_friend(o); it) l_friends.erase(it.value());
		if (auto it = o.find_friend(o); it) o.l_friends.erase(it.value());

		return true;
	}

	bool is_friend(const AnimalC& o) const {
		for (const auto& a : l_friends) {
			if (a == o) return true;
		}
		
		return false;
	}

	std::optional<friend_t::iterator> find_friend(const AnimalC& o) noexcept {
		for (auto it = l_friends.begin(); it != l_friends.end(); ++it) {
			if (*it == o) return it;
		}

		return {};
	}

	void pfriends() const noexcept {
		std::lock_guard<std::mutex> l{ animal_mutex };
		auto n_animals = l_friends.size();
		std::cout << s_name << " friends: \n";
		if (!n_animals) std::cout << " none\n";
		else {
			for (auto& n : l_friends) {
				std::cout << n.s_name;
				if (--n_animals) std::cout << ", ";
			}
		}
		std::cout << "\n";
	}
};

static std::atomic_bool ready{};
static std::atomic_uint64_t g_count{};
static std::atomic_flag winner{};

constexpr uint64_t max_count{ 1'000'000 };
constexpr int max_threads{ 100 };

std::string make_commas(const uint64_t& num);

void sleep_ms(int ms);

void countem(int id);

constexpr size_t num_items{ 10 };
constexpr int delay_time{ 250 };

static std::mutex p_mtx{};
static std::mutex c_mtx{};
static std::deque<size_t> q{};
static std::atomic_flag finished{};

void producer();

void consumer();
