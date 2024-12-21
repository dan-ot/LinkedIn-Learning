#pragma once
#include <string>
#include <optional>
#include <vector>
#include <regex>
#include <unordered_set>
#include <memory>

#include "Observer.h"

class IHandling {
public:
	virtual std::optional<std::string> handle(std::string input) = 0;
};

class Handler
{
private:
	std::vector<std::shared_ptr<IHandling>> validations_;
	std::shared_ptr<ChatGroup> group_;
public:
	std::string handle(std::string input);
	static Handler targeting(std::shared_ptr<ChatGroup> group, std::shared_ptr<IHandling> first);
	Handler then(std::shared_ptr<IHandling> next);
};

class NotEmptyValidator : public IHandling {
public:
	std::optional<std::string> handle(std::string input) override;
};

class LengthValidator : public IHandling {
	int min_length_;
public:
	LengthValidator(int min_length) : min_length_(min_length) {};
	std::optional<std::string> handle(std::string input) override;
};

class RegexValidator : public IHandling {
	std::string pattern_name_;
	std::regex regex_;
		
public:
	RegexValidator(std::string pattern_name, std::string regex_string) :
		pattern_name_(pattern_name), regex_(regex_string) {
	};
	std::optional<std::string> handle(std::string input) override;
};

class HistoryValidator : public IHandling {
	std::unordered_set<std::string> history_;

public:
	HistoryValidator(std::unordered_set<std::string> history) :
		history_(history) {
	};
	std::optional<std::string> handle(std::string input) override;
};

