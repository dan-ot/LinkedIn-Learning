// AdvancedConcepts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <concepts>
#include <variant>

#include "OperatorOverloads.h"
#include "MoveSemantics.h"
#include "OptionalsVariants.h"

using namespace std;

static void print_is(const string& name, const Rational& r) {
    cout << name << " is : " << r.raw_str() << " = " << r << "\n";
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
	using v_animal = variant<Cat, Dog, Wookiee>;
	vector<v_animal> pets{ Cat("Hobbes"), Dog("Fido"), Cat("Bill"), Wookiee{"Chewie"} };

	cout << "-- get method\n";
	for (const v_animal& a : pets) {
		auto idx = a.index();
		if (idx == 0) get<Cat>(a).speak();
		if (idx == 1) get<Dog>(a).speak();
		if (idx == 2) get<Wookiee>(a).speak();
	}

	cout << "\n";
	cout << "-- get_if method\n";
	for (const v_animal& a : pets) {
		if (const auto& o = get_if<Cat>(&a); o) o->speak();
		else if (const auto& o = get_if<Dog>(&a); o) o->speak();
		else if (const auto& o = get_if<Wookiee>(&a); o) o->speak();
	}

	cout << "\n";
	cout << "-- visit method\n";
	for (const v_animal& a : pets) {
		std::visit(animal_speaks{}, a);
	}

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
