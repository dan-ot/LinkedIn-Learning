#include "Concurrency.h"

prime_time count_primes(const uint64_t& max)
{
	prime_time ret{};
	constexpr auto isprime = [](uint64_t n) {
		for (uint64_t i{ 2 }; i < n / 2; ++i) {
			if (n % i == 0) return false;
		}
		return true;
		};
	uint64_t start{ 2 };
	uint64_t end{ max };
	auto time_thread_start = std::chrono::steady_clock::now();
	for (auto i = start; i <= end; ++i) {
		if (isprime(i)) ++ret.count;
	}

	ret.dur = std::chrono::steady_clock::now() - time_thread_start;
	return ret;
}

std::string make_commas(const uint64_t& num) {
	auto s = std::to_string(num);
	for (auto l = static_cast<int>(s.length()) - 3; l > 0; l -= 3) {
		s.insert(l, ",");
	}
	return s;
}

void sleep_ms(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void countem(int id) {
	while (!ready) std::this_thread::yield();
	for (auto i = 0; i < max_count; ++i) {
		if (winner.test()) return;
		++g_count;
	}
	if (!winner.test_and_set()) {
		std::cout << "Thread " << id << " won!\n";
		winner.notify_all();
	}
}

void producer() {
	for (size_t i{}; i < num_items; ++i) {
		sleep_ms(delay_time);
		std::cout << "push " << i << " on the queue\n";
		std::lock_guard<std::mutex> lck{ p_mtx };
		q.push_back(i);
	}

	std::lock_guard<std::mutex> lck{ p_mtx };
	finished.test_and_set();
}

void consumer() {
	while (!finished.test()) {
		sleep_ms(delay_time * 3);
		std::lock_guard<std::mutex> lck{ c_mtx };
		while (!q.empty()) {
			std::cout << "pop " << q.front() << " from the queue\n";
			q.pop_front();
		}
	}
}