#pragma once
#include <iostream>
#include <string>

class Entree {
public:
	virtual void reportEntree() = 0;
};

class HotDog : public Entree {
public:
	void reportEntree() override { std::cout << "Entree is a hot dog." << std::endl; }
};

class Burger : public Entree {
public:
	void reportEntree() override { std::cout << "Entree is a hamburger." << std::endl; }
};

class Side {
public:
	virtual void reportSide() = 0;
};

class Fries : public Side {
public:
	void reportSide() override { std::cout << "Side is a bag of fries." << std::endl; }
};

class Salad : public Side {
public:
	void reportSide() override { std::cout << "Side is a salad." << std::endl; }
};

class Drink {
public:
	virtual void reportDrink() = 0;
};

class Soda : public Drink {
public:
	virtual void reportDrink() override { std::cout << "Drink is a soda." << std::endl; }
};

class Water : public Drink {
public:
	virtual void reportDrink() override { std::cout << "Drink is a water." << std::endl; }
};

class MealCombo {
protected:
	Entree* entree;
	Side* side;
	Drink* drink;
	std::string name;
public:
	MealCombo(const std::string& name) : name(name) {};
	void setEntree(Entree* entree) { this->entree = entree; }
	void setSide(Side* side) { this->side = side; }
	void setDrink(Drink* drink) { this->drink = drink; }
	void report() {
		std::cout << name << std::endl;
		entree->reportEntree();
		side->reportSide();
		drink->reportDrink();
	}
};

class MealBuilder
{
protected:
	MealCombo* meal;
public:
	virtual void cookEntree() = 0;
	virtual void cookSide() = 0;
	virtual void fillDrink() = 0;
	virtual MealCombo* getMeal() {
		return meal;
	}
};

class BurgerMeal : public MealBuilder {
public:
	BurgerMeal() { meal = new MealCombo("Burger"); }
	void cookEntree() override { meal->setEntree(new Burger()); }
	void cookSide() override { meal->setSide(new Fries()); }
	void fillDrink() override { meal->setDrink(new Water()); }
};

class HotDogMeal : public MealBuilder {
public:
	HotDogMeal() { meal = new MealCombo("Hot Dog"); }
	void cookEntree() override { meal->setEntree(new HotDog()); }
	void cookSide() override { meal->setSide(new Salad()); }
	void fillDrink() override { meal->setDrink(new Soda()); }
};
