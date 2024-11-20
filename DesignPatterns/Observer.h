#pragma once
#include <memory>
#include <string>
#include <vector>

class ISubscriber {
public:
	virtual void notify(const std::string& publisher_name, const std::string& message) = 0;
	virtual std::string name() = 0;
};

class IPublisher {
public:
	virtual void subscribe(std::shared_ptr<ISubscriber> subscriber) = 0;
	virtual void unsubscribe(std::shared_ptr<ISubscriber> subscriber) = 0;
	virtual void publish(const std::string& message) = 0;
};

class ChatGroup : public IPublisher {
	std::string group_name_;
	std::vector<std::shared_ptr<ISubscriber>> subscribers_;
public:
	ChatGroup(const std::string& name)
		: group_name_(name) {
	};
	void subscribe(std::shared_ptr<ISubscriber>) override;
	void unsubscribe(std::shared_ptr<ISubscriber>) override;
	void publish(const std::string&);
};

class ChatUser : public ISubscriber {
	std::string username_;
public:
	ChatUser(const std::string& name)
		: username_(name) {
	};
	void notify(const std::string& publisher, const std::string& message) override;
	std::string name() override;
};