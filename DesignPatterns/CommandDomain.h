#pragma once
#include <iostream>
#include <vector>

class Canvas
{
	std::vector<std::string> shapes;
public:
	void add_shape(const std::string& new_shape) {
		shapes.push_back(new_shape);
	}
	void clear_all() {
		shapes.clear();
	}
	std::vector<std::string> get_shapes() { return shapes; }
};
