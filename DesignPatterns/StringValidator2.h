#pragma once
#include <string>
#include <optional>
#include <vector>
#include <sstream>
#include <regex>
#include <unordered_set>

namespace mine {
	class IValidation {
	public:
		virtual std::optional<std::string> validate(std::string input) = 0;
	};

	class Validator
	{
	private:
		std::vector<std::shared_ptr<IValidation>> validations_;
	public:
		std::string validate(std::string input);
		static Validator with(std::shared_ptr<IValidation> first);
		Validator then(std::shared_ptr<IValidation> next);
	};

	class NotEmptyValidator : public IValidation {
	public:
		std::optional<std::string> validate(std::string input) override;
	};

	class LengthValidator : public IValidation {
		int min_length_;
	public:
		LengthValidator(int min_length) : min_length_(min_length) {};
		std::optional<std::string> validate(std::string input) override;
	};

	class RegexValidator : public IValidation {
		std::string pattern_name_;
		std::regex regex_;
		
	public:
		RegexValidator(std::string pattern_name, std::string regex_string) :
			pattern_name_(pattern_name), regex_(regex_string) {
		};
		std::optional<std::string> validate(std::string input) override;
	};

	class HistoryValidator : public IValidation {
		std::unordered_set<std::string> history_;

	public:
		HistoryValidator(std::unordered_set<std::string> history) :
			history_(history) {
		};
		std::optional<std::string> validate(std::string input) override;
	};
}
