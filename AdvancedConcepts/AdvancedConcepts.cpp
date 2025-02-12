// AdvancedConcepts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <concepts>
#include <variant>
#include <tuple>
#include <chrono>
#include <random>
#include <ratio>

#include "OperatorOverloads.h"
#include "MoveSemantics.h"
#include "OptionalsVariants.h"
#include "Concurrency.h"
#include "OtherSubjects.h"

using namespace std;
using namespace std::chrono_literals;

static void print_is(const string& name, const Rational& r) {
    std::cout << name << " is : " << r.raw_str() << " = " << r << "\n";
}

static void disp_v(auto& v, const std::string& label)
{
	if (label.empty() == false)
		std::cout << label << ": ";

	if (v.empty())
		std::cout << "[empty]";
	else
		for (auto& s : v) std::cout << s << " ";

	std::cout << "\n";
}

int main()
{
	auto t = std::chrono::system_clock::now();
	std::cout << "system_clock::now is " << t << "\n\n";

	std::cout << "counting primes up to " << make_commas(MAX_PRIME) << "\n";
	auto secs = timed(count_primes2);
	std::cout << "\n";

	std::cout << "time elapsed: " << setprecision(3) << fixed << secs.count() << " sec\n";
	std::cout << "time elapsed: " << setprecision(3) << fixed << chrono::duration<double, milli>(secs).count() << " ms\n";
	std::cout << "time elapsed: " << setprecision(3) << scientific << chrono::duration<double, micro>(secs).count() << " microsecs\n";
	std::cout << "time elapsed: " << floor<chrono::duration<unsigned long, ratio<1, 24>>>(secs).count() << " frames at 24 fps\n";
	std::cout << "\n";

	std::cout << "time elapsed: " << setprecision(3) << fixed << secs << " sec\n";
	std::cout << "time elapsed: " << setprecision(3) << fixed << chrono::duration<double, milli>(secs) << " ms\n";
	std::cout << "time elapsed: " << setprecision(3) << scientific << chrono::duration<double, micro>(secs) << " microsecs\n";
	std::cout << "\n";

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
