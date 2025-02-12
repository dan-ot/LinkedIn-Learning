#include "OtherSubjects.h"

#include "Concurrency.h"
#include <vector>
#include <iostream>

using namespace std;

void initialize_this() {
	cout << "t1: ";
	thing<int> t1{};
	t1.status();
	cout << endl;

	cout << "t2: ";
	thing<int> t2{ 7 };
	t2.status();
	cout << endl;

	cout << "t3: ";
	thing t3(42);
	t3.status();
	cout << endl;

	cout << "t4: ";
	thing<int> t4{ 1, 2, 3, 4, 5 };
	t4.status();
	cout << endl;

	cout << "t5: ";
	thing<int> t5{ 1, 2 };
	t5.status();
	cout << endl;

	cout << "t6: ";
	thing<int> t6(1, 2);
	t6.status();
	cout << endl;
}

//std::chrono::duration<double> timed(const Callable auto& f) {
//	auto t1 = std::chrono::steady_clock::now();
//	auto count = f();
//	auto t2 = std::chrono::steady_clock::now();
//	std::chrono::duration<double> secs{ t2 - t1 };
//	std::cout << "Found " << make_commas(count) << " primes in range\n";
//	return secs;
//}
uint64_t count_primes2() {
	constexpr auto isprime = [](const uint64_t n) {
		for (uint64_t i{ 2 }; i < n / 2; ++i) {
			if (n % i == 0) return false;
		}
		return true;
		};

	uint64_t count{ 0 };
	uint64_t start{ 2 };
	uint64_t end{ MAX_PRIME };
	for (uint64_t i{ start }; i <= end; ++i) {
		if (isprime(i)) count++;
	}
	return count;
}

ostream& operator<<(ostream& out, filesystem::path& p)
{
	out << p.string();
	return out;
}

void printdir(const filesystem::path& p)
{
	vector<filesystem::directory_entry> dir{};

	auto dircmp = [](const filesystem::directory_entry& lhs, const filesystem::directory_entry& rhs) -> bool {
		return lhs.path().string() < rhs.path().string();
		};

	if (filesystem::exists(p) == false) {
		cout << filesystem::absolute(p) << " does not exist\n";
		return;
	}

	if (filesystem::is_directory(p)) {
		for (const auto& de : filesystem::directory_iterator(p)) {
			dir.emplace_back(de);
		}
		sort(dir.begin(), dir.end(), dircmp);
		for (const auto& e : dir) {
			cout << filesystem::relative(e, p) << " ";
		}
		cout << "\n";
	}
	else {
		cout << "not a directory: " << p;
	}
}
