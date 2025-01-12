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
	auto history = new M::NoOpHistory();
	auto canvas = new M::Canvas(history);

	canvas->add_shape("rhombus");
	canvas->add_shape("triangle");
	canvas->add_shape("square");
	canvas->add_shape("circle");

	cout << "Watching replay: \n";

	auto replayCanvas = new M::ReplayCanvas(history);
	replayCanvas->replay();

	return 0;
}