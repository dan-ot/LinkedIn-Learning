#pragma once

#include <iostream>

class Door {
public:
	Door() {};
	virtual void Open() = 0;
};

class GasCarDoor : public Door {
public:
	GasCarDoor() { std::cout << "Making a door for a gas car." << std::endl; }
	void Open() override { std::cout << "click" << std::endl; }
};

class ElectricCarDoor : public Door {
public:
	ElectricCarDoor() { std::cout << "Making a door for an electric car." << std::endl; }
	void Open() override { std::cout << "shhhhh" << std::endl; }
};

class Engine {
protected:
	char _sound[15];
public:
	Engine() { strcpy_s(_sound, ""); }
	virtual void Run() = 0;
};

class GasEngine : public Engine {
public:
	GasEngine() { 
		strcpy_s(_sound, "vroom");
		std::cout << "Making a gas engine." << std::endl;
	}
	void Run() override {
		std::cout << _sound << std::endl;
	}
};

class ElectricEngine : public Engine {
public:
	ElectricEngine() {
		strcpy_s(_sound, "SHHHH");
		std::cout << "Making an electric engine." << std::endl;
	}
	void Run() override {
		std::cout << _sound << std::endl;
	}
};

class CarFactory {
public:
	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
};

class GasCarFactory : public CarFactory {
public:
	Door* BuildDoor() override { return new GasCarDoor(); }
	Engine* BuildEngine() override { return new GasEngine(); }
};

class ElectricCarFactory : public CarFactory {
public:
	Door* BuildDoor() override { return new ElectricCarDoor(); }
	Engine* BuildEngine() override { return new ElectricEngine(); }
};

class Background {
public:
	virtual void getTheme() = 0;
};

class LightBackground : public Background {
public:
	LightBackground() {
		std::cout << "Making a white background." << std::endl;
	}
	void getTheme() override { std::cout << "This is part of the light theme."; }
};

class DarkBackground : public Background {
public:
	DarkBackground() {
		std::cout << "Making a black background." << std::endl;
	}
	void getTheme() override { std::cout << "This is part of the dark theme."; }
};

class Text {
public:
	virtual void message() = 0;
};

class BlackText : public Text {
public:
	BlackText() { std::cout << "Making the text black." << std::endl; }
	void message() override { std::cout << "This is the default font from the light theme." << std::endl; }
};

class WhiteText : public Text {
public:
	WhiteText() { std::cout << "Making the text white." << std::endl; }
	void message() override { std::cout << "This is the default font for the dark theme." << std::endl; }
};

class DarkGreenText : public Text {
public:
	DarkGreenText() { std::cout << "Making the text dark green." << std::endl; }
	void message() override { std::cout << "This is the font for an alternate light theme." << std::endl; }
};

class LightGreenText : public Text {
public:
	LightGreenText() { std::cout << "Making the text light green." << std::endl; }
	void message() override { std::cout << "This is the font for an alternate dark theme." << std::endl; }
};

class ThemeFactory {
public:
	virtual Background* setBackground() = 0;
	virtual Text* getDefaultText() = 0;
	virtual Text* getGreenText() = 0;
};

class LightFactory : public ThemeFactory {
public:
	Background* setBackground() override { return new LightBackground(); }
	Text* getDefaultText() override { return new BlackText(); }
	Text* getGreenText() override { return new DarkGreenText(); }
};

class DarkFactory : public ThemeFactory {
public:
	Background* setBackground() override { return new DarkBackground(); }
	Text* getDefaultText() override { return new WhiteText(); }
	Text* getGreenText() override { return new LightGreenText(); }
};
