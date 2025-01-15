#pragma once
#include <iostream>
#include <string.h>

class Coffee {
protected: 
	char _type[15];
public:
	Coffee() : _type("Coffee") {}
	char* getType() { return _type; }
};

class Espresso : public Coffee {
public:
	Espresso() : Coffee() {
		strcpy_s(_type, "Espresso");
		std::cout << std::endl << "Making a cup of espresso" << std::endl;
		std::cout << "Grind and brew one scoop of espresso beans." << std::endl;
	}
};

class Cappuccino : public Coffee {
public:
	Cappuccino() : Coffee() {
		strcpy_s(_type, "Cappuccino");
		std::cout << std::endl << "Making a cup of cappuccino" << std::endl;
		std::cout << "Grind and brew one scoop of espresso beans." << std::endl;
		std::cout << "Heat and foam milk." << std::endl;
	}
};

class CoffeeMakerFactory {
private:
	Coffee* _coffee;
public:
	Coffee* GetCoffee() {
		int choice;

		std::cout << "Select type of coffee to make: " << std::endl;
		std::cout << "1: Espresso" << std::endl;
		std::cout << "2: Cappuccino" << std::endl;
		std::cout << "Selection > " << std::endl;

		std::cin >> choice;

		switch (choice) {
		case 1:
			return new Espresso();
			break;
		case 2:
			return new Cappuccino();
			break;
		default:
			std::cout << choice << " is not a valid selection.";
			return nullptr;
			break;
		}
	}
};