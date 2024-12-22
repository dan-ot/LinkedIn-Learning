#include <iostream>
#include <sstream>
#include "StringValidator2.h"
#include "CommandDomain.h"
#include "Command.h"
#include "Mediator.h"
#include "Observer.h"
#include "State.h"

using namespace std;

static string vector_to_string(vector<string> v) {
    stringstream ss;
    for (auto& s : v) {
        ss << s << ", ";
    }
    return ss.str();
}

int main()
{
    auto deliveredState = new DeliveredState(nullptr);
    auto inTransitState = new InTransitState(deliveredState);
    auto purchasedState = new PurchasedState(inTransitState);

    auto purchase = Purchase("Shoes", purchasedState);

    cout << purchase.getDescription();
    purchase.goToNextState();

    cout << purchase.getDescription();
    purchase.goToNextState();

    cout << purchase.getDescription();
    purchase.goToNextState();

    delete deliveredState;
    delete inTransitState;
    delete purchasedState;

    return 0;
}