#pragma once
#include <vector>
#include <string>

namespace M 
{
class Canvas;
class ReplayCanvas;


class CanvasMemento
{
	friend class Canvas;
	friend class ReplayCanvas;
	const std::vector<std::string> shapes;
public:
	CanvasMemento(std::vector<std::string> shapes) : shapes(shapes) {};
};

class CanvasIterator {
public:
	virtual ~CanvasIterator() {};
	virtual CanvasMemento* next() = 0;
	virtual bool isFinished() = 0;
};

class ForwardIterator : public CanvasIterator {
	int currentPosition;
	std::vector<CanvasMemento*>& history;
public:
	ForwardIterator(std::vector<CanvasMemento*>& history) : currentPosition(0), history(history) {};
	CanvasMemento* next() override;
	bool isFinished() override;
};

class History {
public:
	virtual void addState(CanvasMemento* state) = 0;
	virtual CanvasMemento* undo() = 0;
	virtual CanvasIterator* getIterator() = 0;
};

class CanvasHistory : public History {
	std::vector<CanvasMemento*> oldStates;
public:
	~CanvasHistory();
	void addState(CanvasMemento* state) override;
	CanvasMemento* undo() override;
	CanvasIterator* getIterator() override;
};

class NoOpHistory : public History {
public:
	void addState(CanvasMemento* state) override;
	CanvasMemento* undo() override;
	CanvasIterator* getIterator() override;
};

class Canvas
{
	std::vector<std::string> shapes;
	History* history;
public:
	Canvas(History* history) : history(history) {};
	void add_shape(const std::string& new_shape);
	void undo();
	void clear_all();
	std::vector<std::string> get_shapes();
};

class ReplayCanvas {
	std::vector<std::string> shapes;
	CanvasIterator* historyIterator;
public:
	ReplayCanvas(History* history);
	void replay();
};

}
