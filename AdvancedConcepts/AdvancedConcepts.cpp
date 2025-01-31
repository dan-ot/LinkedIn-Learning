// AdvancedConcepts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "OperatorOverloads.h"

using namespace std;

static void print_is(const string& name, const Rational& r) {
    cout << name << " is : " << r.raw_str() << " = " << r << "\n";
}

int main()
{
    const MultBy times4(4);
    const MultBy times10(10);
    //const MultBy times15(15);

    const auto times15 = [](int x) { return x * 15; };

    cout << "times4(5) is " << times4(5) << "\n";
    cout << "times4(15) is " << times4(15) << "\n";
    cout << "times10(5) is " << times10(5) << "\n";
    cout << "times10(15) is " << times10(15) << "\n";
    cout << "times15(5) is " << times15(5) << "\n";
    cout << "times15(15) is " << times15(15) << "\n";
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
