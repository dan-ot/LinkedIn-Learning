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
#include "Memento.h"
#include "NullObject.h"

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
	SomeTask task1(new ConsoleLogger());
	SomeTask task2(new FileLogger("log.txt"));
	SomeTask task3(new ApiLogger("https://log.com"));
	SomeTask task4;

	task1.execute();
	task2.execute();
	task3.execute();
	task4.execute();

	return 0;
}