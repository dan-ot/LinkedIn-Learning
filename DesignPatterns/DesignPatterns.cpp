#include <iostream>
#include <sstream>
#include <vector>

#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Prototype.h"

using namespace std;

int main()
{
	auto sheep0 = new Sheep();
	sheep0->setHairColor("white");
	sheep0->setTail(5);
	sheep0->setWeight(90);
	sheep0->setHeight(1);
	sheep0->setAge(5);

	auto cow0 = new Cow();
	cow0->setHairColor("brown");
	cow0->setTail(20);
	cow0->setWeight(790);
	cow0->setHeight(2);
	cow0->setAge(8);

	auto farm = vector<Animal*>(3);
	farm[0] = sheep0->clone();
	farm[1] = cow0->clone();

	farm[1]->setWeight(1000);

	sheep0->shear();
	farm[2] = sheep0->clone();

	return 0;
}