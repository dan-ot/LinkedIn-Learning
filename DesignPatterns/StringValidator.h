#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <unordered_set>

class IStringValidator
{
public:
	virtual ~IStringValidator() {};
	virtual IStringValidator* set_next(IStringValidator* next_validator) = 0;
	virtual std::string validate(std::string) = 0;
};

class BaseValidator : public IStringValidator {
protected:
	IStringValidator* next_ = nullptr;
public:
	virtual ~BaseValidator() { delete next_; };
	IStringValidator* set_next(IStringValidator* next_validator) override {
		next_ = next_validator;
		return next_validator;
	}
	virtual std::string validate(std::string test_string) override {
		if (this->next_) {
			return this->next_->validate(test_string);
		}

		return "Success!";
	}
};

class NotEmptyValidator : public BaseValidator {
public:
	NotEmptyValidator() {};
	std::string validate(std::string test_string);
};

class LengthValidator : public BaseValidator {
	int min_length_;
public:
	LengthValidator(int min_length) : min_length_(min_length) {};
	std::string validate(std::string test_string);
};


class RegexValidator : public BaseValidator {
	std::string pattern_name_;
	std::string regex_string_;
public:
	RegexValidator(std::string pattern_name, std::string regex_string) :
		pattern_name_(pattern_name), regex_string_(regex_string) {
	};
	std::string validate(std::string test_string);
};

class HistoryValidator : public BaseValidator {
	std::unordered_set<std::string> history_items_;
public:
	HistoryValidator(std::unordered_set<std::string> history_items) :
		history_items_(history_items) {
	};

	std::string validate(std::string test_string) override;
};