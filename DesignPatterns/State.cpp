#include "State.h"
#include <iostream>

using namespace std;

string PurchasedState::getDescription()
{
    return "Current State: PURCHASED - Will be shipping soon.\n";
}

State* State::getNextState()
{
    return nextState;
}

std::string InTransitState::getDescription()
{
    return "Current State: IN TRANSIT - Your item is on the way.\n";
}

std::string DeliveredState::getDescription()
{
    return "Current State: DELIVERED - Your item has arrived.\n";
}

std::string Purchase::getDescription()
{
    return currentState->getDescription();
}

void Purchase::goToNextState()
{
    if (currentState->getNextState() == nullptr) {
        cout << "No more states!\n";
    }
    else {
        currentState = currentState->getNextState();
    }
}
