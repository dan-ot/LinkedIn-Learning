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
#include <utility>

#include "OperatorOverloads.h"
#include "MoveSemantics.h"
#include "OptionalsVariants.h"
#include "Concurrency.h"
#include "OtherSubjects.h"
#include "OtherFeatures.h"

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
	int ca1[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	pspan<int>(ca1);

	cout << "done.\n";

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
