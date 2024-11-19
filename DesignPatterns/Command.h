#pragma once
#include <string>
#include "CommandDomain.h"

class ICommand
{
public:
	virtual ~ICommand() {};
	virtual void execute() = 0;
};

class AddShapeCommand : public ICommand {
	std::string shape_name_;
	Canvas* canvas_;
public:
	AddShapeCommand(const std::string& shape_name, Canvas* canvas)
		: shape_name_(shape_name), canvas_(canvas) {
	};

	void execute();
};

class ClearCommand : public ICommand {
	Canvas* canvas_;
public:
	ClearCommand(Canvas* canvas) : canvas_(canvas) {};
	void execute();
};

class Button {
	ICommand* command_;
public:
	Button(ICommand* command) : command_(command) {};
	void click();
};