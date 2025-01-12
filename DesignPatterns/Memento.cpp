#include "Memento.h"
#include <iostream>

namespace M {

void Canvas::add_shape(const std::string& new_shape)
{
	shapes.push_back(new_shape);
	history->addState(new CanvasMemento(shapes));
}

void Canvas::undo() {
	auto previousState = history->undo();
	shapes = previousState->shapes;
}

void Canvas::clear_all()
{
	shapes.clear();
	history->addState(new CanvasMemento(shapes));
}

std::vector<std::string> Canvas::get_shapes() {
	return shapes;
}

CanvasMemento* ForwardIterator::next()
{
	auto current = history.at(currentPosition);
	currentPosition += 1;
	return current;
}

bool ForwardIterator::isFinished()
{
	return currentPosition >= history.size();
}

CanvasHistory::~CanvasHistory()
{
	for (auto p : oldStates) {
		delete p;
	}
	oldStates.clear();
}

void CanvasHistory::addState(CanvasMemento* state)
{
	oldStates.push_back(state);
}

CanvasMemento* CanvasHistory::undo()
{
	auto previousState = oldStates.back();
	oldStates.pop_back();
	return previousState;
}

CanvasIterator* CanvasHistory::getIterator()
{
	return new ForwardIterator(oldStates);
}

ReplayCanvas::ReplayCanvas(History* history)
{
	historyIterator = history->getIterator();
}

void ReplayCanvas::replay()
{
	while (!historyIterator->isFinished()) {
		auto nextState = historyIterator->next();
		shapes = nextState->shapes;
		std::cout << "The shapes are now: ";
		for (auto shape : shapes) {
			std::cout << shape << ", ";
		}
		std::cout << "\n";
	}
}

void NoOpHistory::addState(CanvasMemento* state)
{
}

CanvasMemento* NoOpHistory::undo()
{
	return new CanvasMemento(std::vector<std::string>());
}

CanvasIterator* NoOpHistory::getIterator()
{
	auto empty = std::vector<CanvasMemento*>();
	return new ForwardIterator(empty);
}

}
