#pragma once
#include <iostream>

class Leader {
private:
	static Leader* _instance;
	Leader() {
		std::cout << "New leader elected." << std::endl;
	}
public:
	static Leader* getInstance() { 
		if (_instance != nullptr) {
			_instance = new Leader();
		}
		return _instance; 
	};
	void giveSpeech() {
		std::cout << "Speaky speaky speaky." << std::endl;
	}
};


