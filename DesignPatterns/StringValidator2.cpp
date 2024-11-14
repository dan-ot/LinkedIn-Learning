#include "StringValidator2.h"
#include <iostream>

using namespace std;

namespace mine {
    string Validator::validate(string input)
    {
        stringstream rb;
        for (auto &validator : validations_) {
            auto possible_error = validator->validate(input);

            if (possible_error.has_value()) {
                rb << possible_error.value();
            }
        }

        auto response = rb.str();

        if (response.empty()) {
            return "Success!";
        }
        else {
            return response;
        }
    }

    Validator Validator::with(std::shared_ptr<IValidation> first)
    {
        auto vc = Validator();
        vc.validations_.push_back(first);
        return vc;
    }
    Validator Validator::then(std::shared_ptr<IValidation> next)
    {
        validations_.push_back(next);
        return *this;
    }

    optional<string> NotEmptyValidator::validate(string input) {
        cout << "Validating emptiness... ";
        if (input.empty()) {
            return optional("String was empty.");
        }
        else {
            return optional<string>();
        }
    }

    optional<string> LengthValidator::validate(string input) {
        cout << "Validating length... ";
        if (input.length() < min_length_) {
            return optional("String isn't long enough.");
        }
        else {
            return optional<string>();
        }
    }

    optional<string> RegexValidator::validate(string input) {
        cout << "Validating pattern... ";
        if (regex_match(input, regex_)) {
            return optional<string>();
        }
        else {
            return optional("String didn't match " + pattern_name_);
        }
    }

    optional<string> HistoryValidator::validate(string input) {
        cout << "Validating history... ";
        if (history_.count(input) > 0) {
            return optional("String has been used before.");
        }
        else {
            history_.emplace(input);
            return optional<string>();
        }
    }
}
