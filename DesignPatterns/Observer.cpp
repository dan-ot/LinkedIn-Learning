#include "Observer.h"
#include <algorithm>
#include <iostream>

using namespace std;

void ChatGroup::subscribe(std::shared_ptr<ISubscriber> subscriber)
{
	subscribers_.push_back(subscriber);
}

void ChatGroup::unsubscribe(std::shared_ptr<ISubscriber> subscriber)
{
	subscribers_.erase(remove_if(subscribers_.begin(), subscribers_.end(), [subscriber](shared_ptr<ISubscriber> s) { return s->name() == subscriber->name(); }), subscribers_.end());
}

void ChatGroup::publish(const std::string& message)
{
	for (auto &subscriber : subscribers_) {
		subscriber->notify(group_name_, message);
	}
}

void ChatUser::notify(const std::string& publisher, const std::string& message)
{
	cout << username_ << " received a new message from " << publisher << ": " << message << "\n";
}

std::string ChatUser::name()
{
	return username_;
}
