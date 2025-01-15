#include <iostream>
#include <sstream>

#include "Factory.h"

using namespace std;

int main()
{
	auto machine = CoffeeMakerFactory();
	Coffee* cup;
	cup = machine.GetCoffee();

	cout << endl << "You had asked for a(n) " << cup->getType() << endl;
	return 0;
}