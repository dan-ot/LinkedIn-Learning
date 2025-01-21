#include <iostream>
#include <sstream>

#include "Factory.h"
#include "AbstractFactory.h"

using namespace std;

int main()
{
	ThemeFactory* factory;
	int choice;

	cout << "Select a theme: " << endl;
	cout << "1: Dark" << endl;
	cout << "2: Light" << endl;
	cout << "Selection > ";
	cin >> choice;
	cout << endl;

	switch (choice) {
	case 1:
		factory = new DarkFactory();
		break;
	case 2:
		factory = new LightFactory();
		break;
	default:
		cout << "That's not a legit choice.";
		return 1;
	}

	auto background = factory->setBackground();
	auto text = factory->getDefaultText();
	auto green = factory->getGreenText();
	
	text->message();
	green->message();

	cout << "Goodbye." << endl;

	return 0;
}