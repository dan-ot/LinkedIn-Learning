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
	auto canvas = M::Canvas();
	
	canvas.add_shape("rhombus");
	canvas.add_shape("triangle");
	canvas.add_shape("square");
	canvas.add_shape("circle");
	
	for (auto shape : canvas.get_shapes()) {
		cout << shape << ", ";
	}

	cout << "\n";

	canvas.add_shape("rhombus");
	canvas.add_shape("triangle");
	canvas.add_shape("square");
	canvas.add_shape("circle");
	canvas.undo();

	for (auto shape : canvas.get_shapes()) {
		cout << shape << ", ";
	}

	cout << "\n";
	

	return 0;
}