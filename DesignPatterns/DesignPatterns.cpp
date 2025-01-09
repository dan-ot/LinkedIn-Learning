#include <iostream>
#include <sstream>
#include "StringValidator2.h"
#include "CommandDomain.h"
#include "Command.h"
#include "Mediator.h"
#include "Observer.h"
#include "State.h"
#include "Strategy.h"
#include "TemplateMethod.h"
#include "Visitor.h"
#include "Iterator.h"

using namespace std;

static string vector_to_string(vector<string> v) {
	stringstream ss;
	for (auto& s : v) {
		ss << s << ", ";
	}
	return ss.str();
}

int main()
{
	auto numbers = vector{ 1,2,3,4,5,6,7 };
	auto nc = NumberCollection(numbers);

	NumberIterator* fi = nc.getForwardIterator();
	NumberIterator* bi = nc.getBackwardIterator();

	while (fi->isFinished() == false) {
		cout << fi->next() << ", ";
	}
	cout << "\n";

	cout << "Backwards: ";

	while (bi->isFinished() == false) {
		cout << bi->next() << ", ";
	}
	cout << "\n";

	delete fi;
	delete bi;
	return 0;
}