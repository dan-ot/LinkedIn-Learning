#include <iostream>
#include <sstream>

#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"

using namespace std;

int main()
{
	MealBuilder* cook;
	MealCombo* meal;
	int choice;

	cout << "Select a meal: " << endl;
	cout << "1: Hamburger meal" << endl;
	cout << "2: Hotdog meal" << endl;
	cout << "Selection > ";
	cin >> choice;
	cout << endl;

	switch (choice) {
	case 1:
		cook = new BurgerMeal();
		break;
	case 2:
		cook = new HotDogMeal();
		break;
	default:
		cout << "What stupid choice." << endl;
		return 1;
	}

	cout << "Making selected meeal." << endl;

	cook->cookEntree();
	cook->cookSide();
	cook->fillDrink();

	meal = cook->getMeal();

	meal->report();

	return 0;
}