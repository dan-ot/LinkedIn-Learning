#pragma once
#include <string>

class State {
protected:
	State* nextState = nullptr;
public:
	State(State* nextState) : nextState(nextState) {};
	virtual std::string getDescription() = 0;
	State* getNextState();
};

class PurchasedState : public State {
public:
	PurchasedState(State* nextState) : State(nextState) {};
	std::string getDescription() override;
};

class InTransitState : public State {
public:
	InTransitState(State* nextState) : State(nextState) {};
	std::string getDescription() override;
};

class DeliveredState : public State {
public:
	DeliveredState(State* nextState) : State(nextState) {};
	std::string getDescription() override;
};

class Purchase
{
	std::string productName;
	State* currentState;

public:
	Purchase(const std::string& productName, State* initialState)
		: productName(productName), currentState(initialState) {
	};

	std::string getDescription();
	void goToNextState();
};

