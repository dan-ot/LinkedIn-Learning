#pragma once
#include <string>
#include <memory>

class State {
protected:
	std::shared_ptr<State> nextState = nullptr;
public:
	State(std::shared_ptr<State> nextState) : nextState(nextState) {};
	virtual std::string getDescription() = 0;
	std::shared_ptr<State> getNextState();
};

class PurchasedState : public State {
public:
	PurchasedState(std::shared_ptr<State> nextState) : State(nextState) {};
	std::string getDescription() override;
};

class InTransitState : public State {
public:
	InTransitState(std::shared_ptr<State> nextState) : State(nextState) {};
	std::string getDescription() override;
};

class DeliveredState : public State {
public:
	DeliveredState(std::shared_ptr<State> nextState) : State(nextState) {};
	std::string getDescription() override;
};

class Purchase
{
	std::string productName;
	std::shared_ptr<State> currentState;

public:
	Purchase(const std::string& productName, std::shared_ptr<State> initialState)
		: productName(productName), currentState(initialState) {
	};

	std::string getDescription();
	void goToNextState();
};

