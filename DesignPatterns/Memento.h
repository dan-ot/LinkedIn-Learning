#pragma once
#include <vector>
#include <string>

namespace M 
{
class Canvas;
class CanvasMemento
{
	friend class Canvas;
	const std::vector<std::string> shapes;
public:
	CanvasMemento(std::vector<std::string> shapes) : shapes(shapes) {};
};

class Canvas
{
	std::vector<std::string> shapes;
	std::vector<CanvasMemento*> oldStates;
public:
	~Canvas() {
		for (auto p : oldStates) {
			delete p;
		}
		oldStates.clear();
	}
	void add_shape(const std::string& new_shape) {
		oldStates.push_back(new CanvasMemento(shapes));
		shapes.push_back(new_shape);
	}
	void undo() {
		auto previousState = oldStates.back();
		oldStates.pop_back();
		shapes = previousState->shapes;
		delete previousState;
	}
	void clear_all() {
		shapes.clear();
	}
	std::vector<std::string> get_shapes() { return shapes; }
};


}
