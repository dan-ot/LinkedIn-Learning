#include "Command.h"

void AddShapeCommand::execute()
{
	canvas_->add_shape(shape_name_);
}

void ClearCommand::execute()
{
	canvas_->clear_all();
}

void Button::click()
{
	command_->execute();
}
