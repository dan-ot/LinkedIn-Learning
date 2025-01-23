#include <iostream>
#include <sstream>
#include <vector>

#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Prototype.h"
#include "Singleton.h"

using namespace std;

int main()
{
	auto elected = Leader::getInstance();
	elected->giveSpeech();

	return 0;
}